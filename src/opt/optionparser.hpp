#ifndef __OPTION_PARSER_HPP__
#define __OPTION_PARSER_HPP__

#include "dir/executorinfo.hpp"

class OptionParser {
public:
    OptionParser(int argc, char ** argv);

    OptionParser & parse();

    ExecutorInfo * getExecutorInfo() const;

private:
    int argc;

    int optc;

    char ** argv;

    char ** optv;

    ExecutorInfo * info;

    void parseImpl();

    void parseExecutionMode();

    void parseExecutionModeImpl();

    void parseExecutionAction();

    void parseExecutionActionImpl();

    void parsePath();

    void parsePathImpl();

    void parseSource();

    void parseSourceImpl();

    void parseDestination();

    void parseDestinationImpl();

    void parseNumber();

    void parseNumberImpl();

    void parseName();

    void parseOptions();

    void setName();

    void parseOption(const int opt, const char * const optarg);

    void setParsePointer();

    void nextParsePointer();

    std::string getNameByInfoMode() const;

};

#endif
