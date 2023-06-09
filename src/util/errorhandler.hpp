#ifndef __ERROR_HANDLER_HPP__
#define __ERROR_HANDLER_HPP__

#include <string>
#include "tr/phrase.hpp"

class ErrorHandler {
public:
    static void terminate();

    static void terminate(const Phrase phrase);

    static void terminate(const std::string message);

private:
    ErrorHandler();

    ~ErrorHandler();

};

#endif
