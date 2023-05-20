SUBDIRS = setup alias

install: $(SUBDIRS)
	for dir in $(SUBDIRS); do $(MAKE) -C $$dir install; done

uninstall: $(SUBDIRS)
	for dir in $(SUBDIRS); do $(MAKE) -C $$dir uninstall; done

.PHONY:	install uninstall
