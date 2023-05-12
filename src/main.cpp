#include <memory>
#include "optionparser.hpp"
#include "executorfactoryproducer.hpp"

int main(int argc, char * argv[]) {
    std::shared_ptr<OptionParser> parser =
        std::make_shared<OptionParser>(argc, argv);

    std::shared_ptr<ExecutorInfo> info(
        parser->parse().getExecutorInfo());

    std::shared_ptr<ExecutorFactory> factory(
        ExecutorFactoryProducer::getExecutorFactory(info.get()));

    std::shared_ptr<Executor> executor(
        factory->getExecutor());
    
    executor->execute();

    return 0;
}
