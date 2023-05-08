#ifndef __ENVIRONMENT_HPP__
#define __ENVIRONMENT_HPP__

#include <string>

class Environment {
public:
    static std::string getEnvVarPwd();

    static std::string getEnvVar(const std::string name);

    static std::string getEnvVar(const char * const name);

private:
    Environment();

    ~Environment();

};

#endif
