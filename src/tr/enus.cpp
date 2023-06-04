#include "tr/translator.hpp"

std::string Translator::toEnUs(const Phrase phrase) const {
    switch (phrase) {
        case PHRASE_HELLO_WORLD:
            return "hello, world.";
        case PHRASE_RUNTIME_ERROR:
            return "runtime error";
        case PHRASE_UNKNOWN_ERROR:
            return "unknown error";
        default:
            return "unknown phrase";
    }
}
