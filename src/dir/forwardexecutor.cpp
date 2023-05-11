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
    assertValid();
    executeAction();
}

std::string ForwardExecutor::document() const {
    return R"(Usage: nd [OPTION]
Switches the working directory to the next working directory.

It also allows you to navigate to even earlier working directories through
options and parameters.

Mandatory arguments to long options are mandatory for short options too.
  -h, --help                 display this help and exit
  -n, --number=NUMBER        go ahead to the next NUMBER directories)";
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
