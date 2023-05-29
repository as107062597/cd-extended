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
#include "settings.hpp"
#include "dir/entry.hpp"

using namespace std;

int main(int argc, char * argv[]) {
    Entry e { "/home/annie" };
    cout << e.getTimestampFormat(USER_SETTING_TIME_FORMAT) << endl;
    cout << e.getPath() << endl;
    return 0;
}
