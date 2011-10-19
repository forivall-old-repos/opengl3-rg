/*
 * GeometryReprImplGlrgShader.h
 *
 *  Created on: Oct 18, 2011
 *      Author: jord
 */

#ifndef GEOMETRYREPRIMPLGLRGSHADER_H_
#define GEOMETRYREPRIMPLGLRGSHADER_H_

#include "GeometryRepr.h"
#include "ShaderRepr.h"

namespace glrg {

class GeometryReprImplGlrgShader: public glrg::GeometryRepr {
protected:
	ShaderRepr *shader;
	GLint getUnitSize(GLuint);
	GLint getType(GLuint);
public:
	GeometryReprImplGlrgShader(ShaderRepr *shader);
	virtual ~GeometryReprImplGlrgShader();
};

} /* namespace glrg */
#endif /* GEOMETRYREPRIMPLGLRGSHADER_H_ */
