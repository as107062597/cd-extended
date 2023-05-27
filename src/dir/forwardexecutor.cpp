#include "forwardexecutor.hpp"
#include "util/errorhandler.hpp"
#include "tr/translator.hpp"

ForwardExecutor::ForwardExecutor(
    const std::string path
) : EditableExecutor(path) {}

ForwardExecutor::~ForwardExecutor() {}

void ForwardExecutor::doPrintAction() {
    assertValid();
    printAction();
}

void ForwardExecutor::doExecuteAction() {
    assertMarker();
    assertSource();
    executeAction();
}

std::string ForwardExecutor::document() const {
    return R"(Usage: nd [NUMBER]
  or:  nd [OPTION]
Switches the working directory to the next working directory.

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
  -n, --number=NUMBER        go ahead to the next NUMBER directories
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

void ForwardExecutor::assertNumber() const {
    if (!isIndexValid(marker + number)) {
        ErrorHandler::terminate(name + ": " + Translator::tr(
            number == 1 ?
                PHARSE_MESSAGE_ALREADY_ON_LAST_DIRECTORY :
                PHARSE_MESSAGE_TOO_MANY_DIRECTORIES_TO_GO_AHEAD
        ));
    }
}

void ForwardExecutor::assertDestination() const {
    if (entries.at(marker + number) != destination) {
        ErrorHandler::terminate(PHARSE_ERROR_UNEXPECTED_DESTINATION);
    }
}

void ForwardExecutor::printAction() {
    assertNumber();
    printActionImpl();
}

void ForwardExecutor::printActionImpl() {
    print(marker + number);
}

void ForwardExecutor::executeAction() {
    assertNumber();
    assertDestination();
    executeActionImpl();
}

void ForwardExecutor::executeActionImpl() {
    move(number);
}
