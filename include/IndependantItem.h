/*
 * Item.h
 *
 *  Created on: 2011-10-08
 *      Author: Jordan
 */
#include "Angel.h"

#ifndef ITEM_H_
#define ITEM_H_

#include "Guard.h"
#include "ShaderManager.h"
#include <string>
#include <map>

namespace glrg {
struct GLRGhandle {
    GLuint GLhandle;
    GLsizeiptr size;
    GLuint attribLocation;
};

class IndependantItem : public glrg::Guard 
{
    void construct(ShaderManager *);

protected:
    ShaderManager *shaders;
    GLenum drawMode;
    
public:
    IndependantItem();
    IndependantItem(ShaderManager *);
    
    virtual ~IndependantItem();
    
    void setNumVerticies(GLsizei);
    void setDrawMode(GLenum);
    void setVertexData(const GLfloat*, GLsizeiptr, GLchar *);
    void setVertexData(const GLfloat*, GLsizeiptr, GLuint);
    void setUniformData(const GLfloat*, GLsizei, GLchar *);
    void setShaderProgram(GLuint);
    
    virtual void Draw();
    
    std::map<GLuint, GLRGhandle *> *vertexData;
    std::map<std::string, GLRGhandle *> *uniformData;
    GLuint vertexArrayObject;
    GLuint shader;
    GLsizei numVerticies;
};

}


#endif /* ITEM_H_ */
