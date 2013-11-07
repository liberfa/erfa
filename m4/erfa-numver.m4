
AC_DEFUN([ERFA_NUMVER],[
AS_VAR_PUSHDEF([MAJOR],[MAJOR_VERSION])dnl
AS_VAR_PUSHDEF([MINOR],[MINOR_VERSION])dnl
AS_VAR_PUSHDEF([MICRO],[MICRO_VERSION])dnl
AS_VAR_PUSHDEF([PATCH],[PATCH_VERSION])dnl
test ".$PACKAGE_VERSION" = "." && PACKAGE_VERSION="$VERSION"
AC_MSG_CHECKING([split $PACKAGE_VERSION])
  MINOR=`echo $PACKAGE_VERSION`
  MAJOR=`echo "$MINOR" | sed -e 's/[[.]].*//'`
  MINOR=`echo "$MINOR" | sed -e "s/^$MAJOR//" -e 's/^.//'`
  MICRO="$MINOR"
  MINOR=`echo "$MICRO" | sed -e 's/[[.]].*//'`
  MICRO=`echo "$MICRO" | sed -e "s/^$MINOR//" -e 's/^.//'`
  PATCH="$MICRO"
  MICRO=`echo "$PATCH" | sed -e 's/[[^0-9]].*//'`
  PATCH=`echo "$PATCH" | sed -e "s/^$MICRO//" -e 's/[[-.]]//'`
  if test "_$MICRO" = "_" ; then MICRO="0" ; fi
  if test "_$MINOR" = "_" ; then MINOR="$MAJOR" ; MAJOR="0" ; fi
  MINOR=`echo "$MINOR" | sed -e 's/[[^0-9]].*//'`
AC_MSG_RESULT([ $MAJOR $MINOR $MICRO $PATCH])
AC_DEFINE_UNQUOTED(PACKAGE_VERSION_MAJOR, $MAJOR, [Define to the major version of this package.])
AC_DEFINE_UNQUOTED(PACKAGE_VERSION_MINOR, $MINOR, [Define to the minor version of this package.])
AC_DEFINE_UNQUOTED(PACKAGE_VERSION_MICRO, $MICRO, [Define to the micro version of this package.])
AC_SUBST(PATCH)
AS_VAR_POPDEF([PATCH])dnl
AS_VAR_POPDEF([MICRO])dnl
AS_VAR_POPDEF([MINOR])dnl
AS_VAR_POPDEF([MAJOR])dnl
])

AC_DEFUN([ERFA_LIB_VERSION_INFO],[
m4_ifndef([ERFA_C], [m4_define([ERFA_C], [$1])])
m4_ifndef([ERFA_R], [m4_define([ERFA_R], [$2])])
m4_ifndef([ERFA_A], [m4_define([ERFA_A], [$3])])
m4_if(
  m4_ifdef([ERFA_C], [ok]):m4_ifdef([ERFA_R], [ok]):m4_ifdef([ERFA_A], [ok]),
    [ok:ok:ok],,
      [m4_fatal([ERFA_LIB_VERSION_INFO should be called with current, revision and age arguments])])dnl
AC_SUBST([VI_CURR], [m4_ifdef([ERFA_C], ['ERFA_C'])])dnl
AC_SUBST([VI_REL], [m4_ifdef([ERFA_R], ['ERFA_R'])])dnl
AC_SUBST([VI_AGE], [m4_ifdef([ERFA_A], ['ERFA_A'])])dnl
vi_all=`echo $VI_CURR:$VI_REL:$VI_AGE`
AC_SUBST([VI_ALL], [$vi_all])
])
