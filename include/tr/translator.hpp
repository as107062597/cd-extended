#ifndef __TRANSLATOR_HPP__
#define __TRANSLATOR_HPP__

#include <string>
#include <vector>
#include "tr/language.hpp"
#include "tr/phrase.hpp"

class Translator {
public:
    explicit Translator();

    explicit Translator(const Language language);

    explicit Translator(const std::string language);

    std::string tr(const Phrase phrase) const;

    std::string translate(const Phrase phrase) const;

private:
    Language language;

    Language getEnvironmentLanguage() const;

    std::string toEnUs(const Phrase phrase) const;

    std::string toZhTw(const Phrase phrase) const;

    static bool isPrefix(
        const std::string reference,
        const std::string prefix
    );

    static bool isPrefix(
        const std::string reference,
        const std::vector< std::string > prefixes
    );

    static bool isEnUs(const std::string languageString);

    static bool isZhTw(const std::string languageString);

    static Language toLanguage(const std::string languageString);

};

#endif
