/*
 * ShaderRepr.h
 *
 *  Created on: Oct 18, 2011
 *      Author: jord
 */

#ifndef SHADERREPR_H_
#define SHADERREPR_H_

class ShaderRepr {
public:
	ShaderRepr();
	virtual ~ShaderRepr();
	void setUniformData(const GLfloat* data, GLsizei size, GLchar *uniform_name);
};

#endif /* SHADERREPR_H_ */
