#include "backwardexecutorfactory.hpp"
#include "backwardexecutor.hpp"

BackwardExecutorFactory::BackwardExecutorFactory() {}

BackwardExecutorFactory::~BackwardExecutorFactory() {}

Executor * BackwardExecutorFactory::createExecutor() const {
    return new BackwardExecutor(path);
}
