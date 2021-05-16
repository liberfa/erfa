This is the source code repository for ERFA (Essential Routines for
Fundamental Astronomy).  ERFA is a C library containing key algorithms for
astronomy, and is based on the `SOFA library <http://www.iausofa.org/>`_ published by the International
Astronomical Union (IAU).

ERFA is intended to replicate the functionality of SOFA (aside from possible
bugfixes in ERFA that have not yet been included in SOFA), but is licensed
under a three-clause BSD license to enable its compatibility with a wide
range of open source licenses. Permission for this release has been
obtained from the SOFA board, and is available in the ``LICENSE`` file included
in this source distribution.

Differences from SOFA
---------------------

This version of ERFA (v2.0.0) is based on SOFA version "20210512", with the
differences outlined below.

ERFA branding
^^^^^^^^^^^^^

All references to "SOFA" in the source code have been changed to ERFA, and
functions have the prefix ``era`` instead of ``iau``.

C macro prefixes
^^^^^^^^^^^^^^^^

All C macros used in ERFA are the same as their SOFA equivalents, but with an
``ERFA_`` prefix to prevent namespace collisions.

Version information
^^^^^^^^^^^^^^^^^^^

ERFA provides a few utility functions for accessing version information at
runtime which are not a part of SOFA.  Specifically, these are the
``eraVersion``, ``eraVersion*``, and ``eraSofaVersion`` functions that are
exposed in the ``erfaextra.h`` header.

Runtime leap second modification
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

ERFA provides the capability to modify at runtime the leap seconds assumed for
various calculations. These are accessed via the ``eraGetLeapSeconds`` and
``eraSetLeapSeconds`` functions that are exposed in the ``erfaextra.h`` header.
This functionality is currently considered somewhat experimental, meaning an
improved API might be available in the future, but the current API can also be
counted on for the near future.

Bug fixes
^^^^^^^^^

ERFA includes smaller changes that may or may not eventually make it into SOFA,
addressing localized bugs or similar smaller issues:

* ERFA 2.0.0 and SOFA "20210512"

  + Functionally, there no differences except for the added ``eraVersion``,
    ``eraSofaVersion``, and leap second functions noted above.
  + The three new functions added in SOFA are added to ERFA as well.
  + Like for SOFA, one now has to explicitly include ``erfam.h`` to use its
    macros defining constants, etc. Including just ``erfa.h`` (or
    ``erfaextra.h``) will no longer includes ``erfam.h`` implicitly.

* ERFA 1.7.3 and SOFA "20210125_a"

  + Only a small bug fix in the SOFA release.  The only differences
    between ERFA 1.7.3 and SOFA "20210125_a" remain the added ``eraVersion``,
    ``eraSofaVersion``, and leap second functions noted above.

* ERFA 1.7.2 and SOFA "20210125"

  + Only bug and accuracy fixes in the SOFA release.  The only differences
    between ERFA 1.7.2 and SOFA "20210125" remain the added ``eraVersion``,
    ``eraSofaVersion``, and leap second functions noted above.

* ERFA 1.7.1 and SOFA "20200721"

  + Only bug fixes in the SOFA release.  The only differences between ERFA 1.7.1
    and SOFA "20200721" remain the added ``eraVersion``, ``eraSofaVersion``, and
    leap second functions noted above.

* ERFA 1.7.0 and SOFA "20190722"

  + There are no differences between ERFA 1.7.0 and SOFA "20190722" except
    for the added ``eraVersion``, ``eraSofaVersion``, and leap second functions
    noted above.

* ERFA 1.6.0 and SOFA "20190722"

  + There are no differences between ERFA 1.6.0 and SOFA "20190722" except
    for the ``eraVersion`` and ``eraSofaVersion`` functions added in ERFA 1.4.0.

* ERFA 1.5.0 and SOFA "20180130"

  + There are no differences between ERFA 1.5.0 and SOFA "20180130" except
    for the ``eraVersion`` and ``eraSofaVersion`` functions added in ERFA 1.4.0.

* ERFA 1.4.0 and SOFA "20170420"

  + ERFA 1.4.0 adds the ``eraVersion`` and ``eraSofaVersion`` functions to
    determine the installed version of ERFA (and the SOFA version it is derived
    from).

  + ERFA 1.4.0 includes some bug fixes contributed to ERFA after 1.3.0 but
    before 1.4.0.  These were incorporated (with modification) into
    SOFA "20170420" (without attribution) and hence these are not differences
    between ERFA and SOFA. (See https://github.com/liberfa/erfa/issues/40 and
    https://github.com/liberfa/erfa/issues/41)

* ERFA 1.3.0 and SOFA "20160503_a"

  + There are no differences between ERFA 1.3.0 and SOFA "20160503_a".

* ERFA 1.2.0 and SOFA "20150209_a"

  + Typos have been corrected in the documentation of atco13 and atio13 (see https://github.com/liberfa/erfa/issues/29).

Note that issues identified in ERFA should generally also be reported upstream to SOFA at sofa@ukho.gov.uk.

Building and installing ERFA
----------------------------

To build and install a released version of ERFA in your OS's standard
location, simply do::

    ./configure
    make
    make install

If you want to run the tests to make sure ERFA built correctly, before
installing do::

    make check


For developers
^^^^^^^^^^^^^^

If you are using a developer version from github, you will need to first do
``./bootstrap.sh`` before the above commands. This requires ``autoconf`` and
``libtool``.

If you wish to build against the ERFA static library without installing, you
will find it in ``$ERFAROOT/src/.libs/liberfa.a`` after running ``make``.

Creating a single-file version of the source code
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Alternatively, if you wish to bundle the ERFA source code with a separate
package, you can use the ``source_flattener.py`` script from the
`erfa-fetch repository`_ to combine
the ERFA source code into just two files: a ``erfa.c`` source file, and an
``erfa.h`` include file.  You should run this script like this::

    cd /path/to/erfa-source-code
    python /path/to/erfa-fetch/source_flattener.py src -n erfa

If possible, however, it is recommended that you provide an option to use any
copy of the ERFA library that is already installed on the system.

Travis build status
-------------------
.. image:: https://travis-ci.org/liberfa/erfa.png
    :target: https://travis-ci.org/liberfa/erfa

.. _erfa-fetch repository: https://github.com/liberfa/erfa-fetch

Cite As
-------
.. image:: https://zenodo.org/badge/DOI/10.5281/zenodo.3564896.svg
   :target: https://doi.org/10.5281/zenodo.3564896
