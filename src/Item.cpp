/*
 * Item.cpp
 *
 *  Created on: 2011-10-08
 *      Author: Jordan
 */

#include "Item.h"
#include "ShaderManager.h"

using namespace glrg;

void Item::construct(ShaderManager *manager) {
    this->shaders = manager;
    this->vertexData  = new std::map<GLuint, GLRGhandle *>();
    this->uniformData = new std::map<std::string, GLRGhandle *>();
    glGenVertexArrays(1, &vertexArrayObject);
//    glBindVertexArray(vertexArrayObject);
}

Item::Item() {
    this->construct(ShaderManager::getSingleton());
}

Item::Item(ShaderManager *manager) {
    this->construct(manager);
}

Item::~Item()
{
    delete this->vertexData;
    delete this->uniformData;
    glDeleteVertexArrays(1, &vertexArrayObject);
}

void Item::setNumVerticies(GLsizei numVerticies) {
    this->numVerticies = numVerticies;
}

void Item::setDrawMode(GLenum mode) {
    this->drawMode = mode;
}

void Item::setVertexData(const GLfloat* data, GLsizeiptr size, GLuint attrib_loc) {
    GLRGhandle *handle = this->vertexData->operator [](attrib_loc);
    printf("%d\n", handle);
    if(handle == NULL) {
        // initialize the data
        handle = new GLRGhandle;
        glGenBuffers(1, &handle->GLhandle);
        handle->size = size;
//        handle->attribLocation = glGetAttribLocation(this->shader, attrib_name);
        handle->attribLocation = attrib_loc;
        
        // buffer the data into video memory
        glBindBuffer(GL_ARRAY_BUFFER, handle->GLhandle);
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
        
        // setup our vertex array object, make sure it's enabled, 
        //  and push the attributes to video memory  
        glBindVertexArray(vertexArrayObject);
        glEnableVertexAttribArray(handle->attribLocation);
        glBindBuffer(GL_ARRAY_BUFFER, handle->GLhandle);
        printf("loc:%d, size:%d, type:%d\n",handle->attribLocation, 
                shaders->getUnitSize(this->shader, attrib_loc), 
                shaders->getType(this->shader, attrib_loc));
        glVertexAttribPointer(
                handle->attribLocation, 
                shaders->getUnitSize(this->shader, attrib_loc), 
                shaders->getType(this->shader, attrib_loc), 
                GL_FALSE, 0, 0);
        
//        glBindVertexArray(0);
    }
    else {
        // just overwrite the data. done.
        glBindBuffer(GL_ARRAY_BUFFER, handle->GLhandle);
        glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
    }
}
// todo: just explain this rather than have a function call.
// or use preproccesor macros to make automatic overloading functions
void Item::setUniformData(const GLfloat* data, GLsizei size, GLchar *uniform_name) {
//    GLuint location = glGetUniformLocation(self->shader, uniform_name);
//    glUniform...(location, size, GL_FALSE, *data);
////    glUniformMatrix4fv(iTransform, 1, GL_FALSE, *mvpMatrix);
}
void Item::setShaderProgram(GLuint program) {
    this->shader = program;
    // todo: rebind attribs
}

void Item::Draw() {
    // todo: also load shader and uniforms.
    puts("drawing");
    // load our vertex array object, draw it, unload it.
    glBindVertexArray(vertexArrayObject);
//    glDrawArrays(this->drawMode, 0, this->numVerticies);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 3);
    glBindVertexArray(0);
}
