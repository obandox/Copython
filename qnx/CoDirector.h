/*
 * CoEGLView.h
 *
 *  Created on: 29/05/2012
 *      Author: miguel
 */

#ifndef _CODirector_H_
#define _CODirector_H_
#include <CCDirector.h>
#include <Cocos2d.h>

#include "CoDefaultScene.h"

namespace cocos2d{

//director

PyObject *
director_setDisplayFPS(PyObject *self, PyObject *args)
{
    int boolean;

    if (!IntFromObjIndex(args, 0, &boolean))
        return NULL;
    CCDirector::sharedDirector()->setDisplayFPS(boolean);
    return Py_BuildValue("i", 1);
}


PyObject *
director_setAnimationInterval(PyObject *self, PyObject *args)
{
    float val;


    if (!FloatFromObjIndex(args, 0, &val))
        return NULL;

    fprintf(stderr," ani interval %.2f ",(val));

    CCDirector::sharedDirector()->setAnimationInterval((double)val);
    return Py_BuildValue("i", 1);
}


PyObject *
director_runWithScene(PyObject *self, PyObject *args)
{


    CCDirector::sharedDirector()->runWithScene(Default::scene());
    return Py_BuildValue("i", 1);
}


static PyMethodDef directorMethods[] = {
		{"setDisplayFPS",  director_setDisplayFPS, METH_VARARGS, "Set Display FPS."},
		{"setAnimationInterval",  director_setAnimationInterval, METH_VARARGS, "set Animation Interval."},
		{"runWithScene",  director_runWithScene, METH_VARARGS, "run With Scene."},
	{NULL}  /* Sentinel */
};



	void initDirector(PyObject* module){
		//director

		PyObject* module2= Py_InitModule("director", directorMethods);
		PyModule_AddObject(module, "director", module2);
	}
}
#endif /* COPOINT_H_ */
