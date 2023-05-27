# It is not recommended to execute this script directly
# unless you are familiar with its content.

# set variables
TMP_DIRCTL="$HOME/.local/usr/opt/cd-extended/dirctl"
TMP_EXEMODE='switch'
TMP_NAME=$1
shift

# change directory
TMP_SOURCE=$(pwd)
builtin cd $@
TMP_EXITSTAT=$?
TMP_DEST=$(pwd)

# execute the main process
if [ -f $BRANCH_DIRHIST_PATH ] && [ -r $BRANCH_DIRHIST_PATH ]; then
    if [ -f $TMP_DIRCTL ] && [ -x $TMP_DIRCTL ]; then
        $TMP_DIRCTL $TMP_EXEMODE $BRANCH_DIRHIST_PATH $TMP_SOURCE $TMP_DEST \
            $TMP_NAME >/dev/null 2>&1
    fi
fi

# unset varables
unset TMP_DIRCTL
unset TMP_EXEMODE
unset TMP_SOURCE
unset TMP_DEST
unset TMP_NAME

# return
case $EXITSTAT in
    0)
        unset TMP_EXITSTAT
        true
        ;;
    *)
        unset TMP_EXITSTAT
        false
        ;;
esac
