/*
 * CoDirector.h
 *
 *  Created on: 29/05/2012
 *      Author: miguel
 */

#ifndef CODIRECTOR_H_
#define CODIRECTOR_H_
#include <CCGeometry.h>

namespace cocos2d{

//CDirector

	typedef struct {
		PyObject_HEAD
		CCDisplayLinkDirector val;
	    PyObject *weakreflist;
	} PyDirectorObject;

	extern PyTypeObject PyCCDirectorType;
	#define PyCCDirector_Check(x) ((x)->ob_type == &PyCCDirectorType)

	//proxy =D
	CCDisplayLinkDirector* CCDirector_FromObject (PyObject* obj, CCDirector* temp);

	//impresion str
	PyObject* director_repr (PyDirectorObject *self);
	PyObject* director_str (PyDirectorObject *self);


	void initDirector(PyObject* module);
}
#endif /* COPOINT_H_ */
