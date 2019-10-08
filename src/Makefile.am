lib_LTLIBRARIES = liberfa.la
include Makefile.part

include_HEADERS = erfa.h erfam.h erfaextra.h

## Version info is in current : revision : age form
## A library supports interfaces from current downto current - age
## Revision is the version of the current interface

## VI_ALL is set in the macro ERFA_LIB_VERSION_INFO in configure.ac

liberfa_la_LDFLAGS = -version-info $(VI_ALL)


## Check program
TESTS = t_erfa_c
check_PROGRAMS = t_erfa_c
t_erfa_c_SOURCES = t_erfa_c.c
AM_CPPFLAGS = -I$(top_srcdir)
LDADD = $(top_builddir)/src/liberfa.la
