if [ $# -lt 1 ]; then
    echo 'shell: missing operand'
    echo "Try 'shell --help' for more information"
    false
elif [ $# -gt 1 ]; then
    echo 'shell: too many argumens'
    echo "Try 'shell --help' for more information"
    false
elif [ $1 == '-h' ] || [ $1 == '--help' ]; then
    echo "Usage: . shell start|stop"
elif [ $1 == 'start' ]; then
    echo 'activate cd-extended ...'

    if [ -f $HOME/.bashrc ]; then
        if [ -r $HOME/.bashrc ]; then
            . $HOME/.bashrc
        fi
    fi
elif [ $1 == 'stop' ]; then
    echo 'deactivate cd-extended ...'

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
else
    echo "shell: '$1' is not a valid option"
    echo 'Usage: . shell start|stop'
fi
