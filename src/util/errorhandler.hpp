#ifndef __ERROR_HANDLER_HPP__
#define __ERROR_HANDLER_HPP__

#include "tr/phrase.hpp"

class ErrorHandler {
public:
    static void terminate();

    static void terminate(const Phrase phrase);

private:
    ErrorHandler();

    ~ErrorHandler();

};

#endif
