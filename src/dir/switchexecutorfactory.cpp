#include "switchexecutorfactory.hpp"
#include "switchexecutor.hpp"

SwitchExecutorFactory::SwitchExecutorFactory() : ExecutorFactory() {}

SwitchExecutorFactory::~SwitchExecutorFactory() {}

Executor * SwitchExecutorFactory::createExecutor() const {
    return new SwitchExecutor(path);
}