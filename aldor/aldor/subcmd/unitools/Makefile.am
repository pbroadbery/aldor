# Aldor portability layer
noinst_LIBRARIES = libport.a
s = $(srcdir)/../../src

libport_a_CFLAGS = -I $s

libport_a_SOURCES =	\
	bigint.c	\
	btree.c	\
	buffer.c	\
	cfgfile.c	\
	compopt.c	\
	debug.c	\
	dword.c	\
	file.c	\
	fluid.c	\
	fname.c	\
	format.c	\
	int.c	\
	list.c	\
	memclim.c	\
	opsys.c	\
	ostream.c	\
	stdc.c	\
	store.c	\
	strops.c	\
	timer.c	\
	util.c	\
	xfloat.c

$(libport_a_SOURCES): %.c: $s/%.c
	cp $< $@

# C compiler driver
bin_PROGRAMS = unicl

unicl_SOURCES = unicl.c
unicl_LDADD = libport.a -lm
unicl_CFLAGS = -I $s $(AM_CFLAGS)


# Print platform information
noinst_PROGRAMS = platform

platform_CFLAGS = -I $s $(AM_CFLAGS)
