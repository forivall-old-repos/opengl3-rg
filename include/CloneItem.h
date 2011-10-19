/*
 * CloneItem.h
 *
 *  Created on: Oct 18, 2011
 *      Author: jord
 */

#ifndef CLONEITEM_H_
#define CLONEITEM_H_

#include "ShaderRepr.h"
#include "GeometryRepr.h"
namespace glrg {
class CloneItem: public glrg::Guard {
private:
	glrg::GeometryRepr *original;
//	void construct(glrg::GeometryRepr *, glrg::ShaderManager *);
	
public:
	CloneItem(glrg::GeometryRepr *, glrg::ShaderManager *);
	virtual ~CloneItem();
};
}
#endif /* CLONEITEM_H_ */
