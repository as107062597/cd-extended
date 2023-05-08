#include "executor.hpp"

Executor::Executor(
    const std::string path, const std::string name
) : Controller(path) {
    this->name = name;
}

Executor::~Executor() {}

void Executor::execute() {}
