#include "erfam.h"

int eraTaiutc(double tai1, double tai2, double *utc1, double *utc2)
/*
**  - - - - - - - - - -
**   e r a T a i u t c
**  - - - - - - - - - -
**
**  Time scale transformation:  International Atomic Time, TAI, to
**  Coordinated Universal Time, UTC.
**
**  Given:
**     tai1,tai2  double   TAI as a 2-part Julian Date (Note 1)
**
**  Returned:
**     utc1,utc2  double   UTC as a 2-part quasi Julian Date (Notes 1-3)
**
**  Returned (function value):
**                int      status: +1 = dubious year (Note 4)
**                                  0 = OK
**                                 -1 = unacceptable date
**
**  Notes:
**
**  1) tai1+tai2 is Julian Date, apportioned in any convenient way
**     between the two arguments, for example where tai1 is the Julian
**     Day Number and tai2 is the fraction of a day.  The returned utc1
**     and utc2 form an analogous pair, except that a special convention
**     is used, to deal with the problem of leap seconds - see the next
**     note.
**
**  2) JD cannot unambiguously represent UTC during a leap second unless
**     special measures are taken.  The convention in the present
**     function is that the JD day represents UTC days whether the
**     length is 86399, 86400 or 86401 SI seconds.
**
**  3) The function eraD2dtf can be used to transform the UTC quasi-JD
**     into calendar date and clock time, including UTC leap second
**     handling.
**
**  4) The warning status "dubious year" flags UTCs that predate the
**     introduction of the time scale and that are too far in the future
**     to be trusted.  See eraDat for further details.
**
**  Called:
**     eraJd2cal    JD to Gregorian calendar
**     eraDat       delta(AT) = TAI-UTC
**     eraCal2jd    Gregorian calendar to JD
**
**  References:
**
**     McCarthy, D. D., Petit, G. (eds.), IERS Conventions (2003),
**     IERS Technical Note No. 32, BKG (2004)
**
**     Explanatory Supplement to the Astronomical Almanac,
**     P. Kenneth Seidelmann (ed), University Science Books (1992)
**
**  Copyright (C) 2013, NumFOCUS Foundation.
**  Derived, with permission, from the SOFA library.  See notes at end of file.
*/
{
   int big1;
   int i, iy, im, id, js;
   double a1, a2, d1, dats1, d2, fd, ddats, dats2, datd, as1, as2, da;


/* Put the two parts of the TAI into big-first order. */
   big1 = ( tai1 >= tai2 );
   if ( big1 ) {
      a1 = tai1;
      a2 = tai2;
   } else {
      a1 = tai2;
      a2 = tai1;
   }

/* See if the TAI can possibly be in a leap-second day. */
   d1 = a1;
   dats1 = 0.0;
   for ( i = -1; i <= 3; i++ ) {
      d2 = a2 + (double) i;
      if ( eraJd2cal(d1, d2, &iy, &im, &id, &fd) ) return -1;
      js = eraDat(iy, im, id, 0.0, &dats2);
      if ( js < 0 ) return -1;
      if ( i == -1 ) dats1 = dats2;
      ddats = dats2 - dats1;
      datd = dats1 / DAYSEC;
      if ( fabs(ddats) >= 0.5 ) {

      /* Yes.  Get TAI for the start of the UTC day that */
      /* ends in a leap. */
         if ( eraCal2jd(iy, im, id, &d1, &d2) ) return -1;
         as1 = d1;
         as2 = d2 - 1.0 + datd;

      /* Is the TAI after this point? */
         da = a1 - as1;
         da = da + ( a2 - as2 );
         if ( da > 0 ) {

         /* Yes:  fraction of the current UTC day that has elapsed. */
            fd = da * DAYSEC / ( DAYSEC + ddats );

         /* Ramp TAI-UTC to bring about ERFA's JD(UTC) convention. */
            datd += ddats * ( fd <= 1.0 ? fd : 1.0 ) / DAYSEC;
         }

      /* Done. */
         break;
      }
      dats1 = dats2;
   }

/* Subtract the (possibly adjusted) TAI-UTC from TAI to give UTC. */
   a2 -= datd;

/* Return the UTC result, preserving the TAI order. */
   if ( big1 ) {
      *utc1 = a1;
      *utc2 = a2;
   } else {
      *utc1 = a2;
      *utc2 = a1;
   }

/* Status. */
   return js;

}
/*----------------------------------------------------------------------
**  
**  
**  Copyright (C) 2013, NumFOCUS Foundation.
**  All rights reserved.
**  
**  This library is derived, with permission, from the International
**  Astronomical Union's "Standards of Fundamental Astronomy" library,
**  available from http://www.iausofa.org.
**  
**  The ERFA version is intended to retain identical
**  functionality to the SOFA library,  but made distinct through
**  different function and file names, as set out in the SOFA license
**  conditions. The SOFA original has a role as a reference standard
**  for the IAU and IERS, and consequently redistribution is permitted only
**  in its unaltered state.  The ERFA version is not subject to this
**  restriction and therefore can be included in distributions which do not
**  support the concept of "read only" software.
**  
**  Although the intent is to replicate the SOFA API (other than replacement of
**  prefix names) and results (with the exception of bugs; any that are
**  discovered will be fixed), SOFA is not responsible for any errors found
**  in this version of the library.
**  
**  If you wish to acknowledge the SOFA heritage, please acknowledge that
**  you are using a library derived from SOFA, rather than SOFA itself.
**  
**  
**  TERMS AND CONDITIONS
**  
**  Redistribution and use in source and binary forms, with or without
**  modification, are permitted provided that the following conditions are met:
**  
**  1 Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**  
**  2 Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in the
**     documentation and/or other materials provided with the distribution.
**  
**  3 Neither the name of the Standards Of Fundamental Astronomy Board, the
**     International Astronomical Union nor the names of its contributors
**     may be used to endorse or promote products derived from this software
**     without specific prior written permission.
**  
**  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
**  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
**  TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
**  PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
**  HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
**  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
**  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
**  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
**  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
**  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**  
*/
