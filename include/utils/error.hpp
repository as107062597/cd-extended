#ifndef __ERROR_HPP__
#define __ERROR_HPP__

#include <memory>
#include <string>
#include "errortype.hpp"

class Translator;

class Error : public std::runtime_error {
public:
    explicit Error(const ErrorType errorType);

    explicit Error(const ErrorType errorType, const std::string & message);

    ErrorType type() const;

    const char * what() const noexcept override;

private:
    ErrorType errorType;

    static std::unique_ptr< Translator > translator;

    static std::string errorMessage(const ErrorType errorType);

};

#endif