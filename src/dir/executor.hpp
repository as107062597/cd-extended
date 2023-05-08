#ifndef __EXECUTOR_HPP__
#define __EXECUTOR_HPP__

#include "controller.hpp"

class Executor : public Controller {
public:
    Executor(const std::string path, const std::string name);

    virtual ~Executor() = 0;

    virtual void execute() = 0;

private:
    std::string name;

};

#endif
