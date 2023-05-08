# This script can only be executed using the dot command.
# It is not recommended to execute this script directly unless
# you are familiar with its content.

# set varables
DIRCTL="$HOME/.local/usr/opt/cd-extended/dirctl"
DIRHIST=$1
EXEMODE='forward'
CTLPRT='print'
CTLEXEC='exec'
shift

# execute the main process
if [ -f $DIRCTL ] && [ -d $(dirname $DIRHIST) ]; then
    SOURCE=$(pwd)
    DEST=$($DIRCTL $EXEMODE $CTLPRT $DIRHIST $@)
    EXITSTAT=$?

    if [ $EXITSTAT -eq 0 ]; then
        if [ ${DEST:0:1} == '/' ]; then
            builtin cd $DEST
            EXITSTAT=$?
            $DIRCTL $EXEMODE $CTLEXEC $DIRHIST $SOURCE $DEST $@ >/dev/null 2>&1
        else
            echo "$DEST"
        fi
    fi
fi

# unset variables
unset DIRCTL
unset DIRHIST
unset EXEMODE
unset CTLPRT
unset CTLEXEC
unset SOURCE
unset DEST

# return
case $EXITSTAT in
    0)
        unset EXITSTAT
        true
        ;;
    *)
        unset EXITSTAT
        false
        ;;
esac
