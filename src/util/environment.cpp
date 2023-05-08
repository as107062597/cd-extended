#include <cstdlib>
#include "environment.hpp"

#define ENV_NO_VAR  ""
#define ENV_VAR_PWD "PWD"

Environment::Environment() {};

Environment::~Environment() {};

std::string Environment::getEnvVarPwd() {
    return getEnvVar(ENV_VAR_PWD);
}

std::string Environment::getEnvVar(const std::string name) {
    return getEnvVar(name.c_str());
}

std::string Environment::getEnvVar(const char * const name) {
    const char * var = std::getenv(name);
    return var ? var : ENV_NO_VAR;
}
