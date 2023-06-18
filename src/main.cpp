// #include "optionparser.hpp"
// #include "executorfactoryproducer.hpp"

// int main(int argc, char * argv[]) {
//     ExecutorFactoryProducer::getExecutorFactory(
//         OptionParser { argc, argv }
//             .parse()
//             .getExecutorInfo()
//     )
//         .getExecutor()
//         .execute();

//     return 0;
// }

#include <iostream>
#include "errorhandler.hpp"
#include "error.hpp"
#include "executorinfo.hpp"
using namespace std;

int main(int argc, char * argv[]) {
    try {
        ExecutorInfo info;
        info.setName("pd");
        info.setAfterTimestamp("");
        cout << 2 << endl;
    } catch (std::exception & e) {
        cout << 3 << endl;
        ErrorHandler::getInstance().handle(e);
        cout << 4 << endl;
    }
    return 0;
}
