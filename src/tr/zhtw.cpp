#include "tr/translator.hpp"

std::string Translator::toZhTw(const Phrase phrase) const {
    switch (phrase) {
        case PHRASE_HELLO_WORLD:
            return "哈囉，世界。";
        case PHRASE_RUNTIME_ERROR:
            return "運行中發生錯誤";
        case PHRASE_UNKNOWN_ERROR:
            return "未知的錯誤";
        default:
            return "未知的語句";
    }
}
