echo "deactivate cd-extended ..."

alias | grep "alias cd=">/dev/null

if [ $? -eq 0 ]; then
    unalias cd
fi

alias | grep "alias pd=">/dev/null

if [ $? -eq 0 ]; then
    unalias pd
fi

alias | grep "alias nd=">/dev/null

if [ $? -eq 0 ]; then
    unalias nd
fi
