#!/bin/bash

# set variables
CDSHELL="$HOME/.local/usr/opt/cd-extended/cd-shell"
PDSHELL="$HOME/.local/usr/opt/cd-extended/pd-shell"
NDSHELL="$HOME/.local/usr/opt/cd-extended/nd-shell"
HISTDIR="$HOME/.local/etc/cd-extended.d"
DIRHIST="$(whoami)-$(date +%s%9N)-$(uuidgen | cut -c25-36).hist"
HISTDAY=30

# create a directory for the dir.hist file
mkdir -p $HISTDIR

# delete the dirhist file that hasn't been modified in the past month
find $HISTDIR -type f -mtime +$HISTDAY -exec rm -f {} \;

# initialize dirhist
echo 0 >> $HISTDIR/$DIRHIST
pwd >> $HISTDIR/$DIRHIST

# declare aliases
if [ -f $CDSHELL ] && [ -f $PDSHELL ] && [ -f $NDSHELL ]; then
    alias cd=". $CDSHELL $HISTDIR/$DIRHIST"
    alias pd=". $PDSHELL $HISTDIR/$DIRHIST"
    alias nd=". $NDSHELL $HISTDIR/$DIRHIST"
fi

# unset variables
unset CDSHELL
unset PDSHELL
unset NDSHELL
unset HISTDIR
unset DIRHIST
unset HISTDAY
