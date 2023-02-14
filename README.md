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

While current Python documentation on extending Python still uses `distutils`, it's worth mentioning that `distutils` is being phased out and `setuptools` is [recommended](https://docs.python.org/3/distributing/index.html) as a replacement for `distutils`.

If you would like to use `setuptools`, simply change the following line in `setup.py`

```python
from distutils.core import setup, Extension
```

to

```python
from setuptools import setup, Extension
```
