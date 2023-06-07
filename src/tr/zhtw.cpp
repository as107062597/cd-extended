#include "tr/translator.hpp"

std::string Translator::toZhTw(const Phrase phrase) const {
    switch (phrase) {
        case PHRASE_DEFAULT_RUNTIME_ERROR_MESSAGE:
            return "運行中發生錯誤";
        case PHRASE_DEFAULT_UNKNOWN_ERROR_MESSAGE:
            return "未知的錯誤";
        case PHRASE_ERROR_MESSAGE_INVALID_EXECUTION_ACTION:
            return "無效的執行行動";
        default:
            return "未知的語句";
    }
}
