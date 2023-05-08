#include "translator.hpp"

std::string Translator::toEnUs(const Phrase phrase) {
    switch (phrase) {
        case PHRASE_HELLO_WORLD:
            return "hello, world.";
        case PHARSE_ERROR_ARG_NO_EXECUTION_MODE:
            return "Error: execution mode not set";
        case PHARSE_ERROR_ARG_INVALID_EXECUTION_MODE:
            return "Error: invalid execution mode";
        case PHARSE_ERROR_ARG_NO_EXECUTION_ACTION:
            return "Error: execution action not set";
        case PHARSE_ERROR_ARG_INVALID_EXECUTION_ACTION:
            return "Error: invalid execution action";
        case PHARSE_ERROR_ARG_NO_PATH_FILE:
            return "Error: dirhist file path not set";
        case PHARSE_ERROR_ARG_NO_SOURCE:
            return "Error: source directory not set";
        case PHARSE_ERROR_ARG_NO_DESTINATION:
            return "Error: destination directory not set";
        case PHARSE_ERROR_OPEN_FILE_FAILED:
            return "Error: open file failed";
        case PHARSE_ERROR_FORMAT_CONVERSION_FAILED:
            return "Error: format conversion failed";
        default:
            return "unknown phrase";
    }
}
