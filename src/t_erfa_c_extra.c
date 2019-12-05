/*
** Copyright (C) 2019, NumFOCUS Foundation.
**
** Licensed under a 3-clause BSD style license - see LICENSE
**
** This file is NOT derived from SOFA sources.
*/

#include <stdio.h>
#include <string.h>
#include <erfa.h>
#include <erfaextra.h>

static int verbose = 0;

/*
**
**  Validate the ERFA C functions that are not derived from SOFA (SOFA-derived tests are in t_erfa_c)
**
*/

static void viv(int ival, int ivalok,
                const char *func, const char *test, int *status)
/*
**  - - - -
**   v i v
**  - - - -
**
**  Validate an integer result.
**
**  Internal function used by t_erfa_c program.
**
**  Given:
**     ival     int          value computed by function under test
**     ivalok   int          correct value
**     func     char[]       name of function under test
**     test     char[]       name of individual test
**
**  Given and returned:
**     status   int          set to TRUE if test fails
**
**  This revision:  2013 August 7
*/
{
   if (ival != ivalok) {
      *status = 1;
      printf("%s failed: %s want %d got %d\n",
             func, test, ivalok, ival);
   } else if (verbose) {
      printf("%s passed: %s want %d got %d\n",
                    func, test, ivalok, ival);
   }

}

static void vvd(double val, double valok, double dval,
                const char *func, const char *test, int *status)
/*
**  - - - -
**   v v d
**  - - - -
**
**  Validate a double result.
**
**  Internal function used by t_erfa_c program.
**
**  Given:
**     val      double       value computed by function under test
**     valok    double       expected value
**     dval     double       maximum allowable error
**     func     char[]       name of function under test
**     test     char[]       name of individual test
**
**  Given and returned:
**     status   int          set to TRUE if test fails
**
**  This revision:  2016 April 21
*/
{
   double a, f;   /* absolute and fractional error */


   a = val - valok;
   if (a != 0.0 && fabs(a) > fabs(dval)) {
      f = fabs(valok / a);
      *status = 1;
      printf("%s failed: %s want %.20g got %.20g (1/%.3g)\n",
             func, test, valok, val, f);
   } else if (verbose) {
      printf("%s passed: %s want %.20g got %.20g\n",
             func, test, valok, val);
   }

}


static void t_versions(int *status)
/*
**  Test that the version-checking functions yield something.
*/
{
  char buf[3];
  char* res;
  const char* version_str = eraVersion();

  sprintf(buf, "%d", eraVersionMajor());
  res = strstr(version_str, buf);
  if (!res) {
    *status = 1;
    printf("t_versions failed - major version %d not in version string %s\n", res, version_str);
  }

  sprintf(buf, "%d", eraVersionMinor());
  res = strstr(version_str, buf);
  if (!res) {
    *status = 1;
    printf("t_versions failed - minor version %d not in version string %s\n", res, version_str);
  }

  sprintf(buf, "%d", eraVersionMicro());
  res = strstr(version_str, buf);
  if (!res) {
    *status = 1;
    printf("t_versions failed - micro version %d not in version string %s\n", res, version_str);
  }

  if (*status == 0) {
    printf("t_versions passed");
  }

}

static void t_leap_seconds(int *status)
/*
**  Test that the leap-second machinery yields something
*/
{

}

int main(int argc, char *argv[])
{
   int status;


/* If any command-line argument, switch to verbose reporting. */
   if (argc > 1) {
      verbose = 1;
      argv[0][0] += 0;    /* to avoid compiler warnings */
   }

/* Preset the &status to FALSE = success. */
   status = 0;

/* Test all of the extra functions. */
   t_versions(&status);
   t_leap_seconds(&status);

/* Report, set up an appropriate exit status, and finish. */
   if (status) {
      printf("t_erfa_c_extra validation failed!\n");
   } else {
      printf("t_erfa_c_extra validation successful\n");
   }
   return status;
}
/*----------------------------------------------------------------------
**  
**  
**  Copyright (C) 2013-2019, NumFOCUS Foundation.
**  All rights reserved.
**  
**  This library is derived, with permission, from the International
**  Astronomical Union's "Standards of Fundamental Astronomy" library,
**  available from http://www.iausofa.org.
**  
**  The ERFA version is intended to retain identical functionality to
**  the SOFA library, but made distinct through different function and
**  file names, as set out in the SOFA license conditions.  The SOFA
**  original has a role as a reference standard for the IAU and IERS,
**  and consequently redistribution is permitted only in its unaltered
**  state.  The ERFA version is not subject to this restriction and
**  therefore can be included in distributions which do not support the
**  concept of "read only" software.
**  
**  Although the intent is to replicate the SOFA API (other than
**  replacement of prefix names) and results (with the exception of
**  bugs;  any that are discovered will be fixed), SOFA is not
**  responsible for any errors found in this version of the library.
**  
**  If you wish to acknowledge the SOFA heritage, please acknowledge
**  that you are using a library derived from SOFA, rather than SOFA
**  itself.
**  
**  
**  TERMS AND CONDITIONS
**  
**  Redistribution and use in source and binary forms, with or without
**  modification, are permitted provided that the following conditions
**  are met:
**  
**  1 Redistributions of source code must retain the above copyright
**    notice, this list of conditions and the following disclaimer.
**  
**  2 Redistributions in binary form must reproduce the above copyright
**    notice, this list of conditions and the following disclaimer in
**    the documentation and/or other materials provided with the
**    distribution.
**  
**  3 Neither the name of the Standards Of Fundamental Astronomy Board,
**    the International Astronomical Union nor the names of its
**    contributors may be used to endorse or promote products derived
**    from this software without specific prior written permission.
**  
**  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
**  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
**  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
**  FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
**  COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
**  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
**  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
**  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
**  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
**  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
**  POSSIBILITY OF SUCH DAMAGE.
**  
*/
