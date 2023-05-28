#include <chrono>
#include "entry.hpp"
#include "settings.hpp"
#include "cfg/config.hpp"

#define BUFFER_SIZE 64

Entry::Entry(const std::string input) {
    if (isAbsolutePath(input)) {
        setInstanceByPath(input);
    } else {
        setInstanceByEntryString(input);
    }
}

Entry::Entry(const time_t timestamp, const std::string path) :
    timestamp { timestamp },
    path { path }
{}

Entry::~Entry() {}

time_t Entry::getTimestamp() const {
    return timestamp;
}

std::string Entry::getTimestampFormat(const std::string format) const {
    char buffer[BUFFER_SIZE];
    formatTimeAsString(buffer, BUFFER_SIZE);
    return std::string { buffer };
}

std::string Entry::getPath() const {
    return path;
}

bool Entry::operator<(const Entry & that) const {
    return timestamp < that.getTimestamp();
}

bool Entry::operator>(const Entry & that) const {
    return timestamp > that.getTimestamp();
}

bool Entry::operator==(const Entry & that) const {
    return timestamp == that.getTimestamp();
}

void Entry::formatTimeAsString(char * buffer, const int size) const {
    strftime(
        buffer,
        size,
        USER_SETTING_DIRECTORY_VISIT_TIME_FORMAT,
        getTimeinfo()
    );
}

struct tm * Entry::getTimeinfo() const {
    time_t timestampCopy { timestamp };
    time(&timestampCopy);
    return localtime(&timestampCopy);
}

bool Entry::isAbsolutePath(const std::string path) {
    return path.length() && path[0] == '/';
}

void Entry::setInstanceByPath(const std::string path) {
    timestamp = getCurrentTimestamp();
    this->path = path;
}

void Entry::setInstanceByEntryString(const std::string entryString) {
    timestamp = getTimestampByEntryString(entryString);
    path = getPathByEntryString(entryString);
}

time_t Entry::getCurrentTimestamp() {
    return static_cast< time_t >(
        std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()
        ).count()
    );
}

time_t Entry::getTimestampByEntryString(const std::string entryString) {
    return static_cast< time_t >(std::stoll(
        entryString.substr(
            0, entryString.find(PKG_CFG_DIRHIST_ENTRY_SEPARATOR)
        )
    ));
}

std::string Entry::getPathByEntryString(const std::string entryString) {
    return entryString.substr(
        entryString.find(PKG_CFG_DIRHIST_ENTRY_SEPARATOR) + 1
    );
}
