#!/bin/bash

# set variables
BASHRC="$HOME/.bashrc"
PATTERN_AUTOLOAD='.bashrc.d'
PATTERN_COMPLETION='.local/etc/bash_completion.d'
APPEND_AUTOLOAD='bashrc_autoload.sh'
APPEND_COMPLETION='bashrc_completion.sh'

# update bashrc
grep $PATTERN_AUTOLOAD $BASHRC >/dev/null 2>&1

if [ $? -eq 1 ]; then
    echo '' >> $BASHRC
    cat $APPEND_AUTOLOAD >> $BASHRC
fi

grep $PATTERN_COMPLETION $BASHRC >/dev/null 2>&1

if [ $? -eq 1 ]; then
    echo '' >> $BASHRC
    cat $APPEND_COMPLETION >> $BASHRC
fi
