# This script can only be executed using the dot command.
# It is not recommended to execute this script directly unless
# you are familiar with its content.

# set variables
DIRCTL="$HOME/.local/usr/opt/cd-extended/dirctl"
DIRHIST=$1
EXEMODE='switch'
shift

# change directory
SOURCE=$(pwd)
builtin cd $@
EXITSTAT=$?
DEST=$(pwd)

# execute the main process
if [ -f $DIRCTL ] && [ -d $(dirname $DIRHIST) ]; then
    $DIRCTL $EXEMODE $DIRHIST $SOURCE $DEST >/dev/null 2>&1
fi

# unset varables
unset DIRCTL
unset DIRHIST
unset EXEMODE
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
