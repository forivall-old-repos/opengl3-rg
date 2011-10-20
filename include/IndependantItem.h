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
#include "ShaderRepr.h"
#include "GeometryReprImplGlrgShader.h"
#include <string>
#include <map>

namespace glrg {

class IndependantItem : public glrg::Guard 
{
    void construct(ShaderManager *);
protected:
    GLenum drawMode;
    ShaderRepr *shader;
    GeometryRepr *geometry;
    
public:
    IndependantItem();
    IndependantItem(ShaderManager *);
    
    virtual ~IndependantItem();
    
    void setNumVerticies(GLsizei);
    void setDrawMode(GLenum);
    void setVertexData(const GLfloat*, GLsizeiptr, GLchar *);
    void setVertexData(const GLfloat*, GLsizeiptr, GLuint);
    void setVertexData(const vertexData_t &, GLuint);
    void setUniformData(UNIFORM_TYPE type, const GLfloat *, GLchar *);
    void setUniformData(UNIFORM_TYPE type, const GLfloat *, GLuint location);
    void setShaderProgram(GLuint);
    
    GeometryRepr *getGeometryRepr();
    
    virtual void Draw();
};

}


#endif /* ITEM_H_ */
