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
    assertMarker();
    assertSource();
    executeAction();
}

std::string SwitchExecutor::document() const {
    return R"(--NONE--)";
}

void SwitchExecutor::executeAction() {
    executeActionImpl();
}

void SwitchExecutor::executeActionImpl() {
    move(number).prune().record(destination);
}
