/*
 * GeometryRepr.h
 *
 *  Created on: Oct 18, 2011
 *      Author: jord
 */

#include "Angel.h"
#include "Guard.h"
#include <map>

#ifndef GEOMETRYREPR_H_
#define GEOMETRYREPR_H_

namespace glrg {
class GeometryRepr {
protected:
	virtual GLint getUnitSize(GLuint) = 0;
	virtual GLint getType(GLuint) = 0;
public:
	GeometryRepr();
	virtual ~GeometryRepr();
	
	void setNumVerticies(GLsizei);
//	void setVertexData(const GLfloat*, GLsizeiptr, GLchar *);
	void setVertexData(const GLfloat*, GLsizeiptr, GLuint);
	
	std::map<GLuint, GLRGhandle *> *vertexData;
	GLuint vertexArrayObject;
	GLsizei numVerticies;
};
}

#endif /* GEOMETRYREPR_H_ */
