#include <iostream>
#include "errorhandler.hpp"
#include "tr/translator.hpp"

ErrorHandler::ErrorHandler() {}

ErrorHandler::~ErrorHandler() {}

void ErrorHandler::terminate() {
    exit(EXIT_FAILURE);
}

void ErrorHandler::terminate(const Phrase phrase) {
    std::cerr << Translator::tr(phrase) << std::endl;
    terminate();
}
