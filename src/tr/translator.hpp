#ifndef __TRANSLATOR_HPP__
#define __TRANSLATOR_HPP__

#include <string>
#include "language.hpp"
#include "phrase.hpp"

class Translator {
public:
    static void setLanguage(const Language language);

    static std::string tr(const Phrase phrase);

    static std::string translate(const Phrase phrase);

private:
    static Language language;

    Translator();

    ~Translator();

    static std::string toEnUs(const Phrase phrase);

    static std::string toZhTw(const Phrase phrase);

};

#endif
