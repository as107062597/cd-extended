# It is not recommended to execute this script directly
# unless you are familiar with its content.

# set varables
TMP_DIRCTL="$HOME/.local/usr/opt/cd-extended/dirctl"
TMP_CTLPRT='print'
TMP_CTLEXEC='exec'
TMP_NAME=$1
shift

# set execution mode for dirhist
case $TMP_NAME in
    'pd')
        TMP_EXEMODE='backward'
        ;;
    'nd')
        TMP_EXEMODE='forward'
        ;;
    *)
        TMP_EXEMODE='none'
        ;;
esac

# detect if the verbose option is present
TMP_VFLAG=0
for tmp_arg in "$@"; do
    if [ tmp_arg == '-v' ] || [ tmp_arg == '--verbose' ]; then
        TMP_VFLAG=1
        break
    fi
done
unset tmp_arg

# execute the main process
if [ -f $BRANCH_DIRHIST_PATH ] && [ -r $BRANCH_DIRHIST_PATH ] &&
    [ -f $TMP_DIRCTL ] && [ -x $TMP_DIRCTL ];
then
    TMP_SOURCE=$(pwd)
    TMP_DEST=$($TMP_DIRCTL $TMP_EXEMODE $TMP_CTLPRT $BRANCH_DIRHIST_PATH \
        $TMP_NAME $@)
    TMP_EXITSTAT=$?

    if [ $TMP_EXITSTAT -eq 0 ]; then
        if [ ${TMP_DEST:0:1} == '/' ]; then
            builtin cd $TMP_DEST
            TMP_EXITSTAT=$?

            if [ $TMP_EXITSTAT -eq 0 ]; then
                if [ $TMP_VFLAG -eq 1 ]; then
                    echo $TMP_DEST
                else
                    $TMP_DIRCTL $TMP_EXEMODE $TMP_CTLEXEC \
                        $BRANCH_DIRHIST_PATH $TMP_SOURCE $TMP_DEST \
                        $TMP_NAME $@ >/dev/null 2>&1
                fi
            fi
        else
            echo "$TMP_DEST"
        fi
    fi
fi

# unset variables
unset TMP_DIRCTL
unset TMP_CTLPRT
unset TMP_CTLEXEC
unset TMP_NAME
unset TMP_EXEMODE
unset TMP_VFLAG
unset TMP_SOURCE
unset TMP_DEST

# return
case $TMP_EXITSTAT in
    0)
        unset TMP_EXITSTAT
        true
        ;;
    *)
        unset TMP_EXITSTAT
        false
        ;;
esac
