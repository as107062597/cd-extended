# Move the contents of the branch dir.hist file for this session to the
# main dir.hist file
if [ -n "$DIRHIST_PATH" ] &&
    [ -d $(dirname $DIRHIST_PATH) ] &&
    [ -n "$BRANCH_DIRHIST_PATH" ] &&
    [ -f $BRANCH_DIRHIST_PATH ] &&
    [ -r $BRANCH_DIRHIST_PATH ];
then
    tail -n +2 $BRANCH_DIRHIST_PATH > $DIRHIST_PATH
    rm -f $BRANCH_DIRHIST_PATH
fi
