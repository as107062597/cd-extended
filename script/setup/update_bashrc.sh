#!/bin/bash

# set variables
BASHRC="$HOME/.bashrc"
PATTERN='.bashrc.d'
APPEND='bashrc_autoload.sh'

# update bashrc
grep $PATTERN $BASHRC >/dev/null 2>&1

if [ $? -eq 1 ]; then
    echo '' >> $BASHRC
    cat $APPEND >> $BASHRC
fi
