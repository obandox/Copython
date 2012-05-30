#ifndef Copython_H
#define Copython_H

#include "Python/Python.h"

#include <cocos2d.h>


#include "CoBase.h"
#include "CoPoint.h"

namespace cocos2d{

	static PyMethodDef cocos2dMethods[] = {
		{NULL}  /* Sentinel */
	};

	void initCoco2d(void){

		PyObject* m;
		m = Py_InitModule3("cocos2d", cocos2dMethods,
						   "copython es un intento por pegar cocos2d a python para una playbook.");
		initPoint(m);
	}
}

#endif
