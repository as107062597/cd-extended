TARGET      = cd-extended.sh
INSTDIR     = $(HOME)/.local/etc/bashrc.d
INSTPATH    = $(INSTDIR)/$(TARGET)
UPDATE      = update_bashrc.sh

all:
	sed -i 's/\r//' *

install: $(INSTPATH)
	bash $(UPDATE)

$(INSTPATH): $(TARGET)
	install -D -m 644 $< $@

uninstall:
	rm -f $(INSTPATH)

.PHONY: all install uninstall
