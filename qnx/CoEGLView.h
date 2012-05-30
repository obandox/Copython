/*
 * CoEGLView.h
 *
 *  Created on: 29/05/2012
 *      Author: miguel
 */

#ifndef COEGLView_H_
#define COEGLView_H_
#include <CCGeometry.h>

namespace cocos2d{

//CEGLView

	typedef struct {
		PyObject_HEAD
		CCEGLView* val;
	    PyObject *weakreflist;
	} PyEGLViewObject;

	extern PyTypeObject PyCCEGLViewType;
	#define PyCCEGLView_Check(x) ((x)->ob_type == &PyCCEGLViewType)

	//proxy =D
	CCEGLView* CCEGLView_FromObject (PyObject* obj, CCEGLView* temp);

	//impresion str
	PyObject* EGLView_repr (PyEGLViewObject *self);
	PyObject* EGLView_str (PyEGLViewObject *self);


	void initEGLView(PyObject* module);
}
#endif /* COPOINT_H_ */
