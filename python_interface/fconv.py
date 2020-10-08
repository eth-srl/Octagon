#
#
#  This source file is part of ELINA (ETH LIbrary for Numerical Analysis).
#  ELINA is Copyright © 2019 Department of Computer Science, ETH Zurich
#  This software is distributed under GNU Lesser General Public License Version 3.0.
#  For more information, see the ELINA project website at:
#  http://elina.ethz.ch
#
#  THE SOFTWARE IS PROVIDED "AS-IS" WITHOUT ANY WARRANTY OF ANY KIND, EITHER
#  EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO ANY WARRANTY
#  THAT THE SOFTWARE WILL CONFORM TO SPECIFICATIONS OR BE ERROR-FREE AND ANY
#  IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE,
#  TITLE, OR NON-INFRINGEMENT.  IN NO EVENT SHALL ETH ZURICH BE LIABLE FOR ANY
#  DAMAGES, INCLUDING BUT NOT LIMITED TO DIRECT, INDIRECT,
#  SPECIAL OR CONSEQUENTIAL DAMAGES, ARISING OUT OF, RESULTING FROM, OR IN
#  ANY WAY CONNECTED WITH THIS SOFTWARE (WHETHER OR NOT BASED UPON WARRANTY,
#  CONTRACT, TORT OR OTHERWISE).
#
#


from fconv_imports import *

import numpy as np
from ctypes import *
from enum import Enum


class MatDouble_c(Structure):
    _fields_ = [
        ('rows', c_int),
        ('cols', c_int),
        ('data', POINTER(c_double))
    ]


class MatInt_c(Structure):
    _fields_ = [
        ('rows', c_int),
        ('cols', c_int),
        ('data', POINTER(c_int))
    ]


new_MatDouble_c = fconv_api.new_MatDouble
new_MatDouble_c.argtype = [c_int, c_int, POINTER(c_double)]
new_MatDouble_c.restype = MatDouble_c

free_MatDouble_c = fconv_api.free_MatDouble
free_MatDouble_c.argtype = MatDouble_c
free_MatDouble_c.restype = None

free_MatInt_c = fconv_api.free_MatInt
free_MatInt_c.argtype = MatInt_c
free_MatInt_c.restype = None

fkrelu_c = fconv_api.fkrelu
fkrelu_c.argtype = [MatDouble_c]
fkrelu_c.restype = MatDouble_c

krelu_with_cdd_c = fconv_api.krelu_with_cdd
krelu_with_cdd_c.argtype = [MatDouble_c]
krelu_with_cdd_c.restype = MatDouble_c

fkpool_c = fconv_api.fkpool
fkpool_c.argtype = [MatDouble_c]
fkpool_c.restype = MatDouble_c

kpool_with_cdd_c = fconv_api.kpool_with_cdd
kpool_with_cdd_c.argtype = [MatDouble_c]
kpool_with_cdd_c.restype = MatDouble_c

fktanh_c = fconv_api.fktanh
fktanh_c.argtype = [MatDouble_c]
fktanh_c.restype = MatDouble_c

ktanh_with_cdd_c = fconv_api.ktanh_with_cdd
ktanh_with_cdd_c.argtype = [MatDouble_c]
ktanh_with_cdd_c.restype = MatDouble_c

generate_sparse_cover_c = fconv_api.generate_sparse_cover
generate_sparse_cover_c.argtype = [c_int, c_int]
generate_sparse_cover_c.restype = MatInt_c


def _compute_relaxation(inp_hrep: np.ndarray, activation: str, version: str) -> np.ndarray:
    """
    Input in format b + Ax >= 0. The input has to be octahedron in a certain format.
    An example of possible inp is:
        [0.4, 1, 0],
        [0.5, -1, 0],
        [0.25, 0, 1],
        [0.75, 0, -1]
    Which describes a system:
        x1  <= 0.4
        -x1 <= 0.5
        x2  <= 0.25
        -x2 <= 0.75
    """
    assert activation in ["relu", "pool", "tanh"]
    assert version in ["fast", "cdd"]

    rows, cols = inp_hrep.shape
    k = cols - 1
    assert k >= 1
    inp_hrep = inp_hrep.flatten().tolist()
    data_c = (c_double * (rows * cols))(*inp_hrep)

    inp_hrep = new_MatDouble_c(rows, cols, data_c)

    if activation == "relu" and version == "fast":
        out_hrep = fkrelu_c(inp_hrep)
    elif activation == "relu" and version == "cdd":
        out_hrep = krelu_with_cdd_c(inp_hrep)
    elif activation == "pool" and version == "fast":
        out_hrep = fkpool_c(inp_hrep)
    elif activation == "pool" and version == "cdd":
        out_hrep = kpool_with_cdd_c(inp_hrep)
    elif activation == "tanh" and version == "fast":
        out_hrep = fktanh_c(inp_hrep)
    elif activation == "tanh" and version == "cdd":
        out_hrep = ktanh_with_cdd_c(inp_hrep)
    else:
        raise Exception("Unknown activation/version", activation, version)

    out = [0] * (out_hrep.rows * out_hrep.cols)
    for i in range(out_hrep.rows * out_hrep.cols):
        out[i] = out_hrep.data[i]
    out = np.array(out)
    out = out.reshape(out_hrep.rows, out_hrep.cols)

    free_MatDouble_c(inp_hrep)
    free_MatDouble_c(out_hrep)

    return out


def fkrelu(inp_hrep: np.ndarray) -> np.ndarray:
    return _compute_relaxation(inp_hrep, "relu", "fast")


def krelu_with_cdd(inp_hrep: np.ndarray) -> np.ndarray:
    return _compute_relaxation(inp_hrep, "relu", "cdd")


def fkpool(inp_hrep: np.ndarray) -> np.ndarray:
    return _compute_relaxation(inp_hrep, "pool", "fast")


def kpool_with_cdd(inp_hrep: np.ndarray) -> np.ndarray:
    return _compute_relaxation(inp_hrep, "pool", "cdd")


def fktanh(inp_hrep: np.ndarray) -> np.ndarray:
    return _compute_relaxation(inp_hrep, "tanh", "fast")


def ktanh_with_cdd(inp_hrep: np.ndarray) -> np.ndarray:
    return _compute_relaxation(inp_hrep, "tanh", "cdd")


def generate_sparse_cover(n, k):
    cover_c = generate_sparse_cover_c(n, k)
    rows = cover_c.rows

    cover = []
    for i in range(rows):
        comb = [None] * k
        for j in range(k):
            comb[j] = cover_c.data[i * k + j]
        cover.append(comb)

    free_MatInt_c(cover_c)

    return cover
