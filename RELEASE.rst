
Instructions for Doing A Release of ERFA
========================================

* Clone the ERFA repository from github (if you haven't already done so),
  and change to the ERFA directory.

* Make sure you are on the "master" branch from the "liberfa" github 
  repository and have the latest version (if you have a fresh clone, this
  should already be the case).

* Update the version number in the `AC_INIT` macro of `configure.ac` to
  the version number you are about to release, and also update the version 
  mentioned in `README.rst`. 

* Commit these changes using ``git commit``, with a commit message like 
  ``Preparing release v0.0.1``.

* Run `./bootstrap.sh`: you need `automake`, `autoconf` and `libtool` 
  installed.  If no errors appear, this will create a new `./configure`
  file.

* Run `./configure`, which should create a `Makefile` in the top level 
  directory and in ./src

* Run `make check`, which will build the library and run the tests -
  make sure they pass before proceeding.

* Run `make distcheck`: this creates the distribution tarball, 
  unpackages it and runs the check inside the untarred directory.
  The resulting tarball will be named e.g., `erfa-0.0.1.tar.gz` and
  will be placed in the working directory.

* Tag the current commit with the version number (e.g., ``git tag v0.0.1``).  

* Push up your changes and the new tag to github: 
  ``git push --tags origin master``. (The command here assumes the git remote
  "origin" points to the "liberfa/erfa" repository.  If not, substitute the
  appropriate name.)

* Go to the "liberfa/erfa" repository for the github page, and click on the
  "releases" button, and then the release corresponding to the tag you just 
  made. 

* Click on the "Draft release notes or downloads".  Put the version number as
  the title (e.g., ``v0.0.1``)and for the description put 
  ``See `README.rst` for release notes.``

* Upload the tarball you created (e.g., `erfa-0.0.1.tar.gz`) by dropping it
  in the area that says "Attach binaries for this release  by dropping them 
  here." 

* Click the "Publish release" button.

* Update the release listing on Github Pages to include this release:
  Do ``git checkout gh-pages``, add a new ``<li>...</li>`` entry for the
  release in `index.html`, do ``git commit``, and then
  ``git push origin gh-pages``.
