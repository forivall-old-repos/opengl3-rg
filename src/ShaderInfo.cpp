/*
 * ShaderInfo.cpp
 *
 *  Created on: Oct 19, 2011
 *      Author: jord
 */

#include "ShaderInfo.h"

namespace glrg {

ShaderInfo::ShaderInfo(ShaderManager *manager) {
	
	if(manager == NULL) {
		manager = ShaderManager::getSingleton();
	}
	this->manager = manager;
}

ShaderInfo::~ShaderInfo() {
	// TODO Auto-generated destructor stub
}

} /* namespace glrg */

void glrg::ShaderInfo::setShaderProgram(GLuint program)
{
	this->shader = program;
}

GLint glrg::ShaderInfo::getUnitSize(GLuint attrib_id)
{
	return manager->getUnitSize(shader, attrib_id);
}

GLint glrg::ShaderInfo::getType(GLuint attrib_id)
{
	return manager->getType(shader, attrib_id);
}
