# This section can help users automatically load customized shell files
# when logging in.
if [ -d $HOME/.local/etc/bashrc.d ]; then
    for i in $HOME/.local/etc/bashrc.d/*.sh; do
        if [ -r $i ]; then
            . $i
        fi
    done
    unset i
fi
