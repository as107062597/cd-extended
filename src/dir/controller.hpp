#ifndef __CONTROLLER_HPP__
#define __CONTROLLER_HPP__

#include "history.hpp"

class Controller : public History {
public:
    Controller(const std::string path);

    virtual ~Controller();

    virtual Controller & init();

    virtual Controller & clear();

    virtual Controller & record();

    virtual Controller & record(const std::string directory);

    virtual Controller & print(const int index);

    virtual Controller & move(const int offset);

    virtual Controller & moveTo(const int index);

    virtual Controller & prune();

    virtual bool isValid() const;

    virtual bool isMarkerValid() const;

    virtual bool isIndexValid(const int index) const;

    virtual void assertValid() const;

private:
    void preprocess();

    void autocorrection();

    void printImpl(const int index) const;

    void moveToImpl(const int index);

    bool isWorkingDirectoryValid() const;

};

#endif
