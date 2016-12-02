#include <config.h>

const char* eraVersion() {

  return PACKAGE_VERSION;

}

int eraVersionMajor() {

  return PACKAGE_VERSION_MAJOR;
}

int eraVersionMinor() {

  return PACKAGE_VERSION_MINOR;
}

int eraVersionMicro() {

  return PACKAGE_VERSION_MICRO;
}
