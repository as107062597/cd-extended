#ifndef __SWITCH_EXECUTOR_HPP__
#define __SWITCH_EXECUTOR_HPP__

#include "editableexecutor.hpp"

class SwitchExecutor : public EditableExecutor {
public:
    SwitchExecutor(const std::string path);

    ~SwitchExecutor();

protected:
    virtual void doPrintAction();

    virtual void doExecuteAction();

    virtual std::string document() const;

private:
    void executeAction();

    void executeActionImpl();

};

#endif
