CXX         = g++
CXXFLAGS    = -Wall -std=c++17 -O3
AR          = ar
ARFLAGS     = rcs
SCPDIRS     = script
SRCDIRS     = src
SCRIPTS     = install.sh uninstall.sh
SUBDIRS     = $(SCPDIRS) $(SRCDIRS)

export CXX CXXFLAGS AR ARFLAGS

all: $(SUBDIRS)
	for file in $(SCRIPTS); do sed -i 's/\r//' $$file; done
	for dir in $(SUBDIRS); do $(MAKE) -C $$dir; done

clean: $(SRCDIR)
	for dir in $(SUBDIRS); do $(MAKE) -C $$dir clean; done

install: $(SUBDIRS)
	for dir in $(SUBDIRS); do $(MAKE) -C $$dir install; done

uninstall: $(SUBDIRS)
	for dir in $(SUBDIRS); do $(MAKE) -C $$dir uninstall; done

.PHONY: all clean install uninstall
