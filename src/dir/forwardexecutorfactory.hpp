#ifndef __FORWARD_EXECUTOR_FACTORY_HPP__
#define __FORWARD_EXECUTOR_FACTORY_HPP__

#include "executorfactory.hpp"

class ForwardExecutorFactory : public ExecutorFactory {
public:
    ForwardExecutorFactory();

    virtual ~ForwardExecutorFactory();

protected:
    virtual Executor * createExecutor() const;

};

#endif
