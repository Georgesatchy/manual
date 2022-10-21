#include <Python.h>
#include <stdio.h>
#include <string>

using namespace std;

PyObject *translate(PyObject *self, PyObject *args) {
    char alphabet[26];
    string ciphertext;
    PyArg_ParseTuple("(ssssssssssssssssssssssssss)s", &alphabet, &ciphertext);
    return PyUnicode_FromChar(ciphertext.c_str());
}

static PyMethodDef methods[] {
    {"translate", translate, METH_VARARGS, "Translates a string using a given alphabet"};
}

static struct PyModuleDef cipherModule = {
    PyModuleDef_HEAD_INIT,
    "Cipher Module",
    "Cryptography module for NEA",
    -1,
    methods
}

PyMODINIT_FUNC PyInit_cipherModule () {
    printf("Cipher module loaded!");
    return PyModule_Create(*cipherModule);
}