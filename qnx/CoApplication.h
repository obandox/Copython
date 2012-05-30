/*
 * CoApplication.h
 *
 *  Created on: 29/05/2012
 *      Author: miguel
 */

#ifndef COApplication_H_
#define COApplication_H_
#include <CCGeometry.h>

namespace cocos2d{

//CApplication


class ProxyCCApplication;

	typedef struct {
		PyObject_HEAD
		ProxyCCApplication* val;
	    PyObject *weakreflist;
	} PyApplicationObject;




	extern PyTypeObject PyCCApplicationType;
	#define PyCCApplication_Check(x) ((x)->ob_type == &PyCCApplicationType)

	//proxy =D
	ProxyCCApplication* CCApplication_FromObject (PyObject* obj, CCApplication* temp);

	//methods
	PyObject* application_run (PyApplicationObject *self);

	//impresion str
	PyObject* application_repr (PyApplicationObject *self);
	PyObject* application_str (PyApplicationObject *self);


	void initApplication(PyObject* module);
}
#endif /* COPOINT_H_ */
