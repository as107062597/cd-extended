#!/bin/bash

# set variables
CDEXTENDED_CDNAME='cd'
CDEXTENDED_PDNAME='pd'
CDEXTENDED_NDNAME='nd'
CDEXTENDED_CDSHELL="$HOME/.local/usr/opt/cd-extended/cd-shell"
CDEXTENDED_EXSHELL="$HOME/.local/usr/opt/cd-extended/ex-shell"
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
    pwd >> $BRANCH_DIRHIST_PATH
else
    echo 0 > $BRANCH_DIRHIST_PATH
    pwd >> $BRANCH_DIRHIST_PATH
fi

# declare aliases
if [ -f $CDEXTENDED_CDSHELL ] && [ -f $CDEXTENDED_EXSHELL ]; then
    alias cd=". $CDEXTENDED_CDSHELL $CDEXTENDED_CDNAME"
    alias pd=". $CDEXTENDED_EXSHELL $CDEXTENDED_PDNAME"
    alias nd=". $CDEXTENDED_EXSHELL $CDEXTENDED_NDNAME"
fi

# unset variables
unset CDEXTENDED_CDNAME
unset CDEXTENDED_PDNAME
unset CDEXTENDED_NDNAME
unset CDEXTENDED_CDSHELL
unset CDEXTENDED_EXSHELL
unset CDEXTENDED_HISTDIR
unset CDEXTENDED_DIRHIST
unset CDEXTENDED_BRANCH_DIRHIST
