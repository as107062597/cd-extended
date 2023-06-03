#ifndef __ERROR_HPP__
#define __ERROR_HPP__

#include "err/errortype.hpp"

class Error {
public:
    explicit Error();

    explicit Error(const ErrorType);
};

#endif
