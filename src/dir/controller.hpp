#ifndef __CONTROLLER_HPP__
#define __CONTROLLER_HPP__

#include "history.hpp"

class Controller : public History {
public:
    Controller(const std::string path);

    virtual ~Controller();

private:
    void preprocess();

    void autocorrection();

};

#endif
