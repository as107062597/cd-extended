#include <climits>
#include "dir/executorinfo.hpp"

#define DEFAULT_EXECUTION_ACTION    ACTION_NONE
#define DEFAULT_EXECUTION_MODE      MODE_NONE
#define DEFAULT_HELP_OPTION         false
#define DEFAULT_TIME_OPTION         false
#define DEFAULT_VERBOSE_OPTION      false
#define DEFAULT_VERSION_OPTION      false
#define DEFAULT_NUMBER              1
#define DEFAULT_LIST_SIZE           0
#define DEFAULT_AFTER_TIMESTAMP     0
#define DEFAULT_BEFORE_TIMESTAMP    LLONG_MAX

ExecutorInfo::ExecutorInfo() :
    executionAction { DEFAULT_EXECUTION_ACTION },
    executionMode   { DEFAULT_EXECUTION_MODE },
    helpOption      { DEFAULT_HELP_OPTION },
    timeOption      { DEFAULT_TIME_OPTION },
    verboseOption   { DEFAULT_VERBOSE_OPTION },
    versionOption   { DEFAULT_VERSION_OPTION },
    number          { DEFAULT_NUMBER },
    listSize        { DEFAULT_LIST_SIZE },
    afterTimestamp  { DEFAULT_AFTER_TIMESTAMP },
    beforeTimestamp { DEFAULT_BEFORE_TIMESTAMP }
{}

ExecutorInfo::~ExecutorInfo() {}

ExecutorInfo & ExecutorInfo::setExecutionAction(
    const ExecutionAction executionAction
) {
    this->executionAction = executionAction;
    return * this;
}

ExecutorInfo & ExecutorInfo::setExecutionMode(
    const ExecutionMode executionMode
) {
    this->executionMode = executionMode;
    return * this;
}

ExecutorInfo & ExecutorInfo::setHelpOption() {
    return setHelpOption(true);
}

ExecutorInfo & ExecutorInfo::setHelpOption(const bool helpOption) {
    this->helpOption = helpOption;
    return * this;
}

ExecutorInfo & ExecutorInfo::setTimeOption() {
    return setTimeOption(true);
}

ExecutorInfo & ExecutorInfo::setTimeOption(const bool timeOption) {
    this->timeOption = timeOption;
    return * this;
}

ExecutorInfo & ExecutorInfo::setVerboseOption() {
    return setVerboseOption(true);
}

ExecutorInfo & ExecutorInfo::setVerboseOption(const bool verboseOption) {
    this->verboseOption = verboseOption;
    return * this;
}

ExecutorInfo & ExecutorInfo::setVersionOption() {
    return setVersionOption(true);
}

ExecutorInfo & ExecutorInfo::setVersionOption(const bool versionOption) {
    this->versionOption = versionOption;
    return * this;
}

ExecutorInfo & ExecutorInfo::setNumber(const bool number) {
    this->number = number;
    return * this;
}

ExecutorInfo & ExecutorInfo::setListSize() {
    return setListSize(INT_MAX);
}

ExecutorInfo & ExecutorInfo::setListSize(const int listSize) {
    this->listSize = listSize;
    return * this;
}

ExecutorInfo & ExecutorInfo::setAfterTimestamp(
    const long long afterTimestamp
) {
    this->afterTimestamp = afterTimestamp;
    return * this;
}

ExecutorInfo & ExecutorInfo::setAfterTimestamp(
    const std::string timeString
) {
    return * this;
}

ExecutorInfo & ExecutorInfo::setBeforeTimestamp(
    const long long beforeTimestamp
) {
    this->beforeTimestamp = beforeTimestamp;
    return * this;
}

ExecutorInfo & ExecutorInfo::setBeforeTimestamp(const std::string timeString) {
    return * this;
}

void ExecutorInfo::assert() const {

}
