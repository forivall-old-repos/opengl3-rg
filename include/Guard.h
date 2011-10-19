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
struct GLRGhandle {
    GLuint GLhandle;
    GLsizeiptr size;
    GLuint attribLocation;
};

class Guard {
public:
//    virtual ~Guard();
    
    virtual void Draw() = 0;
};

}


#endif /* GUARD_H_ */
