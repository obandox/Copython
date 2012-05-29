#ifndef Copython_H
#define Copython_H
#include "../Python/Python.h"

#include <cocos2d.h>

#define MODPREFIX "cocos2d_"

namespace cocos2d{

	static PyMethodDef methods[] = { NULL, NULL, 0, NULL };


	typedef struct {
	    PyObject_HEAD
	    CCApplication* data;
	    PyObject *weakreflist;
	    PyObject *locklist;
	    PyObject *dependency;
	} PyApplicationObject;




#define MODINIT_DEFINE(mod_name) PyMODINIT_FUNC PyInit_##mod_name (void)


	void initCoco2d(){
		PyObject* module;


		module = Py_InitModule("cocos2d", methods);


	    module = Py_InitModule3 (MODPREFIX "Application", methods, "0.0" );
	}


}
#endif
