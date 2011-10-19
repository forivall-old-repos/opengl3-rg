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
// todo: just explain this rather than have a function call.
// or use preproccesor macros to make automatic overloading functions
void IndependantItem::setUniformData(const GLfloat* data, GLsizei size, GLchar *uniform_name) {
//    GLuint location = glGetUniformLocation(self->shader, uniform_name);
//    glUniform...(location, size, GL_FALSE, *data);
////    glUniformMatrix4fv(iTransform, 1, GL_FALSE, *mvpMatrix);
}

void IndependantItem::setShaderProgram(GLuint program) {
    this->shader->setShaderProgram(program);
    // todo: rebind attribs
}

void IndependantItem::Draw() {
    // todo: also load shader and uniforms.
    // load our vertex array object, draw it, unload it.
    glBindVertexArray(this->geometry->vertexArrayObject);
    glDrawArrays(this->drawMode, 0, this->geometry->numVerticies);
//    glDrawArrays(GL_TRIANGLE_STRIP, 0, 3);
    glBindVertexArray(0);
}
