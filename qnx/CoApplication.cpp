
#include "Python/Python.h"

#include <cocos2d.h>
#include "CoApplication.h"
#include "CoBase.h"

namespace cocos2d{


bool ProxyCCApplication::initInstance() {

	return true;
}

bool ProxyCCApplication::applicationDidFinishLaunching(){

	return true;
}

void ProxyCCApplication::applicationDidEnterBackground(){

}

void ProxyCCApplication::applicationWillEnterForeground(){

}

	ProxyCCApplication*
	CCApplication_FromObject (PyObject* obj, CCApplication* temp)
	{
	    float val;
	    int length;

	    if (PyCCApplication_Check (obj))
	        return ( (PyApplicationObject*) obj )->val;


	    return NULL;
	}


	static PyObject*
	application_new (PyTypeObject *type, PyObject *args, PyObject *kwds)
	{
	    PyApplicationObject *self;
	    self = (PyApplicationObject *)type->tp_alloc (type, 0);
	    if (self)
	    {	self->val = new ProxyCCApplication();
	    	self->val->app=(void*)self;
	        self->weakreflist = NULL;
	    }
	    return (PyObject*)self;
	}


	//methods
	PyObject* application_run (PyApplicationObject *self){
		self->val->run();

	}

	static PyMethodDef application_methods[] = {
	    {"run", (PyCFunction)application_run, METH_NOARGS,   "Run app"   },
	    {NULL}  /* Sentinel */
	};

//GETTER AND SETTER



	static PyGetSetDef application_getsets[] = {
	    { NULL, 0, NULL, NULL, NULL }  /* Sentinel */
	};


	//estableciendo tipo
	PyTypeObject PyCCApplicationType = {
	    PyObject_HEAD_INIT(NULL)
	    0,                         /*ob_size*/
	    "cocos2d.Application",             /*tp_name*/
	    sizeof(PyApplicationObject),             /*tp_basicsize*/
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
	    "Application objects",           /* tp_doc */
	    0,		               /* tp_traverse */
	    0,		               /* tp_clear */
	    0,		               /* tp_richcompare */
	    0,		               /* tp_weaklistoffset */
	    0,		               /* tp_iter */
	    0,		               /* tp_iternext */
	    application_methods,            		 /* tp_methods */
	    0,          		   /* tp_members */
	    application_getsets,         			  /* tp_getset */
	    0,                         /* tp_base */
	    0,                         /* tp_dict */
	    0,                         /* tp_descr_get */
	    0,                         /* tp_descr_set */
	    0,                         /* tp_dictoffset */
	    (initproc)0,      				/* tp_init */
	    0,                         /* tp_alloc */
	    application_new,                       /* tp_new */
	};

	void initApplication(PyObject* module)
	{
		PyCCApplicationType.tp_new = PyType_GenericNew;
		if (PyType_Ready(&PyCCApplicationType) < 0)
			return;
		Py_INCREF(&PyCCApplicationType);
		PyModule_AddObject(module, "Application", (PyObject *)&PyCCApplicationType);

	}

}

