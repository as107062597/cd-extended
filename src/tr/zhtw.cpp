#include "tr/translator.hpp"

std::string Translator::toZhTw(const Phrase phrase) const {
    switch (phrase) {
        case PHRASE_HELLO_WORLD:
            return "哈囉，世界。";
        default:
            return "未知的語句";
    }
}
