/*
** Copyright (C) 2016-2017, NumFOCUS Foundation.
**
** Licensed under a 3-clause BSD style license - see LICENSE 
**
** This file is NOT derived from SOFA sources
*/


#ifdef HAVE_CONFIG_H
#include <config.h>
#endif /* HAVE_CONFIG_H */


const char* eraVersion(void) {
  return PACKAGE_VERSION;
}


int eraVersionMajor(void) {
  return PACKAGE_VERSION_MAJOR;
}


int eraVersionMinor(void) {
  return PACKAGE_VERSION_MINOR;
}


int eraVersionMicro(void) {
  return PACKAGE_VERSION_MICRO;
}


const char* eraSofaVersion(void) {
  return SOFA_VERSION;
}

