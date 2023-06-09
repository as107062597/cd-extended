#include "tr/translator.hpp"

std::string Translator::toEnUs(const Phrase phrase) const {
    switch (phrase) {
        case PHRASE_DEFAULT_RUNTIME_ERROR_MESSAGE:
            return "runtime error";
        case PHRASE_DEFAULT_UNKNOWN_ERROR_MESSAGE:
            return "unknown error";
        case PHRASE_ERROR_MESSAGE_INVALID_EXECUTION_ACTION:
            return "invalid execution action";
        case PHRASE_ERROR_MESSAGE_INVALID_EXECUTION_MODE:
            return "invalid execution mode";
        case PHRASE_ERROR_MESSAGE_INVALID_LIST_OPTION:
            return "incorrect argument for option -- 'list'";
        case PHRASE_ERROR_MESSAGE_INVALID_NUMBER_OPTION:
            return "incorrect argument for option -- 'number'";
        case PHRASE_ERROR_MESSAGE_INVALID_TIMESTAMP:
            return "incorrect argument for timestamp";
        case PHRASE_MESSAGE_HELP_EXAMPLE_PART_1:
            return "Try '";
        case PHRASE_MESSAGE_HELP_EXAMPLE_PART_2:
            return " --help' for more information.";
        default:
            return "unknown phrase";
    }
}
