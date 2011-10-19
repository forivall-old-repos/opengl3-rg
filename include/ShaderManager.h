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
    ShaderAttribInfo() : attrib_position(), unit_size(), type() {}
    ShaderAttribInfo(GLint attrib_position, GLint unit_size, GLenum type) :
    	attrib_position(attrib_position), unit_size(unit_size), type(type) {}
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
private:
    std::map<GLuint, std::map<GLuint, ShaderAttribInfo> > info;
	static ShaderManager *singleton;
public:
    ShaderManager();
    
    static ShaderManager *getSingleton();
    
    void addProgramInfo(GLuint, 
            GLuint, 
            GLint,
            GLenum);
    
    GLint getUnitSize(GLuint, GLuint);
    GLint getType(GLuint, GLuint);
    
};

}
#endif /* SHADERMANAGER_H_ */
