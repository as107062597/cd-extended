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
#include "tr/translator.hpp"
#include "setting.hpp"
using namespace std;

int main(int argc, char * argv[]) {
    Translator t { USER_SETTING_LANG };
    cout << t.tr(PHRASE_HELLO_WORLD) << endl;
    return 0;
}
