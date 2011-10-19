/*
 * ShaderInfo.h
 *
 *  Created on: Oct 19, 2011
 *      Author: jord
 */

#ifndef SHADERINFO_H_
#define SHADERINFO_H_

#include "Angel.h"
#include "Guard.h"
#include "ShaderManager.h"

namespace glrg {

class ShaderInfo {
protected:
    ShaderManager *manager;
public:
	ShaderInfo(ShaderManager *manager);
	virtual ~ShaderInfo();
	
	void setShaderProgram(GLuint);
	GLint getUnitSize(GLuint);
	GLint getType(GLuint);
	
//	GLuint getAttribLocation()
	
	GLuint shader;
};

} /* namespace glrg */
#endif /* SHADERINFO_H_ */
