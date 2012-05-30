/*
 * CoEGLView.h
 *
 *  Created on: 29/05/2012
 *      Author: miguel
 */

#ifndef FileUtils_H_
#define FileUtils_H_
#include <CCFileUtils.h>
#include <Cocos2d.h>

namespace cocos2d{

//FileUtils

PyObject *
fileUtils_setResourcePath(PyObject *self, PyObject *args)
{
    const char *path;
    if (!PyArg_ParseTuple(args, "s", &path))
        return NULL;
    CCFileUtils::setResourcePath(path);
    return Py_BuildValue("i", 1);
}
static PyMethodDef fileUtilsMethods[] = {
	{"setResourcePath",  fileUtils_setResourcePath, METH_VARARGS, "set Resource Path."},
	{NULL}  /* Sentinel */
};



	void initfileUtils(PyObject* module){
		//fileUtils

		PyObject* module2= Py_InitModule("fileUtils", fileUtilsMethods);
		PyModule_AddObject(module, "fileUtils", module2);
	}
}
#endif /* COPOINT_H_ */
