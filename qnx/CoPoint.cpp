
#include "Python/Python.h"

#include <cocos2d.h>
#include "CoPoint.h"
#include "CoBase.h"

namespace cocos2d{

	CCPoint*
	CCPoint_FromObject (PyObject* obj, CCPoint* temp)
	{
	    float val;
	    int length;

	    if (PyCCPoint_Check (obj))
	        return &( (PyPointObject*) obj )->val;

	    if (PySequence_Check (obj) && (length = PySequence_Length (obj)) > 0)
	    {
	        if (length == 2)
	        {
	            if (!FloatFromObjIndex(obj, 0, &val))
	                return NULL;
	            temp->x = val;
	            if (!FloatFromObjIndex (obj, 1, &val))
	                return NULL;
	            temp->y = val;

	            return temp;
	        }
	        if (PyTuple_Check (obj) && length == 1) /*looks like an arg?*/
	        {
	            PyObject* sub = PyTuple_GET_ITEM (obj, 0);
	            if (sub)
	                return CCPoint_FromObject (sub, temp);
	        }
	    }
	    if (PyObject_HasAttrString (obj, "point"))
	    {
	        PyObject *attr;
	        CCPoint *ret;
	        attr = PyObject_GetAttrString (obj, "point");
	        if (PyCallable_Check (attr)) /*call if it's a method*/
	        {
	            PyObject *result = PyObject_CallObject (attr, NULL);
	            Py_DECREF (attr);
	            if (!result)
	                return NULL;
	            attr = result;
	        }
	        ret = CCPoint_FromObject (attr, temp);
	        Py_DECREF (attr);
	        return ret;
	    }
	    return NULL;
	}


	static PyObject*
	point_new (PyTypeObject *type, PyObject *args, PyObject *kwds)
	{
	    PyPointObject *self;
	    self = (PyPointObject *)type->tp_alloc (type, 0);
	    if (self)
	    {
	        self->val.x = 0;
	        self->val.y = 0;
	        self->weakreflist = NULL;
	    }
	    return (PyObject*)self;
	}

	static int
	point_init (PyPointObject *self, PyObject *args, PyObject *kwds)
	{
	    CCPoint *arg, temp;
	    if (!(arg = CCPoint_FromObject(args, &temp)))
	    {
	        RAISE (PyExc_TypeError, "Argument must be point style object");
	        return -1;
	    }

	    self->val.x = temp.x;
	    self->val.y = temp.y;

	    return 0;
	}

	//impresion str
	PyObject*
	point_repr (PyPointObject *self)
	{
	    char string[256];
	    sprintf (string, "<Point(%.2f, %.2f)>", self->val.x, self->val.y);
	    return PyUnicode_FromString (string);
	}

	PyObject*
	point_str (PyPointObject *self)
	{
	    return point_repr (self);
	}

//GETTER AND SETTER

	/*x*/
	static PyObject*
	point_getx (PyPointObject *self, void *closure)
	{
	    return PyFloat_FromDouble(self->val.x);
	}
	static float
	point_setx (PyPointObject *self, PyObject* value, void *closure)
	{
		float val1;
	    if (!FloatFromObj (value, &val1))
	    {
	        RAISE (PyExc_TypeError, "invalid point assignment");
	        return -1;
	    }
	    self->val.x = val1;
	    return 0;
	}


	/*y*/
	static PyObject*
	point_gety (PyPointObject *self, void *closure)
	{
	    return PyFloat_FromDouble(self->val.y);
	}
	static float
	point_sety (PyPointObject *self, PyObject* value, void *closure)
	{
		float val1;
	    if (!FloatFromObj (value, &val1))
	    {
	        RAISE (PyExc_TypeError, "invalid point assignment");
	        return -1;
	    }
	    self->val.y = val1;
	    return 0;
	}


	static PyGetSetDef point_getsets[] = {
	    { "x", (getter)point_getx, (setter)point_setx, NULL, NULL },
	    { "y", (getter)point_gety, (setter)point_sety, NULL, NULL },
	    { NULL, 0, NULL, NULL, NULL }  /* Sentinel */
	};


	//estableciendo tipo
	PyTypeObject PyCCPointType = {
	    PyObject_HEAD_INIT(NULL)
	    0,                         /*ob_size*/
	    "cocos2d.Point",             /*tp_name*/
	    sizeof(PyPointObject),             /*tp_basicsize*/
	    0,                         /*tp_itemsize*/
	    0, 							/*tp_dealloc*/
	    0,                         /*tp_print*/
	    0,                         /*tp_getattr*/
	    0,                         /*tp_setattr*/
	    0,                         /*tp_compare*/
	    (reprfunc)point_repr,                         /*tp_repr*/
	    0,                         /*tp_as_number*/
	    0,                         /*tp_as_sequence*/
	    0,                         /*tp_as_mapping*/
	    0,                         /*tp_hash */
	    0,                         /*tp_call*/
	    (reprfunc)point_str,                         /*tp_str*/
	    0,                         /*tp_getattro*/
	    0,                         /*tp_setattro*/
	    0,                         /*tp_as_buffer*/
	    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, /*tp_flags*/
	    "Point objects",           /* tp_doc */
	    0,		               /* tp_traverse */
	    0,		               /* tp_clear */
	    0,		               /* tp_richcompare */
	    0,		               /* tp_weaklistoffset */
	    0,		               /* tp_iter */
	    0,		               /* tp_iternext */
	    0,            		 /* tp_methods */
	    0,          		   /* tp_members */
	    point_getsets,         			  /* tp_getset */
	    0,                         /* tp_base */
	    0,                         /* tp_dict */
	    0,                         /* tp_descr_get */
	    0,                         /* tp_descr_set */
	    0,                         /* tp_dictoffset */
	    (initproc)point_init,      				/* tp_init */
	    0,                         /* tp_alloc */
	    point_new,                       /* tp_new */
	};

	void initPoint(PyObject* module)
	{
		PyCCPointType.tp_new = PyType_GenericNew;
		if (PyType_Ready(&PyCCPointType) < 0)
			return;
		Py_INCREF(&PyCCPointType);
		PyModule_AddObject(module, "Point", (PyObject *)&PyCCPointType);

	}

}

