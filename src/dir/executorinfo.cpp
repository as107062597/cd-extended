#include <climits>
#include "executorinfo.hpp"
#include "error.hpp"
#include "setting.hpp"

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
#define DEFAULT_NAME                "dirctl"
#define NEW_LINE                    "\n"
#define MESSAGE_HEADER_SIGN         ": "
#define IS_DURATION_REGEX           ""
#define GET_DURATION_REGEX          R"(\d+[DdHhMmSs])"

std::unique_ptr< Translator > ExecutorInfo::translator (
    USER_SETTING_USE_CURRENT_ENV_LANG ?
        std::make_unique< Translator >() :
        std::make_unique< Translator >(USER_SETTING_LANG)
);

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
    beforeTimestamp { DEFAULT_BEFORE_TIMESTAMP },
    name            { DEFAULT_NAME }
{}

ExecutorInfo::~ExecutorInfo() {}

ExecutorInfo & ExecutorInfo::setExecutionAction(
    const ExecutionAction executionAction
) {
    if (executionAction != ACTION_NONE && executionAction != ACTION_COUNT) {
        this->executionAction = executionAction;
    } else {
        throwError(PHRASE_ERROR_MESSAGE_INVALID_EXECUTION_ACTION);
    }
    return * this;
}

ExecutorInfo & ExecutorInfo::setExecutionMode(
    const ExecutionMode executionMode
) {
    if (executionMode != MODE_NONE && executionMode != MODE_COUNT) {
        this->executionMode = executionMode;
    } else {
        throwError(PHRASE_ERROR_MESSAGE_INVALID_EXECUTION_MODE);
    }
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

ExecutorInfo & ExecutorInfo::setNumber(const int number) {
    if (number >= 1) {
        this->number = number;
    } else {
        throwErrorWithHelpExample(PHRASE_ERROR_MESSAGE_INVALID_NUMBER_OPTION);
    }
    return * this;
}

ExecutorInfo & ExecutorInfo::setListSize() {
    return setListSize(INT_MAX);
}

ExecutorInfo & ExecutorInfo::setListSize(const int listSize) {
    if (listSize >= 1) {
        this->listSize = listSize;
    } else {
        throwErrorWithHelpExample(PHRASE_ERROR_MESSAGE_INVALID_LIST_OPTION);
    }
    return * this;
}

ExecutorInfo & ExecutorInfo::setAfterTimestamp(const time_t afterTimestamp) {
    if (afterTimestamp >= 0) {
        this->afterTimestamp = afterTimestamp;
    } else {
        throwError(PHRASE_ERROR_MESSAGE_INVALID_TIMESTAMP);
    }
    return * this;
}

ExecutorInfo & ExecutorInfo::setAfterTimestamp(
    const std::string & timeString
) {
    setAfterTimestamp(
        isDuration(timeString) ?
            getTimestampByDuration(timeString) :
            getTimestampByIso8601(timeString)
    );
    return * this;
}

ExecutorInfo & ExecutorInfo::setBeforeTimestamp(const time_t beforeTimestamp) {
    if (beforeTimestamp >= 0) {
        this->beforeTimestamp = beforeTimestamp;
    } else {
        throwError(PHRASE_ERROR_MESSAGE_INVALID_TIMESTAMP);
    }
    return * this;
}

ExecutorInfo & ExecutorInfo::setBeforeTimestamp(
    const std::string & timeString
) {
    setBeforeTimestamp(
        isDuration(timeString) ?
            getTimestampByDuration(timeString) :
            getTimestampByIso8601(timeString)
    );
    return * this;
}

ExecutorInfo & ExecutorInfo::setName(const std::string & name) {
    this->name = name;
    return * this;
}

void ExecutorInfo::assert() const {

}

void ExecutorInfo::throwError(const Phrase phrase) const {
    throwError(phrase, false);
}

void ExecutorInfo::throwErrorWithHelpExample(const Phrase phrase) const {
    throwError(phrase, true);
}

void ExecutorInfo::throwError(const Phrase phrase, const bool showHelp) const {
    throw Error(
        ERROR_TYPE_RUNTIME_ERROR,
        showHelp ?
            generateMessageWithHelpExample(phrase) :
            generateMessage(phrase)
    );
}

std::string ExecutorInfo::getMessageHeader() const {
    return name + MESSAGE_HEADER_SIGN;
}

std::string ExecutorInfo::attachHeader(const std::string & message) const {
    return getMessageHeader() + message;
}

std::string ExecutorInfo::generateMessage(const Phrase phrase) const {
    return attachHeader(translator->tr(phrase));
}

std::string ExecutorInfo::generateMessageWithHelpExample(
    const Phrase phrase
) const {
    return generateMessage(phrase) + NEW_LINE + getShowHelpExample();
}

std::string ExecutorInfo::getShowHelpExample() const {
    return translator->tr(PHRASE_MESSAGE_HELP_EXAMPLE_PART_1)
        + name
        + translator->tr(PHRASE_MESSAGE_HELP_EXAMPLE_PART_2);
}

bool ExecutorInfo::isDuration(const std::string & timeString) {
    // for (char letter : TIME_UNITS) {
    //     if (timeString.find_first_of(letter) != std::string::npos) {
    //         return true;
    //     }
    // }
    return false;
}

time_t ExecutorInfo::getTimestampByDuration(const std::string & duration) {
    return 1;
}

time_t ExecutorInfo::getTimestampByIso8601(const std::string & iso8601) {
    return -1;
}
