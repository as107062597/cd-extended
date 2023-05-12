#include "executorfactoryproducer.hpp"
#include "executionmode.hpp"
#include "switchexecutorfactory.hpp"
#include "backwardexecutorfactory.hpp"
#include "forwardexecutorfactory.hpp"

ExecutorFactoryProducer::ExecutorFactoryProducer() {}

ExecutorFactoryProducer::~ExecutorFactoryProducer() {}

ExecutorFactory * ExecutorFactoryProducer::getExecutorFactory(
    const ExecutorInfo * executorinfo
) {
    return &(createExecutorFactory(executorinfo)
        ->setExecutionAction(executorinfo->getExecutionAction())
        .setHelpOption(executorinfo->getHelpOption())
        .setNumber(executorinfo->getNumber())
        .setName(executorinfo->getName())
        .setPath(executorinfo->getPath())
        .setSource(executorinfo->getSource())
        .setDestination(executorinfo->getDestination())
    );
}

ExecutorFactory * ExecutorFactoryProducer::createExecutorFactory(
    const ExecutorInfo * executorinfo
) {
    switch (executorinfo->getExecutionMode()) {
        case MODE_SWITCH:
            return new SwitchExecutorFactory();
        case MODE_BACKWARD:
            return new BackwardExecutorFactory();
        case MODE_FORWARD:
            return new ForwardExecutorFactory();
        default:
            return nullptr;
    }
}
