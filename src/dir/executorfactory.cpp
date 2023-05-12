#include "executorfactory.hpp"
#include "editableexecutor.hpp"

ExecutorFactory::ExecutorFactory() {};

ExecutorFactory::~ExecutorFactory() {};

ExecutorFactory & ExecutorFactory::setExecutionAction(
    const ExecutionAction executionAction
) {
    this->executionAction = executionAction;
    return * this;
}

ExecutorFactory & ExecutorFactory::setHelpOption(const bool helpOption) {
    this->helpOption = helpOption;
    return * this;
}

ExecutorFactory & ExecutorFactory::setNumber(const int number) {
    this->number = number;
    return * this;
}

ExecutorFactory & ExecutorFactory::setName(const std::string name) {
    this->name = name;
    return * this;
}

ExecutorFactory & ExecutorFactory::setPath(const std::string path) {
    this->path = path;
    return * this;
}

ExecutorFactory & ExecutorFactory::setSource(const std::string source) {
    this->source = source;
    return * this;
}

ExecutorFactory & ExecutorFactory::setDestination(
    const std::string destination
) {
    this->destination = destination;
    return * this;
}

Executor * ExecutorFactory::getExecutor() const {
    return &(
        static_cast<EditableExecutor *>(createExecutor())
            ->setExecutionAction(executionAction)
            .setHelpOption(helpOption)
            .setNumber(number)
            .setName(name)
            .setSource(source)
            .setDestination(destination)
    );
}
