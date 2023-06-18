# This block can help users print candidate words.
# The configuration here will not affect other users.
if [ -d $HOME/.local/etc/bash_completion.d ]; then
    for i in $HOME/.local/etc/bash_completion.d/*; do
        if [ -r $i ]; then
            . $i
        fi
    done
    unset i
fi
