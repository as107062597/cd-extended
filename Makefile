CXX         = g++
CXXFLAGS    = -Wall -std=c++17 -lstdc++fs -O3
AR          = ar
ARFLAGS     = rcs
SCPDIRS     = script
SRCDIRS     = src
SCRIPTS     = install.sh uninstall.sh
SUBDIRS     = $(SCPDIRS) $(SRCDIRS)

export CXX CXXFLAGS AR ARFLAGS

all: $(SRCDIRS)
	for dir in $(SRCDIRS); do $(MAKE) -C $$dir; done

clean: $(SRCDIR)
	for dir in $(SUBDIRS); do $(MAKE) -C $$dir clean; done

install: $(SUBDIRS)
	for dir in $(SUBDIRS); do $(MAKE) -C $$dir install; done

uninstall: $(SUBDIRS)
	for dir in $(SUBDIRS); do $(MAKE) -C $$dir uninstall; done

.PHONY: all clean install uninstall
