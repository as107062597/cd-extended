# It is not recommended to execute this script directly
# unless you are familiar with its content.

# set varables
CDEXTENDED_DIRCTL="$HOME/.local/usr/opt/cd-extended/dirctl"
CDEXTENDED_CTLPRT='print'
CDEXTENDED_CTLEXEC='exec'
CDEXTENDED_NAME=$1
shift

# set execution mode for dirhist
case $CDEXTENDED_NAME in
    'pd')
        CDEXTENDED_EXEMODE='backward'
        ;;
    'nd')
        CDEXTENDED_EXEMODE='forward'
        ;;
    *)
        CDEXTENDED_EXEMODE='none'
        ;;
esac

# detect if the verbose option is present
CDEXTENDED_VFLAG=0
for tmp_arg in "$@"; do
    if [ tmp_arg == '-v' ] || [ tmp_arg == '--verbose' ]; then
        CDEXTENDED_VFLAG=1
        break
    fi
done
unset tmp_arg

# execute the main process
if [ -f $BRANCH_DIRHIST_PATH ] && [ -r $BRANCH_DIRHIST_PATH ] &&
    [ -f $CDEXTENDED_DIRCTL ] && [ -x $CDEXTENDED_DIRCTL ];
then
    CDEXTENDED_SOURCE=$(pwd)
    CDEXTENDED_DEST=$($CDEXTENDED_DIRCTL $CDEXTENDED_EXEMODE \
        $CDEXTENDED_CTLPRT $BRANCH_DIRHIST_PATH \
        $CDEXTENDED_NAME $@\)
    CDEXTENDED_EXITSTAT=$?

    if [ $CDEXTENDED_EXITSTAT -eq 0 ]; then
        if [ ${CDEXTENDED_DEST:0:1} == '/' ]; then
            builtin cd $CDEXTENDED_DEST
            CDEXTENDED_EXITSTAT=$?

            if [ $CDEXTENDED_EXITSTAT -eq 0 ]; then
                if [ $CDEXTENDED_VFLAG -eq 1 ]; then
                    echo $CDEXTENDED_DEST
                else
                    $CDEXTENDED_DIRCTL $CDEXTENDED_EXEMODE \
                        $CDEXTENDED_CTLEXEC $BRANCH_DIRHIST_PATH \
                        $CDEXTENDED_SOURCE $CDEXTENDED_DEST \
                        $CDEXTENDED_NAME $@ >/dev/null 2>&1
                fi
            fi
        else
            echo "$CDEXTENDED_DEST"
        fi
    fi
fi

# unset variables
unset CDEXTENDED_DIRCTL
unset CDEXTENDED_CTLPRT
unset CDEXTENDED_CTLEXEC
unset CDEXTENDED_NAME
unset CDEXTENDED_EXEMODE
unset CDEXTENDED_VFLAG
unset CDEXTENDED_SOURCE
unset CDEXTENDED_DEST

# return
case $CDEXTENDED_EXITSTAT in
    0)
        unset CDEXTENDED_EXITSTAT
        true
        ;;
    *)
        unset CDEXTENDED_EXITSTAT
        false
        ;;
esac
