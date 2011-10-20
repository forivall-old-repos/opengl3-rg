/*
 * GeometryRepr.cpp
 *
 *  Created on: Oct 18, 2011
 *      Author: jord
 */

#include "GeometryRepr.h"
#include <iostream>

glrg::GeometryRepr::GeometryRepr() {
	this->vertexData = new std::map<GLuint, GLRGhandle *>();
	glGenVertexArrays(1, &vertexArrayObject);
}

glrg::GeometryRepr::~GeometryRepr() {
	
}

void glrg::GeometryRepr::setNumVerticies(GLsizei numVerticies) {
	this->numVerticies = numVerticies;
}



//void glrg::GeometryRepr::setVertexData(
//		const GLfloat *data, GLsizeiptr size, GLchar *attrib_name) {
//	GLuint attrib_loc = glGetAttribLocation(this->shader->shader, attrib_name));
//	return this->setVertexData(data, size, attrib_loc);
//}



void glrg::GeometryRepr::setVertexData(
		const GLfloat *data, GLsizeiptr size, GLuint attrib_loc) {
//	GLRGhandle *handle = (*(this->vertexData))[attrib_loc];
//	std::cout << data << " " << *data << std::endl;
	GLRGhandle *handleinfo = this->vertexData->operator [](attrib_loc);
//	std::cout << data << " " << *data << std::endl;
	
	if(handleinfo == NULL) {
		// initialize the data
		handleinfo = new GLRGhandle;
		glGenBuffers(1, &handleinfo->GLhandle);
		handleinfo->size = size;
		//        handleinfo->attribLocation = glGetAttribLocation(this->shader, attrib_name);
		handleinfo->attribLocation = attrib_loc;

		// buffer the data into video memory
		glBindBuffer(GL_ARRAY_BUFFER, handleinfo->GLhandle);
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);

		// setup our vertex array object, make sure it's enabled, 
		//  and push the attributes to video memory  
		glBindVertexArray(vertexArrayObject);
		glEnableVertexAttribArray(handleinfo->attribLocation);
		glBindBuffer(GL_ARRAY_BUFFER, handleinfo->GLhandle);
		glVertexAttribPointer(
				handleinfo->attribLocation, 
				this->getUnitSize(attrib_loc), 
				this->getType(attrib_loc), 
				GL_FALSE, 0, 0);

//        glBindVertexArray(0);
//		this->vertexData->operator [](attrib_loc) = handleinfo;
	}
	else {
		// just overwrite the data. done.
		glBindBuffer(GL_ARRAY_BUFFER, handleinfo->GLhandle);
		glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
	}
}

void glrg::GeometryRepr::setVertexData(const vertexData_t &data, GLuint attrib_loc)
{
	this->setVertexData(data.data, data.size, attrib_loc);
}





