# **cd-extended**
Version: 1.0.2\
Release date: 05/20/2023

## Author
- Neil Chen

## Introduction
This is a project for Linux platform that makes changing directories more convenient. It automatically records directories visited by the user through the existing ```cd``` command by using additional files and programs. Moreover, it provides the ```pd``` and ```nd``` commands to help users shuttle between these directories more easily and quickly.

#### **```pd```**: **previous-directory**
- This command switches the working directory to the previous working directory. It also allows you to navigate to even earlier working directories through options and parameters.

#### **```nd```**: **next-directory**
- This command helps the user to return to an even earlier working directory when using the ```pd``` command to go back to a previous working directory. It also allows the user to switch to a later visited working directory through options and parameters.

## Usage
The commands ```pd``` and ```nd``` are similar to the *back* and *forward* buttons in a web browser, respectively. As their names suggest, they allow users to navigate through previously visited directories. Here are the usage and formats for them:

#### ```pd``` [NUMBER]
- Switch the working directory to the *NUMBER*-th directory in reverse order. If *NUMBER* is not specified, go to the previous directory.

#### ```nd``` [NUMBER]
- Change the current working directory to the *NUMBER*-th directory after the current one. Go to the next directory if *NUMBER* is not specified.

You can add the option ```--help``` when issuing commands to get more detailed usage information.

## Install
First, please make sure that your computer has *g++* version **8.1** or **higher** installed before proceeding with the installation.

Afterward, you need to clone this repository.

    git clone https://github.com/as107062597/cd-extended.git

Navigate to the downloaded repository folder after the program finishes.

    cd cd-extended

Then compile the program in the folder.

    make

Install the compiled scripts and binaries.

    make install

Finally, apply the settings that were just configured to the environment.

    . shell start

## Upgrade
After pulling the more recent version of *cd-extended*, you can use the following command to complete the update.

    make upgrade

Finally, make the shell take effect

    . shell start

## Uninstall
You can first undo the environment setting after entering the repository directory, the *cd-extended* folder.

    . shell stop

Next, remove the installed scripts and binaries from the environment.

    make uninstall

You can remove the compiled files if necessary.

    make clean

## Troubleshooting
If this package has caused inconvenience to your environment or unexpected exceptions have occurred, preventing you from accessing the folder where the package was installed, you can use the following method to remove this package directly from the Bash environment.

    unalias cd pd nd
    rm -f ~/.local/etc/bashrc.d/cd-extended.sh

Note that this operation will not completely remove all installed files. Please proceed to the package's folder and complete the removal process after resolving the exceptions.

## License
*cd-extended* is distributed under the *MIT* license, which allows for the modification and redistribution of the code. For more details, please refer to the *LICENSE* file.

Please note that while we have made every effort to ensure the functionality of this repository, we cannot guarantee that it will work flawlessly in every situation. Users assume all risks associated with the use of this code.

Additionally, we cannot guarantee that updates will be provided in a timely manner. However, we welcome any contributions or feedback from users to help improve the code.
