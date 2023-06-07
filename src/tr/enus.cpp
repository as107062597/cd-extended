#include "tr/translator.hpp"

std::string Translator::toEnUs(const Phrase phrase) const {
    switch (phrase) {
        case PHRASE_DEFAULT_RUNTIME_ERROR_MESSAGE:
            return "runtime error";
        case PHRASE_DEFAULT_UNKNOWN_ERROR_MESSAGE:
            return "unknown error";
        case PHRASE_ERROR_MESSAGE_INVALID_EXECUTION_ACTION:
            return "invalid execution action";
        default:
            return "unknown phrase";
    }
}
