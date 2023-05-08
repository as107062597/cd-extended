SUBDIRS     = setup alias

all: $(SUBDIRS)
	for dir in $(SUBDIRS); do $(MAKE) -C $$dir; done

install: $(SUBDIRS)
	for dir in $(SUBDIRS); do $(MAKE) -C $$dir install; done

uninstall: $(SUBDIRS)
	for dir in $(SUBDIRS); do $(MAKE) -C $$dir uninstall; done

.PHONY:	all install uninstall
