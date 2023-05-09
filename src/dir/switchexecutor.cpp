#include "switchexecutor.hpp"
#include "util/errorhandler.hpp"

SwitchExecutor::SwitchExecutor(
    const std::string path
) : EditableExecutor(path) {}

SwitchExecutor::~SwitchExecutor() {}

void SwitchExecutor::doPrintAction() {
    ErrorHandler::terminate(PHARSE_ERROR_PRINT_ACTION_IS_NOT_DEFINE);
}

void SwitchExecutor::doExecuteAction() {
    executeAction();
}

std::string SwitchExecutor::document() const {
    return R"(--NONE--)";
}

void SwitchExecutor::executeAction() {
    if (isValid()) {
        executeActionImpl();
    } else {
        ErrorHandler::terminate(PHARSE_ERROR_FORMAT_DIRHIST_FILE_IS_INCORRECT);
    }
}

void SwitchExecutor::executeActionImpl() {
    move(number).prune().record(destination);
}
