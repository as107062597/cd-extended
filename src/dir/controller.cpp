#include <iostream>
#include <filesystem>
#include "controller.hpp"
#include "util/environment.hpp"
#include "util/errorhandler.hpp"

Controller::Controller(const std::string path) : History(path) {
    preprocess();
    autocorrection();
}

Controller::~Controller() {
    save();
}

Controller & Controller::init() {
    clear().record();
    return * this;
}

Controller & Controller::clear() {
    marker = 0;
    entries.clear();
    return * this;
}

Controller & Controller::record() {
    return record(Environment::getEnvVarPwd());
}

Controller & Controller::record(const std::string directory) {
    if (static_cast<size_t>(marker) == entries.size()) {
        entries.push_back(directory);
    } else if (isMarkerValid()) {
        entries[marker] = directory;
    } else {
        ErrorHandler::terminate(PHARSE_ERROR_COORDINATE_MISALIGNMENT);
    }
    return * this;
}

Controller & Controller::print(const int index) {
    if (isIndexValid(index)) {
        printImpl(index);
    } else {
        ErrorHandler::terminate(PHARSE_ERROR_COORDINATE_MISALIGNMENT);
    }
    return * this;
}

Controller & Controller::move(const int offset) {
    return moveTo(marker + offset);
}

Controller & Controller::moveTo(const int index) {
    if (isIndexValid(index) || static_cast<size_t>(index) == entries.size()) {
        moveToImpl(index);
    } else {
        ErrorHandler::terminate(PHARSE_ERROR_COORDINATE_MISALIGNMENT);
    }
    return * this;
}

Controller & Controller::prune() {
    entries.erase(entries.begin() + marker, entries.end());
    return * this;
}

bool Controller::isValid() const {
    return isMarkerValid() && isWorkingDirectoryValid();
}

bool Controller::isMarkerValid() const {
    return isIndexValid(marker);
}

bool Controller::isIndexValid(const int index) const {
    return index >= 0 && static_cast<size_t>(index) < entries.size();
}

void Controller::assertValid() const {
    if (!isValid()) {
        ErrorHandler::terminate(PHARSE_ERROR_FORMAT_DIRHIST_FILE_IS_INCORRECT);
    }
}

void Controller::assertMarker() const {
    if (!isMarkerValid()) {
        ErrorHandler::terminate(PHARSE_ERROR_FORMAT_DIRHIST_FILE_IS_INCORRECT);
    }
}

void Controller::preprocess() {
    if (std::filesystem::exists(path)) {
        load();
    } else {
        ErrorHandler::terminate(PHARSE_ERROR_DIRHIST_FILE_NOT_FOUND);
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

void Controller::printImpl(const int index) const {
    std::cout << entries[index] << std::endl;
}

void Controller::moveToImpl(const int index) {
    marker = index;
}

bool Controller::isWorkingDirectoryValid() const {
    return entries.at(marker) == Environment::getEnvVarPwd();
}
