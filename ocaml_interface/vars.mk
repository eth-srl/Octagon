#
#
#  This source file is part of ELINA (ETH LIbrary for Numerical Analysis).
#  ELINA is Copyright © 2017 Department of Computer Science, ETH Zurich
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



MLAPRONDIR = $(APRON_SRCROOT)/mlapronidl

APRON_INCLUDE = $(APRON_PREFIX)/include
APRON_LIB = $(APRON_PREFIX)/lib
APRON_BIN = $(APRON_PREFIX)/bin

ifneq ($(OCAMLFIND),)
  MLGMPIDL_INCLUDE = $(shell $(OCAMLFIND) query gmp)
  MLGMPIDL_LIB = $(MLGMPIDL_INCLUDE)
else
  MLGMPIDL_INCLUDE = $(MLGMPIDL_PREFIX)/include
  MLGMPIDL_LIB = $(MLGMPIDL_PREFIX)/lib
endif

# IC/LI-FLAGS

ICFLAGS = $(CPPFLAGS)

APRON_ICFLAGS = -I$(APRON_SRCROOT)/apron
APRON_LIFLAGS = -L$(APRON_SRCROOT)/apron
APRON_CMXSINC = -I $(APRON_SRCROOT)/apron
NUM_ICFLAGS = -I$(APRON_SRCROOT)/num
NUM_LIFLAGS =
ITV_ICFLAGS = -I$(APRON_SRCROOT)/itv
ITV_LIFLAGS =

MP_ICFLAGS =
MP_LIFLAGS =
ifneq ($(GMP_PREFIX),)
  MP_ICFLAGS += -I$(GMP_PREFIX)/include
  MP_LIFLAGS += -L$(GMP_PREFIX)/lib
endif
ifneq ($(MPFR_PREFIX),)
  ifneq ($(MPFR_PREFIX),$(GMP_PREFIX))
    MP_ICFLAGS += -I$(MPFR_PREFIX)/include
    MP_LIFLAGS += -L$(MPFR_PREFIX)/lib
  endif
endif

BASE_ICFLAGS = $(APRON_ICFLAGS) $(NUM_ICFLAGS) $(ITV_ICFLAGS) $(MP_ICFLAGS)
BASE_LIFLAGS = $(APRON_LIFLAGS) $(NUM_LIFLAGS) $(ITV_LIFLAGS) $(MP_LIFLAGS)

ML_ICFLAGS =
OCAMLINC =
ifneq ($(HAS_OCAML),)
  ML_ICFLAGS += -I$(MLGMPIDL_INCLUDE) -I$(APRON_SRCROOT)/mlapronidl \
		-I$(CAMLIDL_PREFIX) -I$(CAML_PREFIX)
  OCAMLINC   += -I $(MLGMPIDL_LIB) -I $(APRON_SRCROOT)/mlapronidl
endif

PPL_ICFLAGS =
PPL_LIFLAGS =
ifneq ($(PPL_PREFIX),)
  PPL_ICFLAGS += -I$(PPL_PREFIX)/include
  PPL_LIFLAGS += -L$(PPL_PREFIX)lib
endif

# ---

OCAMLOPT_TARGETS0 = $(addsuffix .cmxa, $(1)) $(addsuffix .a, $(1))

ifneq ($(HAS_SHARED),)
  CC_APRON_DYLIB = $(CC) -shared
  CXX_APRON_DYLIB = $(CXX) -shared
  ifneq ($(HAS_OCAML),)
    OCAMLMKLIB := $(OCAMLMKLIB) -dllpath $(APRON_LIB)
    OCAMLMKLIB := $(OCAMLMKLIB) -L$(APRON_LIB)
  endif
  ifneq ($(ABSOLUTE_DYLIB_INSTALL_NAMES),)
    CC_APRON_DYLIB += -install_name $(APRON_LIB)/$@
    CXX_APRON_DYLIB += -install_name $(APRON_LIB)/$@
  endif
  ifneq ($(HAS_NATIVE_PLUGINS),)
    OCAMLOPT_CMXS = $(OCAMLOPT) $(OCAMLOPTFLAGS) -linkall -shared
    OCAMLOPT_TARGETS = $(call OCAMLOPT_TARGETS0,$(1)) $(addsuffix .cmxs, $(1))
  else
    OCAMLOPT_TARGETS = $(call OCAMLOPT_TARGETS0,$(1))
  endif
endif

OCAMLPACK := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))ocamlpack
