/*
 * ShaderRepr.h
 *
 *  Created on: Oct 18, 2011
 *      Author: jord
 */

#ifndef SHADERREPR_H_
#define SHADERREPR_H_

#include "Guard.h"
#include "ShaderManager.h"
#include "ShaderInfo.h"

namespace glrg {
//	UNIFORM_1F = 0,
//	UNIFORM_2F,
//	UNIFORM_3F,
//	UNIFORM_1I,
//	UNIFORM_2I,
//	UNIFORM_3I,
enum UNIFORM_TYPE {
	UNIFORM_1FV = 0,
	UNIFORM_2FV,
	UNIFORM_3FV,
	UNIFORM_1IV,
	UNIFORM_2IV,
	UNIFORM_3IV,
	UNIFORM_MAT_2FV,
	UNIFORM_MAT_3FV,
	UNIFORM_MAT_4FV,
	UNIFORM_LAST
};

class ShaderRepr: public ShaderInfo {
public:
	ShaderRepr(ShaderManager *);
	virtual ~ShaderRepr();
	void setUniformData(UNIFORM_TYPE, const GLfloat* data, GLchar *uniform_name);
	void setUniformData(UNIFORM_TYPE, const GLfloat* data, GLuint location);
	void setUniformData(UNIFORM_TYPE, const GLint* data, GLuint location);
	
	std::map<std::string, GLRGhandle *> *uniformData;
};

}

#endif /* SHADERREPR_H_ */
