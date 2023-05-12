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
    return R"(Usage: pd [NUMBER] [OPTION]
Switches the working directory to the previous working directory.

It also allows you to navigate to even earlier working directories through
options and parameters.

Mandatory arguments to long options are mandatory for short options too.
  -h, --help                 display this help and exit
  -n, --number=NUMBER        go back to the previous NUMBER directories)";
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
