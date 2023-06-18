TARGET      = cd-extended.sh
INSTDIR     = $(HOME)/.local/etc/bashrc.d
INSTPATH    = $(INSTDIR)/$(TARGET)
COMPTAR     = cd-extended-prompt.sh
COMPDIR     = $(HOME)/.local/etc/bash_completion.d
COMPPATH    = $(COMPDIR)/$(basename $(COMPTAR))
SCRIPTS     = update_bashrc.sh update_bash_logout.sh

install: $(INSTPATH) $(COMPPATH)
	for script in $(SCRIPTS); do bash $$script; done

$(INSTPATH): $(TARGET)
	install -D -m 644 $< $@

$(COMPPATH): $(COMPTAR)
	install -D -m 644 $< $@

uninstall:
	rm -f $(INSTPATH) $(COMPPATH)

.PHONY: install uninstall
