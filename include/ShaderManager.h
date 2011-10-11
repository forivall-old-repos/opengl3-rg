/*
 * ShaderManager.h
 *
 *  Created on: 2011-10-08
 *      Author: Jordan
 */

#ifndef SHADERMANAGER_H_
#define SHADERMANAGER_H_

#include "Angel.h"
#include <map>

namespace glrg {

struct ShaderData {
    const char*  filename;
    GLenum       type;
    GLchar*      source;
};

struct ShaderAttribInfo {
    GLint attrib_position;
    GLint unit_size;
    GLenum type;
    // todo: make constructor
};

char* ReadShaderSource(const char* shaderFile);


GLuint InitShader( ShaderData *shaders );

//  Helper function to load vertex and fragment shader files
GLuint InitShader( const char* vertexShaderFile,
           const char* fragmentShaderFile );

// before calling this function, bind the shader's attrib locations
// glBindAttribLocation(program, VPOSITION_LOC, "vPosition");
// glBindAttribLocation(program, VCOLOR_LOC, "vColor");
GLuint LinkShader(GLuint program);

class ShaderManager {
    std::map<GLuint, std::map<GLchar*, ShaderAttribInfo> > info;
public:
    static ShaderManager *getSingleton();
    
    void addProgramInfo(GLuint, 
            GLchar *, 
            GLint,
            GLenum);
    
    GLint getUnitSize(GLuint, GLchar*);
    GLint getType(GLuint, GLchar*);
    
};

}

#endif /* SHADERMANAGER_H_ */
