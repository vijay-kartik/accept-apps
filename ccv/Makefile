TARGET := ccv

lib/config.mk: lib/config.mk.in
	cd lib ; ./configure

SOURCES := $(wildcard lib/*.c) $(wildcard lib/3rdparty/dsfmt/*.c) \
	$(wildcard lib/3rdparty/kissfft/*.c) $(wildcard lib/3rdparty/sfmt/*.c) \
	$(wildcard lib/3rdparty/sha1/*.c) bin/bbfdetect.c

CFLAGS := -Ilib -DSQLITE_THREADSAFE=0 -DSQLITE_OMIT_LOAD_EXTENSION \
	-DHAVE_LIBPNG -DHAVE_LIBJPEG
LDFLAGS := -lm -ljpeg -lpng

RUNARGS := samples/cmyk-jpeg-format.jpg samples/face

ACCEPT_DIR := ../../accept
include $(ACCEPT_DIR)/accept.mk
