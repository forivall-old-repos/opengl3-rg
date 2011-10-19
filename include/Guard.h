/*
 * Guard.h
 *
 *  Created on: 2011-10-08
 *      Author: Jordan
 */

#ifndef GUARD_H_
#define GUARD_H_

#include "Angel.h"

namespace glrg {
struct vertexData_t {
	GLfloat *data;
	GLsizeiptr size;
	GLsizei numVerticies;
	
	vertexData_t(){}
	
	vertexData_t(
			GLfloat *data,
			GLsizeiptr size,
			GLsizei numVerticies):
				data(data),
				size(size),
				numVerticies(numVerticies)
	{}
};

struct GLRGhandle {
    GLuint GLhandle;
    GLsizeiptr size;
    GLuint attribLocation;
};

class Guard {
public:
    virtual ~Guard() = 0;
    
    virtual void Draw() = 0;
};
}





#endif /* GUARD_H_ */
