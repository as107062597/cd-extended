#!/bin/bash

# set variables
CDEXTENDED_CDNAME='cd'
CDEXTENDED_SDNAME='sd'
CDEXTENDED_CDSHELL="$HOME/.local/usr/opt/cd-extended/cd-shell"
CDEXTENDED_SDSHELL="$HOME/.local/usr/opt/cd-extended/sd-shell"
CDEXTENDED_HISTDIR="$HOME/.local/etc/cd-extended.d"
CDEXTENDED_DIRHIST='dir.hist'
CDEXTENDED_BRANCH_DIRHIST="$(whoami)-$(date +%s%9N)-$(uuidgen).dir.hist"

# set global variables
DIRHIST_PATH="$CDEXTENDED_HISTDIR/$CDEXTENDED_DIRHIST"
BRANCH_DIRHIST_PATH="$CDEXTENDED_HISTDIR/$CDEXTENDED_BRANCH_DIRHIST"

# create a directory for the dir.hist file
mkdir -p $CDEXTENDED_HISTDIR

# initialize branch dir.hist file
if [ -f $DIRHIST_PATH ] && [ -r $DIRHIST_PATH ]; then
    echo $(wc -l < $DIRHIST_PATH) > $BRANCH_DIRHIST_PATH
    cat $DIRHIST_PATH >> $BRANCH_DIRHIST_PATH
    CDEXTENDED_LAST_LINE=$(tail -n 1 $BRANCH_DIRHIST_PATH)
    if [[ $CDEXTENDED_LAST_LINE == *,* ]]; then
        if [ ${CDEXTENDED_LAST_LINE#*,} != $(pwd) ]; then
            echo "$(date +%s%3N),$(pwd)" >> $BRANCH_DIRHIST_PATH
        fi
    fi
    unset CDEXTENDED_LAST_LINE
else
    echo 0 > $BRANCH_DIRHIST_PATH
    echo "$(date +%s%3N),$(pwd)" >> $BRANCH_DIRHIST_PATH
fi

# declare aliases
if [ -f $CDEXTENDED_CDSHELL ] && [ -f $CDEXTENDED_SDSHELL ]; then
    alias cd=". $CDEXTENDED_CDSHELL $CDEXTENDED_CDNAME"
    alias sd=". $CDEXTENDED_SDSHELL $CDEXTENDED_SDNAME"
fi

# unset variables
unset CDEXTENDED_CDNAME
unset CDEXTENDED_SDNAME
unset CDEXTENDED_CDSHELL
unset CDEXTENDED_SDSHELL
unset CDEXTENDED_HISTDIR
unset CDEXTENDED_DIRHIST
unset CDEXTENDED_BRANCH_DIRHIST
