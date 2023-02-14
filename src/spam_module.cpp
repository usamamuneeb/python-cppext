/*
For a detailed description of this module file please read the
official Python documentation for "Extending Python" at

https://docs.python.org/3/extending

In the current version of documentation (3.11), sections 1.1-1.4
describe the role of each component in this file.

Please skip 1.5 which describes how to rebuild CPython and
make this module a permanent part of it. In our tutorial, we
use dynamic linking where this is compiled as a dynamic library
(.so or .dll file) and loaded in Python only if the use imports
the `spam` package.
*/

#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject *
spam_system(PyObject *self, PyObject *args)
{
    const char *command;
    int sts;

    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;
    sts = system(command);
    return PyLong_FromLong(sts);
}

static PyMethodDef SpamMethods[] = {
    {
        "system", /* this will be the name of the method in Python */
        spam_system,
        METH_VARARGS,
        "Execute a shell command."
    },
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

static struct PyModuleDef spammodule = {
    PyModuleDef_HEAD_INIT,
    "spam",     /* name of module */
    NULL,       /* module documentation, may be NULL */
    -1,         /* size of per-interpreter state of the module,
                or -1 if the module keeps state in global variables. */
    SpamMethods
};

PyMODINIT_FUNC
PyInit_spam(void)
{
    return PyModule_Create(&spammodule);
}
