# Creating a Python module using CPP

## Setup.py

Copy the code below into a Python file:
```python
from distutils.core import setup, Extension

def main():
    setup(name="test module",
          description="Python test module coded in C++",
          ext_modules=[Extension(""MODULENAME"", ["FILENAME.cpp"])])

if __name__ == "__main__":
    main()
```

**Replace MODULENAME and FILENAME with the corresponding values**

## The main module file

- Create a new CPP file

- Create an initialse function
```c++
#include <stdio.h>

PyMODINIT_FUNC PyInit_testModule () {
    printf("This message prints into the console when the method is imported\n");
    return NULL
};
```

- Define the module, setting the MODULENAME and MODULEDOC
```c++
#include <Python.h>

static struct PyModuleDef testModule = {
    PyModuleDef_HEAD_INIT,
    "MODULENAME",
    "MODULEDOC",
    -1
};
```

- Edit the PyInit function to include the testModule struct
```c++
PyMODINIT_FUNC PyInit_testModule () {
    printf("This message prints into the console when the method is imported\n");
    return PyModule_Create(&testmodule);
};
```

- Create your module's first method
```c++
PyObject *exampleAdd(PyObject *self, PyObject *args) {
    int x;
    int y;
    PyArg_ParseTuple(args, "ii", &x, &y); // "ii" refers to two integer arguments - more information can be found in Python docs
    int result = x + y;
    return PyLong_FromLong((long) (result));
};
```

- Create a struct which stores the method, as well as any future methods
```c++
static PyMethodDef methods[] {
    { "example_add", exampleAdd, METH_VARARGS, "Adds two numbers together" },
    { NULL, NULL, 0, NULL }
};
```

- Edit the testModule struct to include the new methods struct
```c++
static struct PyModuleDef testModule = {
    PyModuleDef_HEAD_INIT,
    "MODULENAME",
    "MODULEDOC",
    -1,
    methods
};
```

- All done!

## Compiling the CPP code into a fully functioning module

Simply run `python setup.py install` in powershell and the module will install itself and will be ready to use in Python

## VSCode include error:

- Hover over the red underline on `#include <Python.h>`
- Select Quick Fix > Edit include path setting
- Go to `.vscode/c_cpp_properties.json`
- Add `"C:/Users/USERNAME/AppData/Local/Programs/Python/Python310/include"` to `includePath`
- Ensure to save the file
- Issue should be resolved!

## Recompiling

**Make sure to delete the testmodule.egg-info file before recompiling to avoid errors**