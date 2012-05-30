/*
 * CoEGLView.h
 *
 *  Created on: 29/05/2012
 *      Author: miguel
 */

#ifndef FileUtils_H_
#define FileUtils_H_
#include <CCGeometry.h>
#include <Cocos2d.h>

namespace cocos2d{

//FileUtils


static PyMethodDef fileUtilsMethods[] = {

	{NULL}  /* Sentinel */
};



	void initfileUtils(PyObject* module){
		//fileUtils

		PyObject* module2= Py_InitModule("fileUtils", fileUtilsMethods);
		PyModule_AddObject(module, "fileUtils", module2);
	}
}
#endif /* COPOINT_H_ */
