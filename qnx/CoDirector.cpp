
#include "Python/Python.h"

#include <cocos2d.h>
#include "CoDirector.h"
#include "CoBase.h"

namespace cocos2d{

	CCDisplayLinkDirector*
	CCDirector_FromObject (PyObject* obj, CCDirector* temp)
	{
	    float val;
	    int length;

	    if (PyCCDirector_Check (obj))
	        return &( (PyDirectorObject*) obj )->val;


	    return NULL;
	}


	static PyObject*
	director_new (PyTypeObject *type, PyObject *args, PyObject *kwds)
	{
	    PyDirectorObject *self;
	    self = (PyDirectorObject *)type->tp_alloc (type, 0);
	    if (self)
	    {
	        self->weakreflist = NULL;
	    }
	    return (PyObject*)self;
	}

	static int
	director_init (PyDirectorObject *self, PyObject *args, PyObject *kwds)
	{
		CCDisplayLinkDirector *arg, temp;
	    if (!(arg = CCDirector_FromObject(args, &temp)))
	    {
	        RAISE (PyExc_TypeError, "Argument must be director style object");
	        return -1;
	    }


	    return 0;
	}


//GETTER AND SETTER



	static PyGetSetDef director_getsets[] = {
	    { NULL, 0, NULL, NULL, NULL }  /* Sentinel */
	};


	//estableciendo tipo
	PyTypeObject PyCCDirectorType = {
	    PyObject_HEAD_INIT(NULL)
	    0,                         /*ob_size*/
	    "cocos2d.Director",             /*tp_name*/
	    sizeof(PyDirectorObject),             /*tp_basicsize*/
	    0,                         /*tp_itemsize*/
	    0, 							/*tp_dealloc*/
	    0,                         /*tp_print*/
	    0,                         /*tp_getattr*/
	    0,                         /*tp_setattr*/
	    0,                         /*tp_compare*/
	    (reprfunc)0,                         /*tp_repr*/
	    0,                         /*tp_as_number*/
	    0,                         /*tp_as_sequence*/
	    0,                         /*tp_as_mapping*/
	    0,                         /*tp_hash */
	    0,                         /*tp_call*/
	    (reprfunc)0,                         /*tp_str*/
	    0,                         /*tp_getattro*/
	    0,                         /*tp_setattro*/
	    0,                         /*tp_as_buffer*/
	    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, /*tp_flags*/
	    "Director objects",           /* tp_doc */
	    0,		               /* tp_traverse */
	    0,		               /* tp_clear */
	    0,		               /* tp_richcompare */
	    0,		               /* tp_weaklistoffset */
	    0,		               /* tp_iter */
	    0,		               /* tp_iternext */
	    0,            		 /* tp_methods */
	    0,          		   /* tp_members */
	    director_getsets,         			  /* tp_getset */
	    0,                         /* tp_base */
	    0,                         /* tp_dict */
	    0,                         /* tp_descr_get */
	    0,                         /* tp_descr_set */
	    0,                         /* tp_dictoffset */
	    (initproc)director_init,      				/* tp_init */
	    0,                         /* tp_alloc */
	    director_new,                       /* tp_new */
	};

	void initDirector(PyObject* module)
	{
		PyCCDirectorType.tp_new = PyType_GenericNew;
		if (PyType_Ready(&PyCCDirectorType) < 0)
			return;
		Py_INCREF(&PyCCDirectorType);
		PyModule_AddObject(module, "Director", (PyObject *)&PyCCDirectorType);

	}

}

