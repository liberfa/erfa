#!/bin/sh

# if running from `meson dist`, make sure we run from the dist root
if [ -n "$MESON_PROJECT_DIST_ROOT" ]; then
    cd "$MESON_PROJECT_DIST_ROOT"
# meson < 0.58
elif [ -n "$MESON_DIST_ROOT" ]; then
    cd "$MESON_DIST_ROOT"
fi

# ensure m4 dir exists
mkdir -p m4
# ensure build-aux exists
mkdir -p build-aux

autoreconf -s -i -m -f
