#include "tr/translator.hpp"

std::string Translator::toEnUs(const Phrase phrase) const {
    switch (phrase) {
        case PHRASE_HELLO_WORLD:
            return "hello, world.";
        default:
            return "unknown phrase";
    }
}
