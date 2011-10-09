/*
 * ShaderManager.cpp
 *
 *  Created on: 2011-10-08
 *      Author: Jordan
 */

#include "ShaderManager.h"

// Create a NULL-terminated string by reading the provided file
char* glrg::ReadShaderSource(const char* shaderFile)
{
    FILE* fp = fopen(shaderFile, "r");

    if ( fp == NULL ) { return NULL; }

    fseek(fp, 0L, SEEK_END);
    long size = ftell(fp);

    fseek(fp, 0L, SEEK_SET);
    char* buf = new char[size + 1];
    fread(buf, 1, size, fp);

    buf[size] = '\0';
    fclose(fp);

    return buf;
}

// Create a GLSL program object from vertex and fragment shader files
GLuint glrg::InitShader(const char* vShaderFile, const char* fShaderFile)
{
    ShaderData  shaders[2] = {
            { vShaderFile, GL_VERTEX_SHADER, NULL },
            { fShaderFile, GL_FRAGMENT_SHADER, NULL }
    };
    return glrg::InitShader(shaders);
}

GLuint glrg::InitShader(ShaderData *shaders) {

    GLuint program = glCreateProgram();

    for ( int i = 0; i < 2; ++i ) {
        ShaderData& s = shaders[i];
        s.source = ReadShaderSource( s.filename );
        if ( shaders[i].source == NULL ) {
            std::cerr << "Failed to read " << s.filename << std::endl;
            exit( EXIT_FAILURE );
        }

        GLuint shader = glCreateShader( s.type );
        glShaderSource( shader, 1, (const GLchar**) &s.source, NULL );
        glCompileShader( shader );

        GLint  compiled;
        glGetShaderiv( shader, GL_COMPILE_STATUS, &compiled );
        if ( !compiled ) {
            std::cerr << s.filename << " failed to compile:" << std::endl;
            GLint  logSize;
            glGetShaderiv( shader, GL_INFO_LOG_LENGTH, &logSize );
            char* logMsg = new char[logSize];
            glGetShaderInfoLog( shader, logSize, NULL, logMsg );
            std::cerr << logMsg << std::endl;
            delete [] logMsg;

            exit( EXIT_FAILURE );
        }

        delete [] s.source;

        glAttachShader( program, shader );
    }
    
    return program;
}

GLuint glrg::LinkShader(GLuint program) {
    /* link  and error check */
    glLinkProgram(program);

    GLint  linked;
    glGetProgramiv( program, GL_LINK_STATUS, &linked );
    if ( !linked ) {
        std::cerr << "Shader program failed to link" << std::endl;
        GLint  logSize;
        glGetProgramiv( program, GL_INFO_LOG_LENGTH, &logSize);
        char* logMsg = new char[logSize];
        glGetProgramInfoLog( program, logSize, NULL, logMsg );
        std::cerr << logMsg << std::endl;
        delete [] logMsg;

        exit( EXIT_FAILURE );
    }

    /* use program object */
    glUseProgram(program);

    return program;
}

void glrg::ShaderManager::addProgramInfo(
        GLuint program, 
        GLchar *attrib_name, 
        GLint unit_size,
        GLenum type) {
    
    //info[program][attrib_name] = ShaderAttribInfo(
//    glGetAttribLocation(program, attrib_name), unit_size, type);
}

GLint glrg::ShaderManager::getUnitSize(GLuint program, GLchar *attrib_name) {
    return this->info[program][attrib_name].unit_size;
}
GLint glrg::ShaderManager::getType(GLuint program, GLchar *attrib_name) {
    return this->info[program][attrib_name].type;
}
