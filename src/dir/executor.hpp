#ifndef __EXECUTOR_HPP__
#define __EXECUTOR_HPP__

#include "controller.hpp"
#include "executionaction.hpp"

class Executor : protected Controller {
public:
    Executor(const std::string path);

    virtual ~Executor() = 0;

    virtual Executor & execute();

protected:
    ExecutionAction executionAction = ACTION_NONE;

    bool helpOption                 = false;

    int number                      = 1;

    std::string name                = "";

    std::string source              = "";

    std::string destination         = "";

    virtual void setDocument() const;

    virtual void executeImpl();

    virtual void printDocument() const;

    virtual void act();

    virtual void doNoneAction();

    virtual void doPrintAction();     // recommended to override

    virtual void doExecuteAction();         // recommended to override

    virtual std::string document() const;   // recommended to override

private:
    std::vector<void (Executor::*) ()> actions{ACTION_COUNT};

    void setActions();

};

#endif
