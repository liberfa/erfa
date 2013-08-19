This is the ERFA source code repository for ERFA (Essential Routines for 
Fundamental Astronomy).  ERFA is a C library containing key algorithms for 
astronomy, and is based on the SOFA library published by the International 
Astronomical Union (IAU).  

It is intended to replicate the functionality of SOFA (aside from possible
bugfixes in ERFA that have not yet been included in SOFA), but is licensed
under a three-clause BSD license to enable its compatibility with a wide 
range of open source licenses. Permission for this release has been
obtained from the SOFA board, and is avilable in the ``LICENSE`` file included
in this source distribution.

Differences from SOFA
---------------------

This version of ERFA (x.x) is based on SOFA version "20120301_a", with the 
differences outlined below.

ERFA Branding
^^^^^^^^^^^^^

All references to "SOFA" in the source code have been changed to ERFA, and
instead of ``iau``, function prefixes are all 


Travis Build Status
-------------------
.. image:: https://travis-ci.org/liberfa/erfa.png
    :target: https://travis-ci.org/liberfa/erfa
