#include "forwardexecutorfactory.hpp"
#include "forwardexecutor.hpp"

ForwardExecutorFactory::ForwardExecutorFactory() {}

ForwardExecutorFactory::~ForwardExecutorFactory() {}

Executor * ForwardExecutorFactory::createExecutor() const {
    return new ForwardExecutor(path);
}
