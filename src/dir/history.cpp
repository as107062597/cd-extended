#include "history.hpp"
#include "util/environment.hpp"
#include "util/errorhandler.hpp"

History::History(const std::string path) {
    this->path = path;
}

History::~History() {}

void History::init() {
    clear();
    record();
}

void History::clear() {
    marker = 0;
    entries.clear();
}

void History::record() {
    if (static_cast<size_t>(marker) == entries.size()) {
        entries.push_back(Environment::getEnvVarPwd());
    }
}

void History::load() {
    std::ifstream file(path);
    load(file);
    file.close();
}

void History::save() const {
    std::ofstream file(path);
    save(file);
    file.close();
}

bool History::isValid() const {
    return isMarkerValid() && isWorkingDirectoryValid();
}

void History::load(std::ifstream & file) {
    if (file.is_open()) {
        loadImpl(file);
    } else {
        ErrorHandler::terminate(PHARSE_ERROR_OPEN_FILE_FAILED);
    }
}

void History::loadImpl(std::ifstream & file) {
    clear();
    loadMarker(file);
    loadEntries(file);
}

void History::loadMarker(std::ifstream & file) {
    std::string line;
    std::getline(file, line);
    marker = strToInt(line);
}

void History::loadEntries(std::ifstream & file) {
    std::string line;
    while (std::getline(file, line)) {
        entries.push_back(line);
    }
}

void History::save(std::ofstream & file) const {
    if (file.is_open()) {
        saveImpl(file);
    } else {
        ErrorHandler::terminate(PHARSE_ERROR_OPEN_FILE_FAILED);
    }
}

void History::saveImpl(std::ofstream & file) const {
    saveMarker(file);
    saveEntries(file);
}

void History::saveMarker(std::ofstream & file) const {
    file << marker << std::endl;
}

void History::saveEntries(std::ofstream & file) const {
    for (std::string entry : entries) {
        file << entry << std::endl;
    }
}

bool History::isMarkerValid() const {
    return marker >= 0 && static_cast<size_t>(marker) < entries.size();
}

bool History::isWorkingDirectoryValid() const {
    return entries.at(marker) == Environment::getEnvVarPwd();
}

int History::strToInt(const std::string str) const {
    try {
        return std::stoi(str);
    } catch (...) {
        ErrorHandler::terminate(PHARSE_ERROR_FORMAT_CONVERSION_FAILED);
        return 0;
    }
}
