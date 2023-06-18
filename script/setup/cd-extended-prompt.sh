###############################################################################
#                                                                             #
#                         cd-extended bash-completion                         #
#                                                                             #
###############################################################################

# completion when use sd command
__cd-extended_completion() {
    local cur opts
    COMPREPLY=()
    cur="${COMP_WORDS[COMP_CWORD]}"
    alias | grep "alias sd=">/dev/null
    if [ $? -eq 0 ] && [ ${COMP_CWORD} -eq 1 ]; then
        opts="next prev"
        COMPREPLY=( $(compgen -W "${opts}" -- ${cur}) )
    fi
    return 0
}

complete -F __cd-extended_completion sd
