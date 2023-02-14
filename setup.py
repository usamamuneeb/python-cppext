"""
For a detailed description of this module file please read the
official Python documentation for "Extending Python" at

https://docs.python.org/3/extending

In the current version of documentation (3.11), section 4.1
covers the `setup.py` script.
"""

from distutils.core import setup, Extension

module1 = Extension('spam', sources = ['src/spam_module.cpp'])

"""
This is a minimal working example. For a complete list
of attributes that can be provided to the `setup()` function
and that comprises the metadata of the Python package, please
read the `distutils` API reference in the official Python
documentation:

https://docs.python.org/3/distutils/apiref.html#distutils.core.setup

Additionally, please see the README.md file if you would like
to use `setuptools` instead of `distutils`.
"""

with open("README.md", "r", encoding="utf-8") as fh:
    long_description = fh.read()

setup(
    name = 'python-cppext',
    version = '0.0.1',
    description = 'A minimal working example for extending a Python package with C++ code.',
    long_description=long_description,
    ext_modules = [module1]
)
