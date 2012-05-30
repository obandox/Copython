/*
 * CoBase.h
 *
 *  Created on: 29/05/2012
 *      Author: miguel
 */

#ifndef COBASE_H_
#define COBASE_H_

#define NO_PYGAME_C_API
#define PYGAMEAPI_BASE_INTERNAL

#include <signal.h>


#include <stdint.h>
typedef uint8_t Uint8;
typedef uint16_t Uint16;
typedef uint32_t Uint32;


/* macros used throughout the source */
#define RAISE(x,y) (PyErr_SetString((x), (y)), (PyObject*)NULL)


/* internal C API utility functions */
static int
IntFromObj (PyObject* obj, int* val) {
    int tmp_val;
    tmp_val = PyInt_AsLong (obj);
    if (tmp_val == -1 && PyErr_Occurred ())
    {
        PyErr_Clear ();
        return 0;
    }
    *val = tmp_val;
    return 1;
}

static int
IntFromObjIndex (PyObject* obj, int _index, int* val)
{
    int result = 0;
    PyObject* item;
    item = PySequence_GetItem (obj, _index);
    if (item)
    {
        result = IntFromObj (item, val);
        Py_DECREF (item);
    }
    return result;
}

static int
TwoIntsFromObj (PyObject* obj, int* val1, int* val2)
{
    if (PyTuple_Check (obj) && PyTuple_Size (obj) == 1)
        return TwoIntsFromObj (PyTuple_GET_ITEM (obj, 0), val1, val2);

    if (!PySequence_Check (obj) || PySequence_Length (obj) != 2)
        return 0;

    if (!IntFromObjIndex (obj, 0, val1) || !IntFromObjIndex (obj, 1, val2))
        return 0;

    return 1;
}

static int
FloatFromObj (PyObject* obj, float* val)
{
    float f= (float)PyFloat_AsDouble (obj);

    if (f==-1 && PyErr_Occurred()) {
		PyErr_Clear ();
        return 0;
	}

    *val = f;
    return 1;
}

static int
FloatFromObjIndex (PyObject* obj, int _index, float* val)
{
    int result = 0;
    PyObject* item;
    item = PySequence_GetItem (obj, _index);
    if (item)
    {
        result = FloatFromObj (item, val);
        Py_DECREF (item);
    }
    return result;
}

static int
TwoFloatsFromObj (PyObject* obj, float* val1, float* val2)
{
    if (PyTuple_Check (obj) && PyTuple_Size (obj) == 1)
        return TwoFloatsFromObj (PyTuple_GET_ITEM (obj, 0), val1, val2);

    if (!PySequence_Check (obj) || PySequence_Length (obj) != 2)
        return 0;

    if (!FloatFromObjIndex (obj, 0, val1) || !FloatFromObjIndex (obj, 1, val2))
        return 0;

    return 1;
}

static int
UintFromObj (PyObject* obj, Uint32* val)
{
    PyObject* longobj;

    if (PyNumber_Check (obj))
    {
        if (!(longobj = PyNumber_Long (obj)))
            return 0;
        *val = (Uint32) PyLong_AsUnsignedLong (longobj);
        Py_DECREF (longobj);
        return 1;
    }
    return 0;
}

static int
UintFromObjIndex (PyObject* obj, int _index, Uint32* val)
{
    int result = 0;
    PyObject* item;
    item = PySequence_GetItem (obj, _index);
    if (item)
    {
        result = UintFromObj (item, val);
        Py_DECREF (item);
    }
    return result;
}

static int
RGBAFromObj (PyObject* obj, Uint8* RGBA)
{
    int length;
    Uint32 val;
    if (PyTuple_Check (obj) && PyTuple_Size (obj) == 1)
        return RGBAFromObj (PyTuple_GET_ITEM (obj, 0), RGBA);

    if (!PySequence_Check (obj))
        return 0;

    length = PySequence_Length (obj);
    if (length < 3 || length > 4)
        return 0;

    if (!UintFromObjIndex (obj, 0, &val) || val > 255)
        return 0;
    RGBA[0] = (Uint8) val;
    if (!UintFromObjIndex (obj, 1, &val) || val > 255)
        return 0;
    RGBA[1] = (Uint8) val;
    if (!UintFromObjIndex (obj, 2, &val) || val > 255)
        return 0;
    RGBA[2] = (Uint8) val;
    if (length == 4)
    {
        if (!UintFromObjIndex (obj, 3, &val) || val > 255)
            return 0;
        RGBA[3] = (Uint8) val;
    }
    else RGBA[3] = (Uint8) 255;

    return 1;
}




#endif /* COBASE_H_ */
