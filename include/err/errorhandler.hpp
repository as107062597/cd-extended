#ifndef __ERROR_HANDLER_HPP__
#define __ERROR_HANDLER_HPP__

#include <memory>

class Error;

class ErrorHandler {
public:
    ~ErrorHandler();

    ErrorHandler(const ErrorHandler &) = delete;

    ErrorHandler & operator=(const ErrorHandler &) = delete;

    static ErrorHandler & getInstance();

    void handle(std::exception & exception) const;

private:
    ErrorHandler();

    void handleCustomizeError(const Error & error) const;

    void handleNativeException(const std::exception & exception) const;

    void noisyExit(const std::exception & exception) const;

    void quietExit() const;

    bool isCustomizeError(std::exception & exception) const;

};

#endif
