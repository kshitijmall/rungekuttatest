# distutils: define_macros=CYTHON_TRACE_NOGIL=1
from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize
import numpy as np
import Cython

#This will generate HTML to show where there are still pythonic bits hiding out
Cython.Compiler.Options.annotate = True

ext_modules = [
    Extension("rk4new",
              sources=["rk4.pyx"],
              libraries=["m"]  # Unix-like specific
              )
]

setup(name="rk4project",
      ext_modules=cythonize(['rk4.pyx']),
      include_dirs=[np.get_include()]
)
