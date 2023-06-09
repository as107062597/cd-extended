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
        case PHARSE_ERROR_DIRHIST_FILE_NOT_FOUND:
            return "Error: dirhist file not found";
        case PHARSE_ERROR_OPEN_FILE_FAILED:
            return "Error: open file failed";
        case PHARSE_ERROR_FORMAT_CONVERSION_FAILED:
            return "Error: format conversion failed";
        case PHARSE_ERROR_DOCUMENT_IS_NOT_DEFINE:
            return "Error: document is not define";
        case PHARSE_ERROR_PRINT_ACTION_IS_NOT_DEFINE:
            return "Error: print action is not define";
        case PHARSE_ERROR_EXECUTE_ACTION_IS_NOT_DEFINE:
            return "Error: execute action is not define";
        case PHARSE_ERROR_NO_EXECUTABLE_ACTION_AVAILABLE:
            return "Error: no executable action to be implemented";
        case PHARSE_ERROR_FORMAT_DIRHIST_FILE_IS_INCORRECT:
            return "Error: the format of the dirhist file is incorrect";
        case PHARSE_ERROR_COORDINATE_MISALIGNMENT:
            return "Error: coordinate misalignment";
        case PHARSE_ERROR_AUTO_CORRECTION_FAILED:
            return "Error: auto-correction failed";
        case PHARSE_ERROR_UNEXPECTED_DESTINATION:
            return "Error: unexpected destination";
        case PHARSE_MESSAGE_ALREADY_ON_FIRST_DIRECTORY:
            return "already on the first directory";
        case PHARSE_MESSAGE_ALREADY_ON_LAST_DIRECTORY:
            return "already on the last directory";
        case PHARSE_MESSAGE_TOO_MANY_DIRECTORIES_TO_GO_BACK:
            return "too many directories to go back";
        case PHARSE_MESSAGE_TOO_MANY_DIRECTORIES_TO_GO_AHEAD:
            return "too many directories to go ahead";
        default:
            return "unknown phrase";
    }
}
