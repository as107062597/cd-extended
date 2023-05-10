#ifndef __BACKWARD_EXECUTOR_HPP__
#define __BACKWARD_EXECUTOR_HPP__

#include "editableexecutor.hpp"

class BackwardExecutor : public EditableExecutor {
public:
    BackwardExecutor(const std::string path);

    ~BackwardExecutor();

protected:
    virtual void doPrintAction();

    virtual void doExecuteAction();

    virtual std::string document() const;

private:
    void assertNumber() const;

    void assertDestination() const;

    void printAction();

    void printActionImpl();

    void executeAction();

    void executeActionImpl();

};

#endif
