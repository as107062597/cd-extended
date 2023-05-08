#include "editableexecutor.hpp"

EditableExecutor::EditableExecutor(const std::string path) : Executor(path) {}

EditableExecutor::~EditableExecutor() {}

EditableExecutor & EditableExecutor::setExecutionAction(
    const ExecutionAction executionAction
) {
    this->executionAction = executionAction;
    return * this;
}

EditableExecutor & EditableExecutor::setHelpOption(const bool helpOption) {
    this->helpOption = helpOption;
    return * this;
}

EditableExecutor & EditableExecutor::setNumber(const int number) {
    this->number = number;
    return * this;
}

EditableExecutor & EditableExecutor::setName(const std::string name) {
    this->name = name;
    return * this;
}

EditableExecutor & EditableExecutor::setSource(const std::string source) {
    this->source = source;
    return * this;
}

EditableExecutor & EditableExecutor::setDestination(
    const std::string destination
) {
    this->destination = destination;
    return * this;
}
