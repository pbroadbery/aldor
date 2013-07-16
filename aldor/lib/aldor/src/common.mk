aldorincdir	:= $(top_srcdir)/lib/aldor/include
aldorlibdir	:= $(top_builddir)/lib/aldor/src

libraryincdir	:= $(top_srcdir)/lib/aldor/include
librarylibdir	:= $(top_builddir)/lib/aldor/src

libraryname	:= aldor

#AXLCDB		:= -W check -Csmax=0 -Fc -Zdb -Qno-cc
AXLFLAGS	:= -Z db -Fc -Q9 -Qinline-all $(AXLCDB)

include $(srcdir)/Makefile.deps
include $(top_srcdir)/lib/buildlib.mk
