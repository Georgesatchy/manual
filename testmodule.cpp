#include <Python.h>
#include <stdio.h>

PyObject *exampleAdd(PyObject *self, PyObject *args) {
    int x;
    int y;
    PyArg_ParseTuple(args, "ii", &x, &y); // "ii" refers to two integer arguments - more information can be found in Python docs
    int result = x + y;
    return PyLong_FromLong((long) (result));
};

static PyMethodDef methods[] {
    { "example_add", exampleAdd, METH_VARARGS, "Adds two numbers together" },
    { NULL, NULL, 0, NULL }
};

static struct PyModuleDef testModule = {
    PyModuleDef_HEAD_INIT,
    "Test Module",
    "Simple module with solely an add function to demonstrate how to make Python modules with CPP",
    -1,
    methods
};

PyMODINIT_FUNC PyInit_testModule () {
    printf("hello world\n");
    return PyModule_Create(&testModule);
};