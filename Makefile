CC = clang
LIBTOOL = libtool
CFLAGS = -Wall -O
LDFLAGS = -lm -fPIC

SRCDIR = src
BUILDDIR = build
LIBNAME = liberfa

OBJECTS = $(patsubst %.c,%.o,$(filter-out $(SRCDIR)/t_erfa_c.c,$(wildcard $(SRCDIR)/*.c)))
HEADERS = $(SRCDIR)/*.h 

UNAME := $(shell uname)

buildstatic : buildobj
	$(LIBTOOL) -static -o $(BUILDDIR)/$(LIBNAME).a $(OBJECTS)

buildshared : $(OBJECTS) mkbuild
ifeq ($(UNAME), Darwin)
	$(CC) -shared -o $(BUILDDIR)/$(LIBNAME).dylib $(OBJECTS) -shared
else
	$(CC) -shared -o $(BUILDDIR)/$(LIBNAME).so $(OBJECTS) -shared
endif

buildobj : $(OBJECTS) mkbuild


headers : mkbuild
	cp $(HEADERS) $(BUILDDIR)

buildtest : build
	$(CC) $(CFLAGS) $(SRCDIR)/t_erfa_c.c -L$(BUILDDIR) -lerfa -o $(BUILDDIR)/test_erfa

test : buildtest
	$(BUILDDIR)/test_erfa --verbose

mkbuild : 
	mkdir -p $(BUILDDIR) 

clean :
	rm $(SRCDIR)/*.o
	rm -rf $(BUILDDIR)