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
#include <erfam.h>
#include <erfaextra.h>

static int verbose = 0;

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

/*
**
**  Validate the ERFA C functions that are not derived from SOFA (SOFA-derived tests are in t_erfa_c)
**
*/

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
    printf("t_versions failed - major version not in version string %s\n", version_str);
  }

  sprintf(buf, "%d", eraVersionMinor());
  res = strstr(version_str, buf);
  if (!res) {
    *status = 1;
    printf("t_versions failed - minor version not in version string %s\n", version_str);
  }

  sprintf(buf, "%d", eraVersionMicro());
  res = strstr(version_str, buf);
  if (!res) {
    *status = 1;
    printf("t_versions failed - micro version not in version string %s\n", version_str);
  }

  if (*status == 0) {
    printf("t_versions passed\n");
  }

}

static void t_bform(int *status)
/*
**  - - - - - - - -
**   t _ b f o r m
**  - - - - - - - -
**
**  Test eraBform function.
**
**  Returned:
**     status    int         FALSE = success, TRUE = fail
**
**  Called:  eraBform, viv, vvd
**
**  This revision:  2023 March 21
*/
{
   int j;
   double a, f;

   j = eraBform(0, &a, &f);

   viv(j, -1, "eraBform", "j0", status);

   j = eraBform(ERFA_WGS84, &a, &f);

   viv(j, 0, "eraBform", "j1", status);
   vvd(a, 6378137.0, 1e-10, "eraBform", "a1", status);
   vvd(f, 0.3352810664747480720e-2, 1e-18, "eraBform", "f1", status);

   j = eraBform(ERFA_GRS80, &a, &f);

   viv(j, 0, "eraBform", "j2", status);
   vvd(a, 6378137.0, 1e-10, "eraBform", "a2", status);
   vvd(f, 0.3352810681182318935e-2, 1e-18, "eraBform", "f2", status);

   j = eraBform(ERFA_WGS72, &a, &f);

   viv(j, 0, "eraBform", "j3", status);
   vvd(a, 6378135.0, 1e-10, "eraBform", "a3", status);
   vvd(f, 0.3352779454167504862e-2, 1e-18, "eraBform", "f3", status);

   j = eraBform(ERFA_IAUMOON1988, &a, &f);

   viv(j, 0, "eraBform", "j4", status);
   vvd(a, 1738400.0, 1e-10, "eraBform", "a4", status);
   vvd(f, 0.0, 1e-18, "eraBform", "f4", status);

   j = eraBform(ERFA_IAUMOON1979, &a, &f);

   viv(j, 0, "eraBform", "j5", status);
   vvd(a, 1738000.0, 1e-10, "eraBform", "a5", status);
   vvd(f, 0.0, 1e-18, "eraBform", "f5", status);

   j = eraBform(ERFA_IAUMERCURY2015, &a, &f);

   viv(j, 0, "eraBform", "j6", status);
   vvd(a, 2439400.0, 1e-10, "eraBform", "a6", status);
   vvd(f, 0.0, 1e-18, "eraBform", "f6", status);

   j = eraBform(ERFA_IAUMERCURY2009, &a, &f);

   viv(j, 0, "eraBform", "j7", status);
   vvd(a, 2439700.0, 1e-10, "eraBform", "a7", status);
   vvd(f, 0.0, 1e-18, "eraBform", "f7", status);

   j = eraBform(ERFA_IAUMERCURY1979, &a, &f);

   viv(j, 0, "eraBform", "j8", status);
   vvd(a, 2439000.0, 1e-10, "eraBform", "a8", status);
   vvd(f, 0.0, 1e-18, "eraBform", "f8", status);

   j = eraBform(ERFA_IAUVENUS1991, &a, &f);

   viv(j, 0, "eraBform", "j9", status);
   vvd(a, 6051800.0, 1e-10, "eraBform", "a9", status);
   vvd(f, 0.0, 1e-18, "eraBform", "f9", status);

   j = eraBform(ERFA_IAUVENUS1982, &a, &f);

   viv(j, 0, "eraBform", "j10", status);
   vvd(a, 6051000.0, 1e-10, "eraBform", "a10", status);
   vvd(f, 0.0, 1e-18, "eraBform", "f10", status);

   j = eraBform(ERFA_IAUMARS2000, &a, &f);

   viv(j, 0, "eraBform", "j11", status);
   vvd(a, 3396190.0, 1e-10, "eraBform", "a11", status);
   vvd(f, 0.5886007555512007e-2, 1e-18, "eraBform", "f11", status);

   j = eraBform(ERFA_IAUMARS1979, &a, &f);

   viv(j, 0, "eraBform", "j12", status);
   vvd(a, 3393400.0, 1e-10, "eraBform", "a12", status);
   vvd(f, 0.5186500000000000e-2, 1e-18, "eraBform", "f12", status);

   j = eraBform(20, &a, &f);
   viv(j, -1, "eraBform", "j10", status);
}

static void t_gc2gde_extra(int *status)
/*
**  - - - - - - - - - - - -
**   t _ g c 2 g d e _extra
**  - - - - - - - - - - - -
**
**  Test eraGc2gde function
**  with planetary bodies
**
**  Returned:
**     status    int         FALSE = success, TRUE = fail
**
**  Called:  eraBform, eraGc2gde, viv, vvd
**
**  This revision:  2023 April 25
*/
{
   int j;
   double a, f;
   double xyz1[] = {6e5, 8.5e5, 1.39e6};
   double xyz2[] = {1.e6, 1.2e6, 1.875e6};
   double xyz3[] = {2e6, 2.77e6, 5.e6};
   double xyz4[] = {1.1e6, 1.5e6, 2.825e6};
   double e, p, h;

   j = eraBform(ERFA_IAUMOON1988, &a, &f);
   j = eraGc2gde(a, f, xyz1, &e, &p, &h);

   viv(j, 0, "eraGc2gde", "j4", status);
   vvd(e, 0.95613337487273109, 1e-14, "eraGc2gde", "e4", status);
   vvd(p, 0.92824779310565875, 1e-14, "eraGc2gde", "p4", status);
   vvd(h, -2139.65085877750971, 1e-8, "eraGc2gde", "h4", status);

   j = eraBform(ERFA_IAUMOON1979, &a, &f);
   j = eraGc2gde(a, f, xyz1, &e, &p, &h);

   viv(j, 0, "eraGc2gde", "j5", status);
   vvd(e, 0.95613337487273109, 1e-14, "eraGc2gde", "e5", status);
   vvd(p, 0.92824779310565875, 1e-14, "eraGc2gde", "p5", status);
   vvd(h, -1739.65085877738898, 1e-8, "eraGc2gde", "h5", status);

   j = eraBform(ERFA_IAUMERCURY2015, &a, &f);
   j = eraGc2gde(a, f, xyz2, &e, &p, &h);

   viv(j, 0, "eraGc2gde", "j6", status);
   vvd(e, 0.87605805059819353, 1e-14, "eraGc2gde", "e6", status);
   vvd(p, 0.87619972706832705, 1e-14, "eraGc2gde", "p6", status);
   vvd(h, 1014.92373735488684, 1e-8, "eraGc2gde", "h6", status);

   j = eraBform(ERFA_IAUMERCURY2009, &a, &f);
   j = eraGc2gde(a, f, xyz2, &e, &p, &h);

   viv(j, 0, "eraGc2gde", "j7", status);
   vvd(e, 0.87605805059819353, 1e-14, "eraGc2gde", "e7", status);
   vvd(p, 0.87619972706832705, 1e-14, "eraGc2gde", "p7", status);
   vvd(h, 714.92373735498495, 1e-8, "eraGc2gde", "h7", status);

   j = eraBform(ERFA_IAUMERCURY1979, &a, &f);
   j = eraGc2gde(a, f, xyz2, &e, &p, &h);

   viv(j, 0, "eraGc2gde", "j8", status);
   vvd(e, 0.87605805059819353, 1e-14, "eraGc2gde", "e8", status);
   vvd(p, 0.87619972706832705, 1e-14, "eraGc2gde", "p8", status);
   vvd(h, 1414.92373735527099, 1e-8, "eraGc2gde", "h8", status);

   j = eraBform(ERFA_IAUVENUS1991, &a, &f);
   j = eraGc2gde(a, f, xyz3, &e, &p, &h);

   viv(j, 0, "eraGc2gde", "j9", status);
   vvd(e, 0.94544310833186163, 1e-14, "eraGc2gde", "e9", status);
   vvd(p, 0.97135803030703449, 1e-14, "eraGc2gde", "p9", status);
   vvd(h, 4015.38688226513113, 1e-8, "eraGc2gde", "h9", status);

   j = eraBform(ERFA_IAUVENUS1982, &a, &f);
   j = eraGc2gde(a, f, xyz3, &e, &p, &h);

   viv(j, 0, "eraGc2gde", "j10", status);
   vvd(e, 0.94544310833186163, 1e-14, "eraGc2gde", "e10", status);
   vvd(p, 0.97135803030703449, 1e-14, "eraGc2gde", "p10", status);
   vvd(h, 4815.38688226492832, 1e-8, "eraGc2gde", "h10", status);

   j = eraBform(ERFA_IAUMARS2000, &a, &f);
   j = eraGc2gde(a, f, xyz4, &e, &p, &h);

   viv(j, 0, "eraGc2gde", "j11", status);
   vvd(e, 0.93804749179271363, 1e-14, "eraGc2gde", "e11", status);
   vvd(p, 0.9939171169955200517, 1e-14, "eraGc2gde", "p11", status);
   vvd(h, 190.9684342201539606, 1e-8, "eraGc2gde", "h11", status);

   j = eraBform(ERFA_IAUMARS1979, &a, &f);
   j = eraGc2gde(a, f, xyz4, &e, &p, &h);

   viv(j, 0, "eraGc2gde", "j12", status);
   vvd(e, 0.93804749179271363, 1e-14, "eraGc2gde", "e12", status);
   vvd(p, 0.9932722909258587642, 1e-14, "eraGc2gde", "p12", status);
   vvd(h, 1305.315664259892943, 1e-8, "eraGc2gde", "h12", status);

}

static void t_gd2gce_extra(int *status)
/*
**  - - - - - - - - - - - -
**   t _ g d 2 g c e _extra
**  - - - - - - - - - - - -
**
**  Test eraGd2gce function.
**  with planetary bodies
**
**  Returned:
**     status    int         FALSE = success, TRUE = fail
**
**  Called:  eraBform, eraGd2gce, viv, vvd
**
**  This revision:  2023 April 25
*/
{
   int j;
   double a, f;
   double e = 3.1, p = -0.5, h = 2500.0;
   double xyz[3];

   j = eraBform(ERFA_IAUMOON1988, &a, &f);
   j = eraGd2gce(a, f, e, p, h, xyz);

   viv(j, 0, "eraGd2gce", "j4", status);
   vvd(xyz[0], -1526462.17886806, 1e-7, "eraGd2gce", "0/1", status);
   vvd(xyz[1], 63526.24923599, 1e-7, "eraGd2gce", "1/1", status);
   vvd(xyz[2], -834631.92015606, 1e-7, "eraGd2gce", "2/1", status);

   j = eraBform(ERFA_IAUMOON1979, &a, &f);
   j = eraGd2gce(a, f, e, p, h, xyz);

   viv(j, 0, "eraGd2gce", "j5", status);
   vvd(xyz[0], -1526111.44943412, 1e-7, "eraGd2gce", "0/2", status);
   vvd(xyz[1], 63511.65305028, 1e-7, "eraGd2gce", "1/2", status);
   vvd(xyz[2], -834440.14994062, 1e-7, "eraGd2gce", "2/2", status);

   j = eraBform(ERFA_IAUMERCURY2015, &a, &f);
   j = eraGd2gce(a, f, e, p, h, xyz);

   viv(j, 0, "eraGd2gce", "j6", status);
   vvd(xyz[0], -2141115.51184899, 1e-7, "eraGd2gce", "0/3", status);
   vvd(xyz[1], 89106.06468457, 1e-7, "eraGd2gce", "1/3", status);
   vvd(xyz[2], -1170709.2227176, 1e-7, "eraGd2gce", "2/3", status);

   j = eraBform(ERFA_IAUMERCURY2009, &a, &f);
   j = eraGd2gce(a, f, e, p, h, xyz);

   viv(j, 0, "eraGd2gce", "j7", status);
   vvd(xyz[0], -2141378.55892445, 1e-7, "eraGd2gce", "0/3", status);
   vvd(xyz[1], 89117.01182385, 1e-7, "eraGd2gce", "1/3", status);
   vvd(xyz[2], -1170853.05037918, 1e-7, "eraGd2gce", "2/3", status);

   j = eraBform(ERFA_IAUMERCURY1979, &a, &f);
   j = eraGd2gce(a, f, e, p, h, xyz);

   viv(j, 0, "eraGd2gce", "j8", status);
   vvd(xyz[0], -2140764.78241505, 1e-7, "eraGd2gce", "0/3", status);
   vvd(xyz[1], 89091.46849886, 1e-7, "eraGd2gce", "1/3", status);
   vvd(xyz[2], -1170517.45250216, 1e-7, "eraGd2gce", "2/3", status);

   j = eraBform(ERFA_IAUVENUS1991, &a, &f);
   j = eraGd2gce(a, f, e, p, h, xyz);

   viv(j, 0, "eraGd2gce", "j9", status);
   vvd(xyz[0], -5308553.02976672, 1e-7, "eraGd2gce", "0/3", status);
   vvd(xyz[1], 220924.21778933, 1e-7, "eraGd2gce", "1/3", status);
   vvd(xyz[2], -2902586.03837143, 1e-7, "eraGd2gce", "2/3", status);

   j = eraBform(ERFA_IAUVENUS1982, &a, &f);
   j = eraGd2gce(a, f, e, p, h, xyz);

   viv(j, 0, "eraGd2gce", "j10", status);
   vvd(xyz[0], -5307851.57089884, 1e-7, "eraGd2gce", "0/3", status);
   vvd(xyz[1], 220895.02541792, 1e-7, "eraGd2gce", "1/3", status);
   vvd(xyz[2], -2902202.49794054, 1e-7, "eraGd2gce", "2/3", status);

   j = eraBform(ERFA_IAUMARS2000, &a, &f);
   j = eraGd2gce(a, f, e, p, h, xyz);

   viv(j, 0, "eraGd2gce", "j11", status);
   vvd(xyz[0], -2984076.561390340530, 1e-7, "eraGd2gce", "0/3", status);
   vvd(xyz[1], 124187.2835124741903, 1e-7, "eraGd2gce", "1/3", status);
   vvd(xyz[2], -1612482.706560474866, 1e-7, "eraGd2gce", "2/3", status);

   j = eraBform(ERFA_IAUMARS1979, &a, &f);
   j = eraGd2gce(a, f, e, p, h, xyz);

   viv(j, 0, "eraGd2gce", "j12", status);
   vvd(xyz[0], -2981149.358708496613, 1e-7, "eraGd2gce", "0/3", status);
   vvd(xyz[1], 124065.4631295617446, 1e-7, "eraGd2gce", "1/3", status);
   vvd(xyz[2], -1613167.098908534541, 1e-7, "eraGd2gce", "2/3", status);

}

static void t_leap_seconds(int *status)
/*
**  Test that the leap-second machinery yields something
*/
{
  int count_init, count_postset, count_postreset;
  eraLEAPSECOND* leapseconds_init;
  eraLEAPSECOND* leapseconds_postset;
  eraLEAPSECOND* leapseconds_postreset;

  eraLEAPSECOND fake_leapsecond[1] = {{ 2050, 5, 55.0 }};

  count_init = eraGetLeapSeconds(&leapseconds_init);

  eraSetLeapSeconds(fake_leapsecond, 1);
  count_postset = eraGetLeapSeconds(&leapseconds_postset);

  if (count_postset == 1) {
    printf("t_leap_seconds set passed\n");
  } else {
    *status = 1;
    printf("t_leap_seconds set failed - leap second table has %d entries instead of %d\n", count_postreset, 1);
  }

  eraSetLeapSeconds(fake_leapsecond, -1);
  count_postreset = eraGetLeapSeconds(&leapseconds_postreset);

  if (count_postreset == count_init) {
    printf("t_leap_seconds reset passed\n");
  } else {
    *status = 1;
    printf("t_leap_seconds reset failed - leap second table has %d entries instead of %d\n", count_postreset, count_init);
  }
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
   t_bform(&status);
   t_gc2gde_extra(&status);
   t_gd2gce_extra(&status);
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
