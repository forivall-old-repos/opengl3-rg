/*
 * CloneItem.h
 *
 *  Created on: Oct 18, 2011
 *      Author: jord
 */

#ifndef CLONEITEM_H_
#define CLONEITEM_H_

#include "Item.h"

class CloneItem: public glrg::Guard {
private:
	glrg::Item *original;
public:
	CloneItem(glrg::Item *);
	virtual ~CloneItem();
};

#endif /* CLONEITEM_H_ */
