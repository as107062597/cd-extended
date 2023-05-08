#include <memory>
#include "option.hpp"
#include "directory.hpp"

int main(int argc, char * argv[]) {
    std::shared_ptr<OptionParser> parser =
        std::make_shared<OptionParser>(argc, argv);

    std::shared_ptr<ExecutorInfo> info(
        parser->parse().getExecutorInfo());

    return 0;
}
