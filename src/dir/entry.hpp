#ifndef __ENTRY_HPP__
#define __ENTRY_HPP__

#include <string>

class Entry {
public:
    explicit Entry(const std::string input);

    explicit Entry(const time_t timestamp, const std::string path);

    ~Entry();

    time_t getTimestamp() const;

    std::string getTimestampFormat(const std::string format) const;

    std::string getPath() const;

    bool operator<(const Entry & that) const;

    bool operator>(const Entry & that) const;

    bool operator==(const Entry & that) const;

private:
    time_t timestamp;

    std::string path;

    void setInstanceByPath(const std::string path);

    void setInstanceByEntryString(const std::string entryString);

    struct tm * getTimeinfo() const;

    static bool isAbsolutePath(const std::string path);

    static time_t getCurrentTimestamp();

    static time_t getTimestampByEntryString(const std::string entryString);

    static std::string getPathByEntryString(const std::string entryString);

};

#endif
