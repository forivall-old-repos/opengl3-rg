/*
 * Item.cpp
 *
 *  Created on: 2011-10-08
 *      Author: Jordan
 */

#include "IndependantItem.h"
#include "ShaderManager.h"

#include <iostream>

using namespace glrg;

void IndependantItem::construct(ShaderManager *manager) {
    this->shader = new ShaderRepr(manager);
    this->geometry = new GeometryReprImplGlrgShader(this->shader);
}

IndependantItem::IndependantItem() {
    this->construct(NULL);
}

IndependantItem::IndependantItem(ShaderManager *manager) {
    this->construct(manager);
}

IndependantItem::~IndependantItem() {
    delete this->shader;
    delete this->geometry;
}

void IndependantItem::setNumVerticies(GLsizei numVerticies) {
    this->geometry->setNumVerticies(numVerticies);
}

void IndependantItem::setDrawMode(GLenum mode) {
    this->drawMode = mode;
}

void IndependantItem::setVertexData(const GLfloat *data, GLsizeiptr size, GLchar* attrib_name) {
	return this->setVertexData(data, size, glGetAttribLocation(this->shader->shader, attrib_name));
}

void IndependantItem::setVertexData(const GLfloat *data, GLsizeiptr size, GLuint attrib_loc) {
    this->geometry->setVertexData(data, size, attrib_loc);
}

void IndependantItem::setShaderProgram(GLuint program) {
    this->shader->setShaderProgram(program);
    // todo: rebind attribs
}

void glrg::IndependantItem::setVertexData(const vertexData_t &data, GLuint attrib_loc)
{
	this->geometry->setVertexData(data, attrib_loc);
}

GeometryRepr *glrg::IndependantItem::getGeometryRepr()
{
	return this->geometry;
}

void glrg::IndependantItem::setUniformData(UNIFORM_TYPE type, const GLfloat *data, GLchar *name)
{
	this->shader->setUniformData(type, data, name);
}

void glrg::IndependantItem::setUniformData(UNIFORM_TYPE type, const GLfloat *data, GLuint location)
{
	this->shader->setUniformData(type, data, location);
}

void IndependantItem::Draw() {
    this->shader->Draw();
    // load our vertex array object, draw it, unload it.
    glBindVertexArray(this->geometry->vertexArrayObject);
    glDrawArrays(this->drawMode, 0, this->geometry->numVerticies);
//    glDrawArrays(GL_TRIANGLE_STRIP, 0, 3);
    glBindVertexArray(0);
}
