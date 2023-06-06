#ifndef __EXECUTOR_INFO_HPP__
#define __EXECUTOR_INFO_HPP__

#include <string>
#include "executionaction.hpp"
#include "executionmode.hpp"

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

    ExecutorInfo & setNumber(const bool number);

    ExecutorInfo & setListSize();

    ExecutorInfo & setListSize(const int listSize);

    ExecutorInfo & setAfterTimestamp(const long long afterTimestamp);

    ExecutorInfo & setAfterTimestamp(const std::string timeString);

    ExecutorInfo & setBeforeTimestamp(const long long beforeTimestamp);

    ExecutorInfo & setBeforeTimestamp(const std::string timeString);

private:
    ExecutionAction executionAction;

    ExecutionMode executionMode;

    bool helpOption;

    bool timeOption;

    bool verboseOption;

    bool versionOption;

    int number;

    int listSize;

    long long afterTimestamp;

    long long beforeTimestamp;

    void assert() const;

};

#endif
