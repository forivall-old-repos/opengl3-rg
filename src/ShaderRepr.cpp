/*
 * ShaderRepr.cpp
 *
 *  Created on: Oct 18, 2011
 *      Author: jord
 */

#include "ShaderRepr.h"

using namespace glrg;

glrg::ShaderRepr::ShaderRepr(ShaderManager *manager) {
	if(manager == NULL) {
		manager = ShaderManager::getSingleton();
	}
	this->manager = manager;
	this->uniformData = new std::map<std::string, GLRGhandle *>();
}

glrg::ShaderRepr::~ShaderRepr() {
	delete this->uniformData;
}

GLint glrg::ShaderRepr::getUnitSize(GLuint attrib_id)
{
	return manager->getUnitSize(shader, attrib_id);
}

void glrg::ShaderRepr::setShaderProgram(GLuint program)
{
	this->shader = program;
}

void glrg::ShaderRepr::setUniformData(UNIFORM_TYPE type, 
		const GLfloat *data, GLchar *uniform_name)
{
	GLint location = glGetUniformLocation(this->shader, uniform_name);
	this->setUniformData(type, data, location);
}
void glrg::ShaderRepr::setUniformData(UNIFORM_TYPE type, 
		const GLfloat *data, GLuint location)
{
	switch (type) {
	case UNIFORM_1FV: 	  glUniform1fv(location, 1, data); break;
	case UNIFORM_2FV:	  glUniform2fv(location, 2, data); break;
	case UNIFORM_3FV:	  glUniform3fv(location, 3, data); break;
	case UNIFORM_MAT_2FV: glUniformMatrix2fv(location, 1, GL_FALSE, data); break;
	case UNIFORM_MAT_3FV: glUniformMatrix3fv(location, 1, GL_FALSE, data); break;
	case UNIFORM_MAT_4FV: glUniformMatrix4fv(location, 1, GL_FALSE, data); break;
	default: throw "invalid argument";
		
	}
}

void glrg::ShaderRepr::setUniformData(UNIFORM_TYPE type, 
		const GLint *data, GLuint location)
{
	switch (type) {
	case UNIFORM_1IV:	  glUniform1iv(location, 1, data); break;
	case UNIFORM_2IV:	  glUniform2iv(location, 2, data); break;
	case UNIFORM_3IV:	  glUniform3iv(location, 3, data); break;
	default: throw "invalid argument";
	}
}




GLint glrg::ShaderRepr::getType(GLuint attrib_id)
{
	return manager->getType(shader, attrib_id);
}



