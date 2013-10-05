This is the source code repository for ERFA (Essential Routines for 
Fundamental Astronomy).  ERFA is a C library containing key algorithms for 
astronomy, and is based on the `SOFA library <http://www.iausofa.org/>`_ published by the International 
Astronomical Union (IAU).  

ERFA is intended to replicate the functionality of SOFA (aside from possible
bugfixes in ERFA that have not yet been included in SOFA), but is licensed
under a three-clause BSD license to enable its compatibility with a wide 
range of open source licenses. Permission for this release has been
obtained from the SOFA board, and is avilable in the ``LICENSE`` file included
in this source distribution.

Differences from SOFA
---------------------

This version of ERFA (v0.0.1) is based on SOFA version "20120301_a", with the 
differences outlined below.

ERFA Branding
^^^^^^^^^^^^^

All references to "SOFA" in the source code have been changed to ERFA, and 
functions have the prefix ``era`` instead of ``iau``. 

Building and Installing ERFA
----------------------------

To build and install a released version of ERFA in your OS's standard 
location, simply do::

    ./configure
    make
    make install

If you want to run the tests to make sure ERFA built correctly, before
installing do::

    make check


For Developers
^^^^^^^^^^^^^^

If you are using a developer version from github, you will need to first do
``./bootstrap.sh`` before the above commands. This requires ``autoconf`` and 
``libtool``.

If you wish to build against the ERFA static library without installing, you
will find it in ``$ERFAROOT/src/.libs/liberfa.a`` after running ``make``.

Alternatively, if you wish to bundle the ERFA source code with a separate 
package, you can use the ``source_flattener.py`` script from the 
`erfa-fetch repository <https://github.com/liberfa/erfa-fetch>`_ to combine
the ERFA source code into a single ``erfa.c`` source file, and an 
``erfa.h`` include file.  If possible, however, it is recommended that you
provide an option to use a installed ERFA library, if it is present.


Travis Build Status
-------------------
.. image:: https://travis-ci.org/liberfa/erfa.png
    :target: https://travis-ci.org/liberfa/erfa
