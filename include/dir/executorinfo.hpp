#ifndef __EXECUTOR_INFO_HPP__
#define __EXECUTOR_INFO_HPP__

#include <memory>
#include <string>
#include "executionaction.hpp"
#include "executionmode.hpp"
#include "tr/translator.hpp"

class ExecutorInfo {
public:
    explicit ExecutorInfo();

    ~ExecutorInfo();

    ExecutorInfo & setExecutionAction(const ExecutionAction executionAction);

    ExecutorInfo & setExecutionMode(const ExecutionMode executionMode);

    ExecutorInfo & setHelpOption();

    ExecutorInfo & setHelpOption(const bool helpOption);

    ExecutorInfo & setTimeOption();

    ExecutorInfo & setTimeOption(const bool timeOption);

    ExecutorInfo & setVerboseOption();

    ExecutorInfo & setVerboseOption(const bool verboseOption);

    ExecutorInfo & setVersionOption();

    ExecutorInfo & setVersionOption(const bool versionOption);

    ExecutorInfo & setNumber(const int number);

    ExecutorInfo & setListSize();

    ExecutorInfo & setListSize(const int listSize);

    ExecutorInfo & setAfterTimestamp(const time_t afterTimestamp);

    ExecutorInfo & setAfterTimestamp(const std::string & timeString);

    ExecutorInfo & setBeforeTimestamp(const time_t beforeTimestamp);

    ExecutorInfo & setBeforeTimestamp(const std::string & timeString);

    ExecutorInfo & setName(const std::string & name);

private:
    ExecutionAction executionAction;

    ExecutionMode executionMode;

    bool helpOption;

    bool timeOption;

    bool verboseOption;

    bool versionOption;

    int number;

    int listSize;

    time_t afterTimestamp;

    time_t beforeTimestamp;

    std::string name;

    static std::unique_ptr< Translator > translator;

    void assert() const;

    void throwError(const Phrase phrase) const;

    void throwErrorWithHelpExample(const Phrase phrase) const;

    void throwError(const Phrase phrase, const bool showHelp) const;

    std::string getMessageHeader() const;

    std::string attachHeader(const std::string & message) const;

    std::string generateMessage(const Phrase phrase) const;

    std::string generateMessageWithHelpExample(const Phrase phrase) const;

    std::string getShowHelpExample() const;

    static bool isDuration(const std::string & timeString);

    static time_t getTimestampByDuration(const std::string & duration);

    static time_t getTimestampByIso8601(const std::string & iso8601);

};

#endif
