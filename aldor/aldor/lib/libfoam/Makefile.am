SUBDIRS = al

aldorsrcdir = $(top_srcdir)/aldor/src

runtime_CFLAGS = -I $(aldorsrcdir)

runtime_ALDOR = al/runtime.c
runtime_CSOURCES =			\
	btree.c		\
	compopt.c	\
	dword.c		\
	foam_c.c		\
	foam_cfp.c	\
	foamopt.c	\
	opsys.c		\
	output.c		\
	stdc.c		\
	store.c		\
	table.c		\
	timer.c		\
	util.c		\
	xfloat.c

AM_CFLAGS = -I$(aldorsrcdir) -DFOAM_RTS

lib_LIBRARIES =

$(runtime_CSOURCES): %.c: $(aldorsrcdir)/%.c
	cp $< $@

#############################################################################
# :: Built-in bigint
#############################################################################

lib_LIBRARIES += libfoam.a

libfoam_a_SOURCES =		\
	bigint.c		\
	foam_i.c		\
	$(runtime_ALDOR)	\
	$(runtime_CSOURCES)

bigint.c: $(aldorsrcdir)/bigint.c
	cp $< $@

foam_i.c: $(aldorsrcdir)/foam_i.c
	cp $< $@

#############################################################################
# :: GMP for bigint
#############################################################################

if GMP
lib_LIBRARIES += libfoam-gmp.a
endif

# TODO: get rid of bigint.c in here
libfoam_gmp_a_SOURCES =			\
	../../contrib/gmp/fm_gmp.c	\
	bigint.c		\
	$(runtime_ALDOR)		\
	$(runtime_CSOURCES)


#############################################################################
# :: Common portable byte-code library
#############################################################################

datalibdir = $(datadir)/lib
datalib_DATA = al/libfoam.al
