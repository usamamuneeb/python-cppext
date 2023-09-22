# Minimal Python C++ Extension

This repository serves as a minimal working example for extending a Python package with C++ code.

This repository complements the official Python documentation on [extending Python](https://docs.python.org/3/extending).

## Installation

Simply clone this repository, `cd` inside it and run

```bash
python setup.py install
```

## Usage

```python
import spam
spam.system("ls -al")
```

## Note regarding `distutils`

Currently, as of version 3.11 [Python documentation](https://docs.python.org/3.11/extending/building.html#building-c-and-c-extensions-with-distutils) still uses `distutils`. It's worth mentioning that direct usage of `distutils` is being phased out and `setuptools` is [recommended](https://docs.python.org/3.10/distributing/index.html) as a replacement for `distutils`.

If you would like to use `setuptools`, simply change the following line in `setup.py`

```python
from distutils.core import setup, Extension
```

to

```python
from setuptools import setup, Extension
```
