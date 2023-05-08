#include <iostream>
#include <string>
#include <cstring>
#include <getopt.h>
#include "optionparser.hpp"
#include "util/errorhandler.hpp"

#define NEXT_ARGUMENT_INDEX 1

#define ARG_SWITCH_MODE     "switch"

#define ARG_BACKWARD_MODE   "backward"

#define ARG_FORWARD_MODE    "forward"

#define ARG_PRINT_ACTION    "print"

#define ARG_EXECUTE_ACTION  "exec"

#define ARG_OPTIONS_STRING  "hn:"

#define ARG_OPTIONS_LONG    { \
    { "help", 0, nullptr, 'h' }, \
    { "number", 1, nullptr, 'n' } \
}

OptionParser::OptionParser(int argc, char ** const argv) {
    this->argc = argc;
    this->argv = argv;
}

OptionParser & OptionParser::parse() {
    info = new ExecutorInfo();
    setParsePointer();
    parseImpl();
    return * this;
}

ExecutorInfo * OptionParser::getExecutorInfo() const {
    return info;
}

void OptionParser::parseImpl() {
    parseExecutionMode();
    parseExecutionAction();
    parseFilePath();
    parseSource();
    parseDestination();
    parseOptions();
}

void OptionParser::parseExecutionMode() {
    if (optc > NEXT_ARGUMENT_INDEX) {
        parseExecutionModeImpl();
        nextParsePointer();
    } else {
        ErrorHandler::terminate(PHARSE_ERROR_ARG_NO_EXECUTION_MODE);
    }
}

void OptionParser::parseExecutionModeImpl() {
    if (!strcmp(optv[NEXT_ARGUMENT_INDEX], ARG_SWITCH_MODE)) {
        info->setExecutionMode(MODE_SWITCH);
        info->setExecutionAction(ACTION_EXECUTE);
    } else if (!strcmp(optv[NEXT_ARGUMENT_INDEX], ARG_BACKWARD_MODE)) {
        info->setExecutionMode(MODE_BACKWARD);
    } else if (!strcmp(optv[NEXT_ARGUMENT_INDEX], ARG_FORWARD_MODE)) {
        info->setExecutionMode(MODE_FORWARD);
    } else {
        ErrorHandler::terminate(PHARSE_ERROR_ARG_INVALID_EXECUTION_MODE);
    }
}

void OptionParser::parseExecutionAction() {
    if (info->getExecutionMode() != MODE_SWITCH) {
        if (optc > NEXT_ARGUMENT_INDEX) {
            parseExecutionActionImpl();
            nextParsePointer();
        } else {
            ErrorHandler::terminate(PHARSE_ERROR_ARG_NO_EXECUTION_ACTION);
        }
    }
}

void OptionParser::parseExecutionActionImpl() {
    if (!strcmp(optv[NEXT_ARGUMENT_INDEX], ARG_PRINT_ACTION)) {
        info->setExecutionAction(ACTION_PRINT);
    } else if (!strcmp(optv[NEXT_ARGUMENT_INDEX], ARG_EXECUTE_ACTION)) {
        info->setExecutionAction(ACTION_EXECUTE);
    } else {
        ErrorHandler::terminate(PHARSE_ERROR_ARG_INVALID_EXECUTION_ACTION);
    }
}

void OptionParser::parseFilePath() {
    if (optc > NEXT_ARGUMENT_INDEX) {
        parseFilePathImpl();
        nextParsePointer();
    } else {
        ErrorHandler::terminate(PHARSE_ERROR_ARG_NO_PATH_FILE);
    }
}

void OptionParser::parseFilePathImpl() {
    info->setFilePath(optv[NEXT_ARGUMENT_INDEX]);
}

void OptionParser::parseSource() {
    if (info->getExecutionAction() == ACTION_EXECUTE) {
        if (optc > NEXT_ARGUMENT_INDEX) {
            parseSourceImpl();
            nextParsePointer();
        } else {
            ErrorHandler::terminate(PHARSE_ERROR_ARG_NO_SOURCE);
        }
    }
}

void OptionParser::parseSourceImpl() {
    info->setSource(optv[NEXT_ARGUMENT_INDEX]);
}

void OptionParser::parseDestination() {
    if (info->getSource().length()) {
        if (optc > NEXT_ARGUMENT_INDEX) {
            parseDestinationImpl();
            nextParsePointer();
        } else {
            ErrorHandler::terminate(PHARSE_ERROR_ARG_NO_DESTINATION);
        }
    }
}

void OptionParser::parseDestinationImpl() {
    info->setDestination(optv[NEXT_ARGUMENT_INDEX]);
}

void OptionParser::parseOptions() {
    const char * optstr = ARG_OPTIONS_STRING;
    const struct option opts[] = ARG_OPTIONS_LONG;

    int opt;
    while ((opt = getopt_long(optc, optv, optstr, opts, nullptr)) != EOF) {
        parseOption(opt, optarg);
    }
}

void OptionParser::parseOption(const int opt, const char * const optarg) {
    switch (opt) {
        case 'h':
            info->setHelpOption(true);
            break;
        case 'n':
            info->setNumber(std::atoi(optarg));
            break;
        case '?':
        default:
            ErrorHandler::terminate();
    }
}

void OptionParser::setParsePointer() {
    optc = argc;
    optv = argv;
}

void OptionParser::nextParsePointer() {
    optc -= 1;
    optv += 1;
}
