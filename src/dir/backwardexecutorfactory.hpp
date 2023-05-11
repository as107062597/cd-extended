#ifndef __BACKWARD_EXECUTOR_FACTORY_HPP__
#define __BACKWARD_EXECUTOR_FACTORY_HPP__

#include "executorfactory.hpp"

class BackwardExecutorFactory : public ExecutorFactory {
public:
    BackwardExecutorFactory();

    virtual ~BackwardExecutorFactory();

protected:
    virtual Executor * createExecutor() const;

};

#endif
