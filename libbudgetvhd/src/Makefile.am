noinst_HEADERS= internal.h 

libbudgetvhd_la_SOURCES = \
    libbudgetvhd.c \
    swab.c \
    budgetvhd.h \
    internal.h

libbudgetvhd_la_CFLAGS = \
    -g -W -Wall -Werror

lib_LTLIBRARIES = libbudgetvhd.la
include_HEADERS = budgetvhd.h

libbudgetvhd_la_LDFLAGS = \
        -version-info $(LT_CURRENT):$(LT_REVISION):$(LT_AGE) \
        -release $(LT_RELEASE) \
        -export-dynamic 
