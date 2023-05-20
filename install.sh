echo "activate cd-extended ..."

if [ -f $HOME/.bashrc ]; then
    if [ -r $HOME/.bashrc ]; then
        . $HOME/.bashrc
    fi
fi
