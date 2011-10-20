/*
 * ShaderRepr.cpp
 *
 *  Created on: Oct 18, 2011
 *      Author: jord
 */

#include "ShaderRepr.h"

using namespace glrg;

glrg::ShaderRepr::ShaderRepr(ShaderManager *manager) :
	ShaderInfo(manager) {
//	this->uniformData = new std::map<std::string, GLRGhandle *>();
	this->uniformCache = new std::map<GLuint, uniformCache_t *> ();
}

glrg::ShaderRepr::~ShaderRepr() {
//	delete this->uniformData;
	delete this->uniformCache;
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
	uniformCache_t *current = this->uniformCache->operator [](location);
	GLsizei size = UNIFORM_SIZE[type]*sizeof(GLfloat);
	if(current == NULL) {
		current = new uniformCache_t;
		current->type = type;
		current->data.resize(size);
		this->uniformCache->operator [](location) = current;
	}
	std::copy(data, data + size, current->data.begin() );
	// verify copying (for debugging segfault)
//	std::cout << data[0] << " " << data[1] << " " << data [2] << " " << data[3] << std::endl;
//	std::cout << current->data[0] << " " << current->data[1] << " " << 
//			current->data [2] << " " << current->data[3] << std::endl;
//	std::cout << "done" << std::endl;
}

void setGlUniform(UNIFORM_TYPE type, 
		const GLfloat *data, GLuint location) {
	switch (type) {
	case UNIFORM_1FV: 	  glUniform1fv(location, 1, data); break;
	case UNIFORM_2FV:	  glUniform2fv(location, 1, data); break;
	case UNIFORM_3FV:	  glUniform3fv(location, 1, data); break;
	case UNIFORM_4FV:	  glUniform4fv(location, 1, data); break;
	case UNIFORM_MAT_2FV: glUniformMatrix2fv(location, 1, GL_FALSE, data); break;
	case UNIFORM_MAT_3FV: glUniformMatrix3fv(location, 1, GL_FALSE, data); break;
	case UNIFORM_MAT_4FV: glUniformMatrix4fv(location, 1, GL_FALSE, data); break;
	default: throw "invalid argument";
		
	}
}

void glrg::ShaderRepr::Draw()
{
	glUseProgram(this->shader);
	
	std::map<GLuint, uniformCache_t *>::iterator it;
	for(it = this->uniformCache->begin();
			it != this->uniformCache->end();
			it++) {
		uniformCache_t* test = it->second;
//		std::cout << test << std::endl;
		setGlUniform(it->second->type, &(it->second->data[0]), it->first);
	}
}



//void glrg::ShaderRepr::setUniformData(UNIFORM_TYPE type, 
//		const GLint *data, GLuint location)
//{
//	switch (type) {
//	case UNIFORM_1IV:	  glUniform1iv(location, 1, data); break;
//	case UNIFORM_2IV:	  glUniform2iv(location, 2, data); break;
//	case UNIFORM_3IV:	  glUniform3iv(location, 3, data); break;
//	default: throw "invalid argument";
//	}
//}



