#include "err/error.hpp"
#include "setting.hpp"
#include "tr/translator.hpp"

std::unique_ptr< Translator > Error::translator (
    USER_SETTING_USE_CURRENT_ENV_LANG ?
        std::make_unique< Translator >() :
        std::make_unique< Translator >(USER_SETTING_LANG)
);

Error::Error(const ErrorType errorType) :
    std::runtime_error { errorMessage(errorType) },
    errorType { errorType }
{}

Error::Error(const ErrorType errorType, const std::string message) :
    std::runtime_error { message },
    errorType { errorType }
{}

ErrorType Error::type() const {
    return errorType;
}

const char * Error::what() const noexcept {
    return std::runtime_error::what();
}

std::string Error::errorMessage(const ErrorType errorType) {
    switch (errorType) {
        case ERROR_TYPE_RUNTIME_ERROR:
            return translator->tr(PHRASE_DEFAULT_RUNTIME_ERROR_MESSAGE);
        default:
            return translator->tr(PHRASE_DEFAULT_UNKNOWN_ERROR_MESSAGE);
    }
}
