**cd-extended**
===============
version: 1.0.0\
Release date: 05/13/2023

Author
======
- Neil Chen

Introduction
============
This is a project for Linux platform that makes changing directories more convenient. It automatically records directories visited by the user through the existing ```cd``` command by using additional files and programs. Moreover, it provides the ```pd``` and ```nd``` commands to help users shuttle between these directories more easily and quickly.

#### **```pd```**: **previous-directory**
+ This command switches the working directory to the previous working directory. It also allows you to navigate to even earlier working directories through options and parameters.
#### **```nd```**: **next-directory**
+ This command helps the user to return to an even earlier working directory when using the ```pd``` command to go back to a previous working directory. It also allows the user to switch to a later visited working directory through options and parameters.

Usage
=====
The commands ```pd``` and ```nd``` are similar to the *back* and *forward* buttons in a web browser, respectively. As their names suggest, they allow users to navigate through previously visited directories. Here are the detailed usage and formats for them:
#### ```pd``` [-*n* NUMBER]
- Switch the working directory to the *n*-th directory in reverse order. If *n* is not specified, go to the previous directory.
#### ```nd``` [-*n* NUMBER]
- Change the current working directory to the *n*-th directory after the current one. Go to the next directory if *n* is not specified.

Install
=======
You can install the tool by following these steps after cloning this repository.\
First, you need to clone this repository.

    git clone https://github.com/as107062597/cd-extended.git

Navigate to the downloaded repository folder after the program finishes.

    cd cd-extended

Then compile the program in the folder.

    make

Install the compiled scripts and binaries.

    make install

Finally, apply the settings that were just configured to the environment.

    . install-shell

Uninstall
=========
You can first undo the alias setting if these commands becomes unavailable due to certain reasons.

    unalias cd pd nd

You can first undo the environment setting after entering the repository directory, the *cd-extended* folder.

    . uninstall-shell

Next, remove the installed scripts and binaries from the environment.

    make uninstall

You can remove the compiled files if necessary.

    make clean

License
=======
*cd-extended* is distributed under the MIT license, which allows for the modification and redistribution of the code. For more details, please refer to the *LICENSE* file.

Please note that while we have made every effort to ensure the functionality of this repository, we cannot guarantee that it will work flawlessly in every situation. Users assume all risks associated with the use of this code.

Additionally, we cannot guarantee that updates will be provided in a timely manner. However, we welcome any contributions or feedback from users to help improve the code.
