#include "backwardexecutor.hpp"
#include "util/errorhandler.hpp"
#include "tr/translator.hpp"

BackwardExecutor::BackwardExecutor(
    const std::string path
) : EditableExecutor(path) {}

BackwardExecutor::~BackwardExecutor() {}

void BackwardExecutor::doPrintAction() {
    assertValid();
    printAction();
}

void BackwardExecutor::doExecuteAction() {
    assertMarker();
    assertSource();
    executeAction();
}

std::string BackwardExecutor::document() const {
    return R"(Usage: pd [NUMBER]
  or:  pd [OPTION]
Switches the working directory to the previous working directory.

It also allows you to navigate to even earlier working directories through
options and parameters.

Mandatory arguments to long options are mandatory for short options too.
  -a, --after=DURATION       print the directories visited after a time point
                               DURATION earlier than the current time
      --after-timestamp=TIMESTAMP
                             display the directories visited after TIMESTAMP
  -b, --before=DURATION      output the directories that were visited prior to
                               a time point DURATION earlier than the current
                               time
      --before-timestamp=TIMESTAMP
                             display the directories visited before TIMESTAMP
  -t, --time                 show visited timestamp when list directory history
  -h, --help                 display this help and exit
  -l, --list[=SIZE]          exhibit SIZE most recently visited and changeable
                               directories, defaulting to all directories
  -n, --number=NUMBER        go back to the previous NUMBER directories
  -v, --verbose              explain what is being done
  -V, --version              output version information and exit

The format of DURATION is <day>d|<hour>h|<minute>m|<second>s. For example, you
can use the following phrase to express one day and a half: 1d12h

The TIMESTAMP argument is composed of <yyyy>, <MM>, <dd>, <HH>, <mm> and <ss>,
representing year, month, day, hour, minute and second respectively.

TIMESTAMP format:
  <HH>:<mm>[:<ss>]
  [<yyyy>-]<MM>-<dd>
  [<yyyy>-]<MM>-<dd>T<HH>:<mm>[:<ss>]

More information is available on GitHub: <https://github.com/as107062597/>)";
}

void BackwardExecutor::assertNumber() const {
    if (!isIndexValid(marker - number)) {
        ErrorHandler::terminate(name + ": " + Translator::tr(
            number == 1 ?
                PHARSE_MESSAGE_ALREADY_ON_FIRST_DIRECTORY :
                PHARSE_MESSAGE_TOO_MANY_DIRECTORIES_TO_GO_BACK
        ));
    }
}

void BackwardExecutor::assertDestination() const {
    if (entries.at(marker - number) != destination) {
        ErrorHandler::terminate(PHARSE_ERROR_UNEXPECTED_DESTINATION);
    }
}

void BackwardExecutor::printAction() {
    assertNumber();
    printActionImpl();
}

void BackwardExecutor::printActionImpl() {
    print(marker - number);
}

void BackwardExecutor::executeAction() {
    assertNumber();
    assertDestination();
    executeActionImpl();
}

void BackwardExecutor::executeActionImpl() {
    move(-number);
}
