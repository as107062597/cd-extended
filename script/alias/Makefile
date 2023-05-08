TARGETS     = cd-shell.sh pd-shell.sh nd-shell.sh
INSTDIR     = $(HOME)/.local/usr/opt/cd-extended
INSTPATHS   = $(addprefix $(INSTDIR)/,$(basename $(TARGETS)))

all:
	sed -i 's/\r//' *

install: $(INSTPATHS)

$(INSTDIR)/%: %.sh
	install -D -m 644 $< $@

uninstall:
	for file in $(INSTPATHS); \
	do rm -f $$file; \
	done

.PHONY: all install uninstall
