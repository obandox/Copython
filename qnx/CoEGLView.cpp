
#include "Python/Python.h"

#include <cocos2d.h>
#include "CoEGLView.h"
#include "CoBase.h"

namespace cocos2d{

	CCEGLView*
	CCEGLView_FromObject (PyObject* obj, CCEGLView* temp)
	{
	    float val;
	    int length;

	    if (PyCCEGLView_Check (obj))
	        return &( (PyEGLViewObject*) obj )->val;


	    return NULL;
	}


	static PyObject*
	EGLView_new (PyTypeObject *type, PyObject *args, PyObject *kwds)
	{
	    PyEGLViewObject *self;
	    self = (PyEGLViewObject *)type->tp_alloc (type, 0);
	    if (self)
	    {
	        self->weakreflist = NULL;
	    }
	    return (PyObject*)self;
	}

	static int
	EGLView_init (PyEGLViewObject *self, PyObject *args, PyObject *kwds)
	{
		CCEGLView *arg, temp;
	    if (!(arg = CCEGLView_FromObject(args, &temp)))
	    {
	        RAISE (PyExc_TypeError, "Argument must be EGLView style object");
	        return -1;
	    }


	    return 0;
	}


//GETTER AND SETTER



	static PyGetSetDef EGLView_getsets[] = {
	    { NULL, 0, NULL, NULL, NULL }  /* Sentinel */
	};


	//estableciendo tipo
	PyTypeObject PyCCEGLViewType = {
	    PyObject_HEAD_INIT(NULL)
	    0,                         /*ob_size*/
	    "cocos2d.EGLView",             /*tp_name*/
	    sizeof(PyEGLViewObject),             /*tp_basicsize*/
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
	    "EGLView objects",           /* tp_doc */
	    0,		               /* tp_traverse */
	    0,		               /* tp_clear */
	    0,		               /* tp_richcompare */
	    0,		               /* tp_weaklistoffset */
	    0,		               /* tp_iter */
	    0,		               /* tp_iternext */
	    0,            		 /* tp_methods */
	    0,          		   /* tp_members */
	    EGLView_getsets,         			  /* tp_getset */
	    0,                         /* tp_base */
	    0,                         /* tp_dict */
	    0,                         /* tp_descr_get */
	    0,                         /* tp_descr_set */
	    0,                         /* tp_dictoffset */
	    (initproc)EGLView_init,      				/* tp_init */
	    0,                         /* tp_alloc */
	    EGLView_new,                       /* tp_new */
	};

	void initEGLView(PyObject* module)
	{
		PyCCEGLViewType.tp_new = PyType_GenericNew;
		if (PyType_Ready(&PyCCEGLViewType) < 0)
			return;
		Py_INCREF(&PyCCEGLViewType);
		PyModule_AddObject(module, "EGLView", (PyObject *)&PyCCEGLViewType);

	}

}

