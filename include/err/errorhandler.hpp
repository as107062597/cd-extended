#ifndef __ERROR_HANDLER_HPP__
#define __ERROR_HANDLER_HPP__

class ErrorHandler {
public:
    ~ErrorHandler();

    ErrorHandler(const ErrorHandler &) = delete;

    ErrorHandler & operator=(const ErrorHandler &) = delete;

    static ErrorHandler & getInstance();

    void handle(const std::runtime_error error);

private:
    ErrorHandler();

};

#endif
