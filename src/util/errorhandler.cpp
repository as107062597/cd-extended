#include <iostream>
#include "errorhandler.hpp"
#include "tr/translator.hpp"

ErrorHandler::ErrorHandler() {}

ErrorHandler::~ErrorHandler() {}

void ErrorHandler::terminate() {
    exit(EXIT_FAILURE);
}

void ErrorHandler::terminate(const Phrase phrase) {
    terminate(Translator::tr(phrase));
}

void ErrorHandler::terminate(const std::string message) {
    std::cerr << message << std::endl;
    terminate();
}
