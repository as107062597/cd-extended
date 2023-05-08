#include <iostream>
#include "executor.hpp"
#include "util/errorhandler.hpp"

Executor::Executor(const std::string path) : Controller(path) {
    setActions();
}

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
    std::cout << document() << std::flush;
}

void Executor::act() {
    (this->*(actions[executionAction]))();
}

void Executor::doNoneAction() {
    ErrorHandler::terminate(PHARSE_ERROR_NO_EXECUTABLE_ACTION_AVAILABLE);
}

void Executor::doPrintAction() {
    ErrorHandler::terminate(PHARSE_ERROR_PRINT_ACTION_IS_NOT_DEFINE);
}

void Executor::doExecuteAction() {
    ErrorHandler::terminate(PHARSE_ERROR_EXECUTE_ACTION_IS_NOT_DEFINE);
}

std::string Executor::document() const {
    ErrorHandler::terminate(PHARSE_ERROR_DOCUMENT_IS_NOT_DEFINE);
    return "";
}

void Executor::setActions() {
    actions[ACTION_PRINT] = &Executor::doPrintAction;
    actions[ACTION_EXECUTE] = &Executor::doExecuteAction;
    actions[ACTION_NONE] = &Executor::doNoneAction;
    actions.push_back(&Executor::doNoneAction);
}
