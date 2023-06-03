#include "tr/translator.hpp"

#define LOCAL_LANG_ENV_VAR_NAME \
        "LANG"

#define LOCAL_EN_US_LANG_PREFIXES \
        { "en_US", "C" }

#define LOCAL_ZH_TW_LANG_PREFIXES \
        { "zh_TW" }

#define LOCAL_UNKNOWN_LANGUAGE \
        "unknown language"

Translator::Translator() :
    language { getEnvironmentLanguage() }
{}

Translator::Translator(const Language language) :
    language { language }
{}

Translator::Translator(const std::string language) :
    language { toLanguage(language) }
{}

std::string Translator::tr(const Phrase phrase) const {
    return translate(phrase);
}

std::string Translator::translate(const Phrase phrase) const {
    switch (language) {
        case LANGUAGE_EN_US:
            return toEnUs(phrase);
        case LANGUAGE_ZH_TW:
            return toZhTw(phrase);
        default:
            return LOCAL_UNKNOWN_LANGUAGE;
    }
}

Language Translator::getEnvironmentLanguage() const {
    return toLanguage(std::getenv(LOCAL_LANG_ENV_VAR_NAME));
}

bool Translator::isPrefix(
    const std::string reference,
    const std::string prefix
) {
    return !reference.find(prefix);
}

bool Translator::isPrefix(
    const std::string reference,
    const std::vector< std::string > prefixes
) {
    bool ret { false };
    for (std::string prefix : prefixes) {
        if (isPrefix(reference, prefix)) {
            ret = true;
        }
    }
    return ret;
}

bool Translator::isEnUs(const std::string languageString) {
    return isPrefix(
        languageString,
        std::vector< std::string > LOCAL_EN_US_LANG_PREFIXES
    );
}

bool Translator::isZhTw(const std::string languageString) {
    return isPrefix(
        languageString,
        std::vector< std::string > LOCAL_ZH_TW_LANG_PREFIXES
    );
}

Language Translator::toLanguage(const std::string languageString) {
    if (isEnUs(languageString)) {
        return LANGUAGE_EN_US;
    } else if (isZhTw(languageString)) {
        return LANGUAGE_ZH_TW;
    } else {
        return LANGUAGE_UNKNOWN;
    }
}
