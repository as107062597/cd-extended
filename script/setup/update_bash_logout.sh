#!/bin/bash

# set variables
BASHLOGOUT="$HOME/.bash_logout"
PATTERN='dir.hist'
APPEND='bash_logout_update_dirhist.sh'

# update bash_logout
grep $PATTERN $BASHLOGOUT >/dev/null 2>&1

if [ $? -eq 1 ]; then
    echo '' >> $BASHLOGOUT
    cat $APPEND >> $BASHLOGOUT
fi
