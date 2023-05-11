#ifndef __SWITCH_EXECUTOR_FACTORY_HPP__
#define __SWITCH_EXECUTOR_FACTORY_HPP__

#include "executorfactory.hpp"

class SwitchExecutorFactory : public ExecutorFactory {
public:
    SwitchExecutorFactory();

    virtual ~SwitchExecutorFactory();

protected:
    virtual Executor * createExecutor() const;

};

#endif
