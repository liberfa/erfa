project(
    'erfa', 'c',
    version: '2.0.0',
    meson_version: '>=0.46.0',
)

cc = meson.get_compiler('c')
confdata = configuration_data()

# The historic versions use libtool-compatible versioning.
# This uses some gnarly math to define ABI versions, which we replicate here.
# The general formula is:
#   libtool: C:R:A
#   -soname: (C - A).A.R
libtool_version = [9, 0, 8]
soversion = '@0@.@1@.@2@'.format(
    libtool_version[0] - libtool_version[2],
    libtool_version[2],
    libtool_version[1],
)

# API versions
version = meson.project_version().split('.')
confdata.set_quoted('PACKAGE_VERSION', meson.project_version())
confdata.set('PACKAGE_VERSION_MAJOR', version[0])
confdata.set('PACKAGE_VERSION_MINOR', version[1])
confdata.set('PACKAGE_VERSION_MICRO', version[2])

confdata.set_quoted('SOFA_VERSION', '20210512')


libm = cc.find_library('m', required: false)

subdir('src')

import('pkgconfig').generate(
    liberfa,
    filebase: 'erfa',
    name: 'Erfa',
    description: 'Essential Routines for Fundamental Astronomy',
)
