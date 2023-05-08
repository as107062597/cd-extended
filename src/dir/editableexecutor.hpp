#ifndef __EDITABLE_EXECUTOR_HPP__
#define __EDITABLE_EXECUTOR_HPP__

#include "executor.hpp"

class EditableExecutor : public Executor {
public:
    EditableExecutor & setExecutionAction(
        const ExecutionAction executionAction);

    EditableExecutor & setHelpOption(const bool helpOption);

    EditableExecutor & setNumber(const int number);

    EditableExecutor & setName(const std::string name);

    EditableExecutor & setSource(const std::string source);

    EditableExecutor & setDestination(const std::string destination);

protected:
    EditableExecutor(const std::string path);

    ~EditableExecutor() = 0;

};

#endif
