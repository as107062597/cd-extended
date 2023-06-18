echo 'deactivate cd-extended ...'

function cd_extended_deactivate() {
    if [ -n "$1" ]; then
        alias | grep "alias $1=">/dev/null

        if [ $? -eq 0 ]; then
            unalias $1
        fi
    fi
}

cd_extended_deactivate cd
cd_extended_deactivate sd
cd_extended_deactivate pd
cd_extended_deactivate nd
