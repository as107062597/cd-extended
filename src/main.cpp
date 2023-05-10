#include <memory>
#include "option.hpp"
#include "directory.hpp"

int main(int argc, char * argv[]) {
    std::shared_ptr<OptionParser> parser =
        std::make_shared<OptionParser>(argc, argv);

    std::shared_ptr<ExecutorInfo> info(
        parser->parse().getExecutorInfo());
    
    //----------------------------------------------------------------
    // SwitchExecutor * e = new SwitchExecutor("/tmp/o.txt");
    // e->setExecutionAction(ACTION_EXECUTE);
    // e->setSource("/home/chi/workspace/Github/cd-extended/src");
    // e->setDestination("/home/ed/1");
    // e->execute();
    // delete e;
    // #include <iostream>
    // std::cout << marker << std::endl;
    //     for (std::string s : entries) std::cout << s << std::endl;
    //----------------------------------------------------------------

    return 0;
}
