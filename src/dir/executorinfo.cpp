#include "executorinfo.hpp"

ExecutorInfo::ExecutorInfo() {}

ExecutorInfo::~ExecutorInfo() {}

ExecutorInfo & ExecutorInfo::setExecutionMode(
    const ExecutionMode executionMode
) {
    this->executionMode = executionMode;
    return * this;
}

ExecutionMode ExecutorInfo::getExecutionMode () const {
    return executionMode;
}

ExecutorInfo & ExecutorInfo::setExecutionAction(
    const ExecutionAction executionAction
) {
    this->executionAction = executionAction;
    return * this;
}

ExecutionAction ExecutorInfo::getExecutionAction () const {
    return executionAction;
}

ExecutorInfo & ExecutorInfo::setHelpOption(const bool helpOption) {
    this->helpOption = helpOption;
    return * this;
}

bool ExecutorInfo::getHelpOption() const {
    return helpOption;
}

ExecutorInfo & ExecutorInfo::setNumber(const int number) {
    this->number = number;
    return * this;
}

int ExecutorInfo::getNumber() const {
    return number;
}

ExecutorInfo & ExecutorInfo::setName(const std::string name) {
    this->name = name;
    return * this;
}

std::string ExecutorInfo::getName() const {
    return name;
}

ExecutorInfo & ExecutorInfo::setFilePath(const std::string filePath) {
    this->filePath = filePath;
    return * this;
}

std::string ExecutorInfo::getFilePath() const {
    return filePath;
}

ExecutorInfo & ExecutorInfo::setSource(const std::string source) {
    this->source = source;
    return * this;
}

std::string ExecutorInfo::getSource() const {
    return source;
}

ExecutorInfo & ExecutorInfo::setDestination(const std::string destination) {
    this->destination = destination;
    return * this;
}

std::string ExecutorInfo::getDestination() const {
    return destination;
}
