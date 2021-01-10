cmake_minimum_required(VERSION 3.13)
project(erfa VERSION 1.7.1)

set(ERFA_SOFA_VERSION 20200721)

set(ERFA_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(ERFA_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(ERFA_VERSION_PATCH ${PROJECT_VERSION_PATCH})
set(ERFA_VERSION ${PROJECT_VERSION})

include(CheckIncludeFile)

set(MAIN_PROJECT OFF)
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(MAIN_PROJECT ON)
    message("Building as main project")
endif()

if(MAIN_PROJECT AND NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
endif()

option(ERFA_SHARED_LIB "Build shared libraries (.dll/.so) instead of static ones" ${BUILD_SHARED_LIBS})
option(BUILD_TESTING "Generate the test target." ${MAIN_PROJECT})
option(ERFA_INSTALL "Generate the install target." ${MAIN_PROJECT})

include(CTest)

check_include_file(dlfcn.h HAVE_DLFCN_H)
check_include_file(inttypes.h HAVE_INTTYPES_H)
check_include_file(memory.h HAVE_MEMORY_H)
check_include_file(stdint.h HAVE_STDINT_H)
check_include_file(stdlib.h HAVE_STDLIB_H)
check_include_file(strings.h HAVE_STRINGS_H)
check_include_file(string.h HAVE_STRING_H)
check_include_file(sys/stat.h HAVE_SYS_STAT_H)
check_include_file(sys/types.h HAVE_SYS_TYPES_H)
check_include_file(unistd.h HAVE_UNISTD_H)

include(CheckLibraryExists)
check_library_exists(m sin "" HAVE_LIB_M)
if(HAVE_LIB_M)
    set(pc_private_libs "-lm")
endif()

set(ERFA_PACKAGE_BUGREPORT "" CACHE STRING "Define to the address where bug reports for this package should be sent.")
set(ERFA_PACKAGE_URL "" CACHE STRING "Define to the home page for this package.")

include(CheckIncludeFiles)
check_include_files("stdlib.h;stdarg.h;string.h;float.h" STDC_HEADERS)

configure_file(cmake.config.h.in config.h @ONLY)

include(GNUInstallDirs)

add_subdirectory(src)

set(gitignore ${PROJECT_SOURCE_DIR}/.gitignore)
if (MAIN_PROJECT AND EXISTS ${gitignore})
    file(STRINGS ${gitignore} lines)
    foreach(line ${lines})
        string(REPLACE "." "[.]" line "${line}")
        string(REPLACE "*" ".*" line "${line}")
        set(ignored_files ${ignored_files} "${line}$" "${line}/")
    endforeach()
    set(ignored_files ${ignored_files} /.git)

    set(CPACK_SOURCE_IGNORE_FILES ${ignored_files})
    set(CPACK_RESOURCE_FILE_README ${PROJECT_SOURCE_DIR}/README.rst)
    include(CPack)
endif()
