#!/bin/bash

# set variables
TMP_CDNAME='cd'
TMP_PDNAME='pd'
TMP_NDNAME='nd'
TMP_CDSHELL="$HOME/.local/usr/opt/cd-extended/cd-shell"
TMP_EXSHELL="$HOME/.local/usr/opt/cd-extended/ex-shell"
TMP_HISTDIR="$HOME/.local/etc/cd-extended.d"
TMP_DIRHIST='dir.hist'
TMP_BRANCH_DIRHIST="$(whoami)-$(date +%s%9N)-$(uuidgen).dir.hist"

# set global variables
DIRHIST_PATH="$TMP_HISTDIR/$TMP_DIRHIST"
BRANCH_DIRHIST_PATH="$TMP_HISTDIR/$TMP_BRANCH_DIRHIST"

# create a directory for the dir.hist file
mkdir -p $TMP_HISTDIR

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
if [ -f $TMP_CDSHELL ] && [ -f $TMP_EXSHELL ]; then
    alias cd=". $TMP_CDSHELL $TMP_CDNAME"
    alias pd=". $TMP_EXSHELL $TMP_PDNAME"
    alias nd=". $TMP_EXSHELL $TMP_NDNAME"
fi

# unset variables
unset TMP_CDNAME
unset TMP_PDNAME
unset TMP_NDNAME
unset TMP_CDSHELL
unset TMP_EXSHELL
unset TMP_HISTDIR
unset TMP_DIRHIST
unset TMP_BRANCH_DIRHIST
