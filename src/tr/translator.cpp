#include "translator.hpp"

#define DEFAULT_LANGUAGE LANG_EN_US
#define UNKNONWN_LANGUAGE "unknown language"

Language Translator::language = DEFAULT_LANGUAGE;

Translator::Translator() {}

Translator::~Translator() {}

void Translator::setLanguage(const Language language) {
    Translator::language = language;
}

std::string Translator::tr(const Phrase phrase) {
    return translate(phrase);
}

std::string Translator::translate(const Phrase phrase) {
    switch (language) {
        case LANG_EN_US:
            return toEnUs(phrase);
        case LANG_ZH_TW:
            return toZhTw(phrase);
        default:
            return UNKNONWN_LANGUAGE;
    }
}
