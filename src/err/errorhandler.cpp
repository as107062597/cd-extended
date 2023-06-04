#include <iostream>
#include "err/errorhandler.hpp"
#include "err/error.hpp"
#include "setting.hpp"

ErrorHandler::ErrorHandler() {}

ErrorHandler::~ErrorHandler() {}

ErrorHandler & ErrorHandler::getInstance() {
    static ErrorHandler instance;
    return instance;
}

void ErrorHandler::handle(std::exception & exception) const {
    if (isCustomizeError(exception)) {
        handleCustomizeError(dynamic_cast< Error & >(exception));
    } else {
        handleNativeException(exception);
    }
}

void ErrorHandler::handleCustomizeError(const Error & error) const {
    switch (error.type()) {
        case ERROR_TYPE_RUNTIME_ERROR:
        default:
            noisyExit(error);
    }
}

void ErrorHandler::handleNativeException(
    const std::exception & exception
) const {
    noisyExit(exception);
}

void ErrorHandler::noisyExit(const std::exception & exception) const {
    std::cerr << exception.what() << std::endl;
    exit(EXIT_FAILURE);
}

void ErrorHandler::quietExit() const {
    exit(EXIT_FAILURE);
}

bool ErrorHandler::isCustomizeError(std::exception & exception) const {
    return dynamic_cast< Error * >(&exception) != nullptr;
}
