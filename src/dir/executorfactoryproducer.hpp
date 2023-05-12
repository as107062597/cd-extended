#ifndef __EXECUTOR_FACTORY_PRODUCER_HPP__
#define __EXECUTOR_FACTORY_PRODUCER_HPP__

#include "executorfactory.hpp"
#include "executorinfo.hpp"

class ExecutorFactoryProducer {
public:
    static ExecutorFactory * getExecutorFactory(
        const ExecutorInfo * executorinfo);

private:
    ExecutorFactoryProducer();

    ~ExecutorFactoryProducer();

    static ExecutorFactory * createExecutorFactory(
        const ExecutorInfo * executorinfo);

};

#endif
