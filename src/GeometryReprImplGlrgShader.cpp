/*
 * GeometryReprImplGlrgShader.cpp
 *
 *  Created on: Oct 18, 2011
 *      Author: jord
 */

#include "GeometryReprImplGlrgShader.h"

namespace glrg {

GeometryReprImplGlrgShader::GeometryReprImplGlrgShader(ShaderInfo *shader)
: GeometryRepr() {
	this->shader = shader;
}

GLint GeometryReprImplGlrgShader::getUnitSize(GLuint attrib_id)
{
	return this->shader->getUnitSize(attrib_id);
}

GLint GeometryReprImplGlrgShader::getType(GLuint attrib_id)
{
	return this->shader->getType(attrib_id);
}

GeometryReprImplGlrgShader::~GeometryReprImplGlrgShader() {
	delete this->vertexData;
	glDeleteVertexArrays(1, &vertexArrayObject);
}
	
} /* namespace glrg */
