#include <filesystem>
#include "controller.hpp"

Controller::Controller(const std::string path) : History(path) {
    preprocess();
    autocorrection();
}

Controller::~Controller() {
    save();
}

void Controller::preprocess() {
    if (std::filesystem::exists(path)) {
        load();
    } else {
        init();
    }
}

void Controller::autocorrection() {
    if (entries.empty()) {
        marker = 0;
        record();
    } else if (marker < 0) {
        marker = 0;
    } else if (static_cast<size_t>(marker) >= entries.size()) {
        marker = static_cast<int>(entries.size()) - 1;
    }
}
