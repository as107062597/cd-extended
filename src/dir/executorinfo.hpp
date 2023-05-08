#ifndef __EXECUTOR_INFO_HPP__
#define __EXECUTOR_INFO_HPP__

#include <string>
#include "executionmode.hpp"
#include "executionaction.hpp"

class ExecutorInfo {
public:
    ExecutorInfo();

    ~ExecutorInfo();

    ExecutorInfo & setExecutionMode(const ExecutionMode executionMode);

    ExecutionMode getExecutionMode () const;

    ExecutorInfo & setExecutionAction(const ExecutionAction executionAction);

    ExecutionAction getExecutionAction () const;

    ExecutorInfo & setHelpOption(const bool helpOption);

    bool getHelpOption() const;

    ExecutorInfo & setNumber(const int number);

    int getNumber() const;

    ExecutorInfo & setName(const std::string name);

    std::string getName() const;

    ExecutorInfo & setFilePath(const std::string filePath);

    std::string getFilePath() const;

    ExecutorInfo & setSource(const std::string source);

    std::string getSource() const;

    ExecutorInfo & setDestination(const std::string destination);

    std::string getDestination() const;

private:
    ExecutionMode executionMode     = MODE_NONE;

    ExecutionAction executionAction = ACTION_NONE;

    bool helpOption                 = false;

    int number                      = 1;

    std::string name                = "";

    std::string filePath            = "";

    std::string source              = "";

    std::string destination         = "";

};

#endif
