#include <chrono>
#include "dir/entry.hpp"
#include "setting.hpp"
#include "definition.hpp"

#define LOCAL_ADDITIONAL_BUFFER_SPACE 4
#define LOCAL_GET_BUFFER_SIZE_BY_FORMAT_LENGTH(x) \
        (x + LOCAL_ADDITIONAL_BUFFER_SPACE)

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
    char buffer[LOCAL_GET_BUFFER_SIZE_BY_FORMAT_LENGTH(format.length())];
    formatTimeAsString(buffer, format);
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

void Entry::formatTimeAsString(char * buffer, const std::string format) const {
    strftime(
        buffer,
        LOCAL_GET_BUFFER_SIZE_BY_FORMAT_LENGTH(format.length()),
        USER_SETTING_USE_STANDARD_CONVERSION_FORMAT ?
            toCStyleConversionFormat(std::string { format }).c_str() :
            format.c_str(),
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
        std::chrono::duration_cast< std::chrono::milliseconds >(
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

std::string Entry::toCStyleConversionFormat(
    const std::string standardFormat
) {
    return replace(
        standardFormat,
        std::vector< std::string >
            PKG_CFG_DATETIME_STANDARD_CONVERSION_PATTERNS,
        std::vector< std::string >
            PKG_CFG_DATETIME_C_STYLE_CONVERSION_PATTERNS
    );
}

std::string Entry::replace(
    const std::string source,
    const std::vector< std::string > & substrings,
    const std::vector< std::string > & newSubstrings
) {
    std::string output { source };
    for (size_t i {0}; i != substrings.size(); i += 1) {
        output = replace(output, substrings[i], newSubstrings[i]);
    }
    return output;
}

std::string Entry::replace(
    const std::string source,
    const std::string substring,
    const std::string newSubstring
) {
    std::string output { source };
    const size_t found { output.find(substring) };
    if (found != std::string::npos) {
        output.replace(found, substring.length(), newSubstring);
    }
    return output;
}
