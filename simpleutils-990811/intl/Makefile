# Generated automatically from Makefile.in by configure.
# Makefile for directory with message catalog handling in GNU NLS Utilities.
# Copyright (C) 1995, 1996, 1997, 1998 Free Software Foundation, Inc.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

PACKAGE = @PACKAGE@
VERSION = @VERSION@

SHELL = /bin/sh

srcdir = .
top_srcdir = .
top_builddir = ..

prefix = /home/honey/simplescalar
exec_prefix = ${prefix}
transform = s,x,x,
libdir = $(exec_prefix)/lib
includedir = $(prefix)/include
datadir = $(prefix)/share
localedir = $(datadir)/locale
gnulocaledir = $(prefix)/share/locale
gettextsrcdir = ${prefix}/share/gettext/intl
aliaspath = $(localedir):.
subdir = intl

INSTALL = /usr/bin/install -c
INSTALL_DATA = ${INSTALL} -m 644
MKINSTALLDIRS = $(srcdir)/../../mkinstalldirs

l = 

AR = ar
CC = gcc
LIBTOOL = @LIBTOOL@
RANLIB = ranlib

DEFS = -DLOCALEDIR=\"$(localedir)\" -DGNULOCALEDIR=\"$(gnulocaledir)\" \
-DLOCALE_ALIAS_PATH=\"$(aliaspath)\" -DHAVE_CONFIG_H
CPPFLAGS = 
CFLAGS = -g -O2 -W -Wall
LDFLAGS = 

COMPILE = $(CC) -c $(DEFS) $(INCLUDES) $(CPPFLAGS) $(CFLAGS) $(XCFLAGS)

HEADERS = $(COMHDRS) libgettext.h loadinfo.h
COMHDRS = gettext.h gettextP.h hash-string.h
SOURCES = $(COMSRCS) intl-compat.c cat-compat.c
COMSRCS = bindtextdom.c dcgettext.c dgettext.c gettext.c \
finddomain.c loadmsgcat.c localealias.c textdomain.c l10nflist.c \
explodename.c
OBJECTS = $(GETTOBJS) bindtextdom.$lo dcgettext.$lo dgettext.$lo gettext.$lo \
finddomain.$lo loadmsgcat.$lo localealias.$lo textdomain.$lo l10nflist.$lo \
explodename.$lo
CATOBJS = cat-compat.$lo ../po/cat-id-tbl.$lo
GETTOBJS = intl-compat.$lo
DISTFILES.common = ChangeLog Makefile.in linux-msg.sed po2tbl.sed.in \
xopen-msg.sed $(HEADERS) $(SOURCES)
DISTFILES.normal = VERSION
DISTFILES.gettext = libintl.glibc intlh.inst.in

.SUFFIXES:
.SUFFIXES: .c .o .lo
.c.o:
	$(COMPILE) $<
.c.lo:
	$(LIBTOOL) --mode=compile $(COMPILE) $<

INCLUDES = -I. -I$(srcdir)

all: all-yes

all-yes: libintl.$la intlh.inst
all-no:
install-info:

libintl.a: $(OBJECTS)
	rm -f $@
	$(AR) cru $@ $(OBJECTS)
	$(RANLIB) $@

libintl.la: $(OBJECTS)
	$(LIBTOOL) --mode=link $(CC) $(LDFLAGS) -o $@ $(OBJECTS) \
		   -version-info 1:0 -rpath $(libdir)

../po/cat-id-tbl.$lo: ../po/cat-id-tbl.c $(top_srcdir)/po/$(PACKAGE).pot
	cd ../po && $(MAKE) cat-id-tbl.$lo

check: all

# This installation goal is only used in GNU gettext.  Packages which
# only use the library should use install instead.

# We must not install the libintl.h/libintl.a files if we are on a
# system which has the gettext() function in its C library or in a
# separate library or use the catgets interface.  A special case is
# where configure found a previously installed GNU gettext library.
# If you want to use the one which comes with this version of the
# package, you have to use `configure --with-included-gettext'.
install: install-exec install-data
install-exec: all
	if test "$(PACKAGE)" = "gettext" \
	   && test '$(GETTOBJS)' = '$(GETTOBJS)'; then \
	  if test -r $(MKINSTALLDIRS); then \
	    $(MKINSTALLDIRS) $(libdir) $(includedir); \
	  else \
	    $(top_srcdir)/mkinstalldirs $(libdir) $(includedir); \
	  fi; \
	  $(INSTALL_DATA) intlh.inst $(includedir)/libintl.h; \
	  $(INSTALL_DATA) libintl.a $(libdir)/libintl.a; \
	else \
	  : ; \
	fi
install-data: all
	if test "$(PACKAGE)" = "gettext"; then \
	  if test -r $(MKINSTALLDIRS); then \
	    $(MKINSTALLDIRS) $(gettextsrcdir); \
	  else \
	    $(top_srcdir)/mkinstalldirs $(gettextsrcdir); \
	  fi; \
	  $(INSTALL_DATA) VERSION $(gettextsrcdir)/VERSION; \
	  dists="$(DISTFILES.common)"; \
	  for file in $$dists; do \
	    $(INSTALL_DATA) $(srcdir)/$$file $(gettextsrcdir)/$$file; \
	  done; \
	else \
	  : ; \
	fi

# Define this as empty until I found a useful application.
installcheck:

uninstall:
	dists="$(DISTFILES.common)"; \
	for file in $$dists; do \
	  rm -f $(gettextsrcdir)/$$file; \
	done

info dvi:

$(OBJECTS): config.h libgettext.h
bindtextdom.$lo finddomain.$lo loadmsgcat.$lo: gettextP.h gettext.h loadinfo.h
dcgettext.$lo: gettextP.h gettext.h hash-string.h loadinfo.h

tags: TAGS

TAGS: $(HEADERS) $(SOURCES)
	here=`pwd`; cd $(srcdir) && etags -o $$here/TAGS $(HEADERS) $(SOURCES)

id: ID

ID: $(HEADERS) $(SOURCES)
	here=`pwd`; cd $(srcdir) && mkid -f$$here/ID $(HEADERS) $(SOURCES)


mostlyclean:
	rm -f *.a *.o *.lo core core.*

clean: mostlyclean

distclean: clean
	rm -f Makefile ID TAGS po2msg.sed po2tbl.sed libintl.h config.log

maintainer-clean: distclean
	@echo "This command is intended for maintainers to use;"
	@echo "it deletes files that may require special tools to rebuild."


# GNU gettext needs not contain the file `VERSION' but contains some
# other files which should not be distributed in other packages.
distdir = ../$(PACKAGE)-$(VERSION)/$(subdir)
dist distdir: Makefile $(DISTFILES)
	if test "$(PACKAGE)" = gettext; then \
	  additional="$(DISTFILES.gettext)"; \
	else \
	  additional="$(DISTFILES.normal)"; \
	fi; \
	for file in $(DISTFILES.common) $$additional; do \
	  ln $(srcdir)/$$file $(distdir) 2> /dev/null \
	    || cp -p $(srcdir)/$$file $(distdir); \
	done

dist-libc:
	tar zcvf intl-glibc.tar.gz $(COMSRCS) $(COMHDRS) libintl.h.glibc

Makefile: Makefile.in config.status
	CONFIG_FILES=$@ CONFIG_HEADERS= $(SHELL) ./config.status

# The dependency for intlh.inst is different in gettext and all other
# packages.  Because we cannot you GNU make features we have to solve
# the problem while rewriting Makefile.in.
#YES#intlh.inst: intlh.inst.in ../config.status
#YES#	cd .. \
#YES#	&& CONFIG_FILES=$(subdir)/$@ CONFIG_HEADERS= \
#YES#	  $(SHELL) ./config.status
.PHONY: intlh.inst
intlh.inst:

# Tell versions [3.59,3.63) of GNU make not to export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
