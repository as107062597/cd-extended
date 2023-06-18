# It is not recommended to execute this script directly
# unless you are familiar with its content.

# set variables
CDEXTENDED_DIRCTL="$HOME/.local/usr/opt/cd-extended/dirctl"
CDEXTENDED_EXEMODE='change'
CDEXTENDED_EXECACT='exec'
CDEXTENDED_NAME=$1
shift

# change directory
CDEXTENDED_SOURCE=$(pwd)
builtin cd $@
CDEXTENDED_EXITSTAT=$?
CDEXTENDED_DEST=$(pwd)

# execute the main process
if [ -f $BRANCH_DIRHIST_PATH ] && [ -r $BRANCH_DIRHIST_PATH ]; then
    if [ -f $CDEXTENDED_DIRCTL ] && [ -x $CDEXTENDED_DIRCTL ]; then
        $CDEXTENDED_DIRCTL $CDEXTENDED_EXEMODE $CDEXTENDED_EXECACT \
            $BRANCH_DIRHIST_PATH $CDEXTENDED_SOURCE $CDEXTENDED_DEST \
            $CDEXTENDED_NAME >/dev/null 2>&1
    fi
fi

# unset varables
unset CDEXTENDED_DIRCTL
unset CDEXTENDED_EXEMODE
unset CDEXTENDED_EXECACT
unset CDEXTENDED_SOURCE
unset CDEXTENDED_DEST
unset CDEXTENDED_NAME

# return
case $EXITSTAT in
    0)
        unset CDEXTENDED_EXITSTAT
        true
        ;;
    *)
        unset CDEXTENDED_EXITSTAT
        false
        ;;
esac
