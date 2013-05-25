LIBTOOL = libtool
CFLAGS = -Wall -O
LDFLAGS = -lm -fPIC

SRCDIR = src
BUILDDIR = build
LIBNAME = liberfa

OBJECTS = $(patsubst %.c,%.o,$(filter-out $(SRCDIR)/t_erfa_c.c,$(wildcard $(SRCDIR)/*.c)))
HEADERS = $(SRCDIR)/*.h 

UNAME := $(shell uname)

buildstatic : buildobj cpheaders
	$(LIBTOOL) -static -o $(BUILDDIR)/$(LIBNAME).a $(OBJECTS)

buildshared : buildobj cpheaders
ifeq ($(UNAME), Darwin)
	$(CC) -shared -o $(BUILDDIR)/$(LIBNAME).dylib $(OBJECTS) -shared
else
	$(CC) -shared -o $(BUILDDIR)/$(LIBNAME).so $(OBJECTS) -shared
endif

buildobj : $(OBJECTS) mkbuild

cpheaders : mkbuild
	cp $(HEADERS) $(BUILDDIR)

buildtest : buildstatic
	$(CC) $(CFLAGS) $(SRCDIR)/t_erfa_c.c -L$(BUILDDIR) -lerfa -o $(BUILDDIR)/test_erfa

test : buildtest
	$(BUILDDIR)/test_erfa --verbose

mkbuild : 
	mkdir -p $(BUILDDIR) 

clean :
	rm $(SRCDIR)/*.o
	rm -rf $(BUILDDIR)
