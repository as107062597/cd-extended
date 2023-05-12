#ifndef __EXECUTOR_FACTORY_HPP__
#define __EXECUTOR_FACTORY_HPP__

#include "editableexecutor.hpp"

class ExecutorFactory {
public:
    ExecutorFactory();

    virtual ~ExecutorFactory() = 0;

    virtual ExecutorFactory & setExecutionAction(
        const ExecutionAction executionAction);

    virtual ExecutorFactory & setHelpOption(const bool helpOption);

    virtual ExecutorFactory & setNumber(const int number);

    virtual ExecutorFactory & setName(const std::string name);

    virtual ExecutorFactory & setPath(const std::string path);

    virtual ExecutorFactory & setSource(const std::string source);

    virtual ExecutorFactory & setDestination(const std::string destination);

    virtual Executor * getExecutor() const;

protected:
    ExecutionAction executionAction;

    bool helpOption;

    int number;

    std::string name;

    std::string path;

    std::string source;

    std::string destination;

    virtual Executor * createExecutor() const = 0;

};

#endif
