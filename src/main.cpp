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
#include "err/errorhandler.hpp"
#include "err/error.hpp"
using namespace std;

int main(int argc, char * argv[]) {
    try {
        cout << 1 << endl;
        throw Error { ERROR_TYPE_RUNTIME_ERROR };
        // throw std::runtime_error("hehe");
        cout << 2 << endl;
    } catch (std::exception & e) {
        cout << 3 << endl;
        ErrorHandler::getInstance().handle(e);
        cout << 4 << endl;
    }
    return 0;
}
