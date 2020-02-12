#
# Autoconf initialisation.
#
AC_INIT(libbudgetvhd, 1.0)
AC_PREREQ(2.13)
AM_CONFIG_HEADER(src/config.h)
AM_INIT_AUTOMAKE([foreign -Wall -Werror])
AC_CONFIG_MACRO_DIR([m4])

#
# Version management.
# +1    : 0     Interface changes breaking retro-compatibility.
# 0     : +1    Internal changes without lost of retro-compatibility.
#
VERSION_MAJOR=1
VERSION_MINOR=0
AC_DEFINE_UNQUOTED([VERSION_MAJOR], [$VERSION_MAJOR], [major version number])
AC_DEFINE_UNQUOTED([VERSION_MINOR], [$VERSION_MINOR], [minor version number])

#
# Standard checks.
#
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AM_PROG_AR

# Compiler capabilities.
AC_C_INLINE
AC_C_CONST

#
# Libtool
#
LT_INIT

LT_CURRENT=$VERSION_MAJOR
LT_REVISION=$VERSION_MINOR
LT_AGE=0
LT_RELEASE=$VERSION_MAJOR.$VERSION_MINOR
AC_SUBST(LT_CURRENT)
AC_SUBST(LT_REVISION)
AC_SUBST(LT_AGE)
AC_SUBST(LT_RELEASE)

# Output files.
AC_OUTPUT([Makefile
	   libbudgetvhd.pc
           src/Makefile
           app/Makefile
           ])
