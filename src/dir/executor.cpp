#include <iostream>
#include "executor.hpp"
#include "util/errorhandler.hpp"

Executor::Executor(const std::string path) : Controller(path) {}

Executor::~Executor() {}

Executor & Executor::execute() {
    executeImpl();
    return * this;
}

void Executor::executeImpl() {
    if (helpOption) {
        printDocument();
    } else {
        act();
    }
}

void Executor::printDocument() const {
    std::cout << document << std::flush;
}

void Executor::act() {
    switch (executionAction) {
        case ACTION_PRINT:
            doPrintAction();
            break;
        case ACTION_EXECUTE:
            doExecuteAction();
            break;
        default:
            doNoneAction();
    }
}

void Executor::doPrintAction() {}

void Executor::doExecuteAction() {}

void Executor::doNoneAction() {
    ErrorHandler::terminate(PHARSE_ERROR_ARG_NO_EXECUTION_ACTION);
}
