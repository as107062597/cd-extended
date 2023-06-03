#include "err/errorhandler.hpp"
#include <iostream>
ErrorHandler::ErrorHandler() {}

ErrorHandler::~ErrorHandler() {}

ErrorHandler & ErrorHandler::getInstance() {
    static ErrorHandler instance;
    return instance;
}

void ErrorHandler::handle(const std::runtime_error error) {

}
