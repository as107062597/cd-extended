TARGET      = cd-extended.sh
INSTDIR     = $(HOME)/.local/etc/bashrc.d
INSTPATH    = $(INSTDIR)/$(TARGET)
SCRIPTS     = update_bashrc.sh update_bash_logout.sh

install: $(INSTPATH)
	for script in $(SCRIPTS); do bash $$script; done

$(INSTPATH): $(TARGET)
	install -D -m 644 $< $@

uninstall:
	rm -f $(INSTPATH)

.PHONY: install uninstall
