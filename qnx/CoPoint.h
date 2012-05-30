/*
 * CoPoint.h
 *
 *  Created on: 29/05/2012
 *      Author: miguel
 */

#ifndef COPOINT_H_
#define COPOINT_H_
#include <CCGeometry.h>

namespace cocos2d{

//CPoint

	typedef struct {
		PyObject_HEAD
		CCPoint val;
	    PyObject *weakreflist;
	} PyPointObject;

	extern PyTypeObject PyCCPointType;
	#define PyCCPoint_Check(x) ((x)->ob_type == &PyCCPointType)

	//proxy =D
	CCPoint* CCPoint_FromObject (PyObject* obj, CCPoint* temp);

	//impresion str
	PyObject* point_repr (PyPointObject *self);
	PyObject* point_str (PyPointObject *self);


	void initPoint(PyObject* module);
}
#endif /* COPOINT_H_ */
