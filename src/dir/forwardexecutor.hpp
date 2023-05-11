#ifndef __FORWARD_EXECUTOR_HPP__
#define __FORWARD_EXECUTOR_HPP__

#include "editableexecutor.hpp"

class ForwardExecutor : public EditableExecutor {
public:
    ForwardExecutor(const std::string path);

    ~ForwardExecutor();

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
