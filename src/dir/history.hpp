#ifndef __HISTORY_HPP__
#define __HISTORY_HPP__

#include <string>
#include <fstream>
#include <vector>

class History {
public:
    std::string path;

    int marker;

    std::vector<std::string> entries;

    History(const std::string path);

    virtual ~History() = 0;

    virtual void init();

    virtual void clear();

    virtual void record();

    virtual void load();

    virtual void save() const;

    virtual bool isValid() const;

private:
    void load(std::ifstream & file);

    void loadImpl(std::ifstream & file);

    void loadMarker(std::ifstream & file);

    void loadEntries(std::ifstream & file);

    void save(std::ofstream & file) const;

    void saveImpl(std::ofstream & file) const;

    void saveMarker(std::ofstream & file) const;

    void saveEntries(std::ofstream & file) const;

    bool isMarkerValid() const;

    bool isWorkingDirectoryValid() const;

    int strToInt(const std::string str) const;

};

#endif
