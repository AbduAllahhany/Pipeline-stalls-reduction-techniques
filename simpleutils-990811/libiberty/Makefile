# Generated automatically from Makefile.in by configure.
#
# Makefile
#   Copyright (C) 1990, 91, 92, 93, 94, 95, 96, 97, 1998
#   Free Software Foundation
#
# This file is part of the libiberty library.
# Libiberty is free software; you can redistribute it and/or
# modify it under the terms of the GNU Library General Public
# License as published by the Free Software Foundation; either
# version 2 of the License, or (at your option) any later version.
#
# Libiberty is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Library General Public License for more details.
#
# You should have received a copy of the GNU Library General Public
# License along with libiberty; see the file COPYING.LIB.  If not,
# write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
# Boston, MA 02111-1307, USA.
#

# This file was written by K. Richard Pixley <rich@cygnus.com>.

#
# Makefile for libiberty directory
#

srcdir = .

prefix = /home/honey/simplescalar

exec_prefix = ${prefix}
bindir = ${exec_prefix}/bin
libdir = ${exec_prefix}/lib

SHELL = /bin/sh

# Multilib support variables.
MULTISRCTOP =
MULTIBUILDTOP =
MULTIDIRS =
MULTISUBDIR =
MULTIDO = true
MULTICLEAN = true

INSTALL = /usr/bin/install -c
INSTALL_PROGRAM = ${INSTALL}
INSTALL_DATA = ${INSTALL} -m 644

AR = ar
AR_FLAGS = rc

CC = gcc
CFLAGS = -g -O2 -W -Wall
LIBCFLAGS = $(CFLAGS)
RANLIB = ranlib

PICFLAG =

MAKEOVERRIDES =

TARGETLIB = libiberty.a

LIBOBJS = 
ALLOCA = 

# A configuration can specify extra .o files that should be included,
# even if they are in libc. (Perhaps the libc version is buggy.)
EXTRA_OFILES = 

# Flags to pass to a recursive make.
FLAGS_TO_PASS = \
	"AR=$(AR)" \
	"AR_FLAGS=$(AR_FLAGS)" \
	"CC=$(CC)" \
	"CFLAGS=$(CFLAGS)" \
	"LIBCFLAGS=$(LIBCFLAGS)" \
	"EXTRA_OFILES=$(EXTRA_OFILES)" \
	"HDEFINES=$(HDEFINES)" \
	"INSTALL=$(INSTALL)" \
	"INSTALL_DATA=$(INSTALL_DATA)" \
	"INSTALL_PROGRAM=$(INSTALL_PROGRAM)" \
	"LDFLAGS=$(LDFLAGS)" \
	"LOADLIBES=$(LOADLIBES)" \
	"RANLIB=$(RANLIB)" \
	"SHELL=$(SHELL)"

all: stamp-picdir $(TARGETLIB) needed-list required-list
	@$(MULTIDO) $(FLAGS_TO_PASS) multi-do DO=all

.PHONY: check installcheck
check installcheck:


# Warning: this fragment is automatically generated
enable_shared = no

INCDIR=$(srcdir)/$(MULTISRCTOP)../include

COMPILE.c = $(CC) -c -DHAVE_CONFIG_H $(LIBCFLAGS) -I. -I$(INCDIR) $(HDEFINES)
.c.o:
	test x"$(enable_shared)" != xyes || \
	  $(COMPILE.c) $(PICFLAG) $< -o pic/$@
	$(COMPILE.c) $<

info install-info clean-info dvi:

# Include files that are in this directory.
HFILES = alloca-conf.h

# NOTE: If you add new files to the library, add them to this list
# (alphabetical), and add them to REQUIRED_OFILES or funcs in
# configure.in.
CFILES = asprintf.c alloca.c argv.c atexit.c basename.c bcmp.c bcopy.c \
	bzero.c choose-temp.c clock.c concat.c cplus-dem.c fdmatch.c \
	fnmatch.c getcwd.c getopt.c getopt1.c getpagesize.c \
	getruntime.c floatformat.c hex.c index.c insque.c memchr.c \
	memcmp.c memcpy.c memmove.c memset.c mkstemps.c objalloc.c obstack.c \
	pexecute.c random.c rename.c rindex.c sigsetmask.c spaces.c \
	splay-tree.c strcasecmp.c strncasecmp.c strchr.c strdup.c strerror.c \
	strrchr.c strsignal.c strstr.c strtod.c strtol.c strtoul.c \
	tmpnam.c vasprintf.c vfork.c vfprintf.c vprintf.c vsprintf.c \
	waitpid.c xatexit.c xexit.c xmalloc.c xstrdup.c xstrerror.c

# These are always included in the library.
REQUIRED_OFILES = argv.o choose-temp.o concat.o cplus-dem.o \
  fdmatch.o fnmatch.o getopt.o getopt1.o getruntime.o hex.o \
  floatformat.o objalloc.o obstack.o pexecute.o spaces.o \
  splay-tree.o strerror.o strsignal.o xatexit.o xexit.o xmalloc.o \
  xstrdup.o xstrerror.o

$(TARGETLIB): $(REQUIRED_OFILES) $(EXTRA_OFILES) $(LIBOBJS) $(ALLOCA)
	rm -f $(TARGETLIB)
	$(AR) $(AR_FLAGS) $(TARGETLIB) \
	  $(REQUIRED_OFILES) $(EXTRA_OFILES) $(LIBOBJS) $(ALLOCA)
	$(RANLIB) $(TARGETLIB)

INSTALL_DEST = libdir
install: install_to_$(INSTALL_DEST)

install_to_libdir: all
	$(INSTALL_DATA) $(TARGETLIB) $(libdir)$(MULTISUBDIR)/$(TARGETLIB)n
	( cd $(libdir)$(MULTISUBDIR) ; $(RANLIB) $(TARGETLIB)n )
	mv -f $(libdir)$(MULTISUBDIR)/$(TARGETLIB)n $(libdir)$(MULTISUBDIR)/$(TARGETLIB)
	@$(MULTIDO) $(FLAGS_TO_PASS) multi-do DO=install

install_to_tooldir: all
	$(INSTALL_DATA) $(TARGETLIB) $(tooldir)/lib$(MULTISUBDIR)/$(TARGETLIB)n
	( cd $(tooldir)/lib$(MULTISUBDIR) ; $(RANLIB) $(TARGETLIB)n )
	mv -f $(tooldir)/lib$(MULTISUBDIR)/$(TARGETLIB)n $(tooldir)/lib$(MULTISUBDIR)/$(TARGETLIB)
	@$(MULTIDO) $(FLAGS_TO_PASS) multi-do DO=install

# needed-list is used by libstdc++.
needed-list: Makefile
	f="$(LIBOBJS) $(ALLOCA) $(EXTRA_OFILES)"; \
	case $$f in \
	  *alloca.o*) f="$$f xmalloc.o xexit.o" ;; \
	esac; \
	echo $$f > needed-list

# required-list was used when building a shared bfd/opcodes/libiberty
# library.  I don't know if it used by anything currently.
required-list: Makefile
	echo $(REQUIRED_OFILES) > required-list

stamp-picdir:
	if [ x"$(enable_shared)" = xyes ] && [ ! -d pic ]; then \
	  mkdir pic; \
	else true; fi
	touch stamp-picdir

.PHONY: all etags tags ls clean stage1 stage2

etags tags: TAGS

TAGS: $(CFILES) $(HFILES)
	etags `for i in $(HFILES) $(CFILES); do echo $(srcdir)/$$i ; done`

# The standalone demangler (c++filt) has been moved to binutils.
demangle:
	@echo "The standalone demangler, now named c++filt, is now"
	@echo "a part of binutils."
	@false

ls:
	@echo Makefile $(HFILES) $(CFILES)

# Need to deal with profiled libraries, too.

mostlyclean:
	rm -rf *.o pic core errs \#* *.E a.out
	rm -f needed.awk needed2.awk errors dummy needed-list config.h stamp-*
	rm -f $(CONFIG_H) $(NEEDED_LIST) stamp-picdir
	@$(MULTICLEAN) multi-clean DO=mostlyclean
clean: mostlyclean
	rm -f *.a required-list tmpmulti.out
	@$(MULTICLEAN) multi-clean DO=clean
distclean: clean
	@$(MULTICLEAN) multi-clean DO=distclean
	rm -f *~ Makefile config.status xhost-mkfrag TAGS multilib.out
	rm -f config.log
maintainer-clean realclean: distclean

force:

Makefile: $(srcdir)/Makefile.in config.status
	CONFIG_FILES=Makefile CONFIG_HEADERS= $(SHELL) ./config.status

config.h: stamp-h ; @true
stamp-h: config.in config.status
	CONFIG_FILES= CONFIG_HEADERS=config.h:config.in $(SHELL) ./config.status

config.status: $(srcdir)/configure $(srcdir)/config.table
	$(SHELL) ./config.status --recheck

$(REQUIRED_OFILES) $(EXTRA_OFILES) $(LIBOBJS) $(ALLOCA): stamp-picdir

alloca.o: config.h
atexit.o: config.h
argv.o: config.h alloca-conf.h $(INCDIR)/libiberty.h
basename.o: $(INCDIR)/libiberty.h
choose-temp.o: config.h
clock.o: config.h
concat.o: $(INCDIR)/libiberty.h
cplus-dem.o: config.h $(INCDIR)/demangle.h
fdmatch.o: $(INCDIR)/libiberty.h
fnmatch.o: config.h $(INCDIR)/fnmatch.h
getcwd.o: config.h
getopt.o: config.h $(INCDIR)/getopt.h
getopt1.o: config.h $(INCDIR)/getopt.h
getpagesize.o: config.h
getruntime.o: config.h $(INCDIR)/libiberty.h
hex.o: $(INCDIR)/libiberty.h
floatformat.o: $(INCDIR)/floatformat.h
mkstemps.o: config.h
objalloc.o: $(INCDIR)/objalloc.h
obstack.o: config.h $(INCDIR)/obstack.h
pexecute.o: config.h $(INCDIR)/libiberty.h
spaces.o: $(INCDIR)/libiberty.h
splay-tree.o: config.h $(INCDIR)/libiberty.h $(INCDIR)/splay-tree.h $(INCDIR)/ansidecl.h
strerror.o: config.h $(INCDIR)/libiberty.h
strsignal.o: config.h $(INCDIR)/libiberty.h
xatexit.o: $(INCDIR)/libiberty.h
xexit.o: $(INCDIR)/libiberty.h
xmalloc.o: $(INCDIR)/libiberty.h
xstrdup.o: config.h $(INCDIR)/libiberty.h
xstrerror.o: config.h $(INCDIR)/libiberty.h
