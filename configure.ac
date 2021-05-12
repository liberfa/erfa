# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
## Follow the instructions in RELEASE.rst to change package version
AC_INIT([erfa],[2.0.0])
AC_CONFIG_SRCDIR([src/erfa.h])
AC_CONFIG_HEADER([config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([foreign])

AC_PROG_CC
LT_INIT

ERFA_NUMVER
## Version info is in current : revision : age form
## A library supports interfaces from current downto current - age
## Revision is the version of the current interface
## Follow the instructions in RELEASE.rst to change the version info
ERFA_LIB_VERSION_INFO(9, 0, 8)

## SOFA version, update if needed in new relases
AC_DEFINE([SOFA_VERSION], ["20210512"], [Define to the version of SOFA])

# Checks for libraries.
AC_SEARCH_LIBS([sin], [m], , AC_MSG_ERROR([cannot find math functions]))

AC_CONFIG_FILES([Makefile
                 erfa.pc
                 src/Makefile
])
AC_OUTPUT
