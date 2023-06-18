#include "translator.hpp"

std::string Translator::toZhTw(const Phrase phrase) const {
    switch (phrase) {
        case PHRASE_DEFAULT_RUNTIME_ERROR_MESSAGE:
            return "運行中發生錯誤";
        case PHRASE_DEFAULT_UNKNOWN_ERROR_MESSAGE:
            return "未知的錯誤";
        case PHRASE_ERROR_MESSAGE_INVALID_EXECUTION_ACTION:
            return "無效的執行行動";
        case PHRASE_ERROR_MESSAGE_INVALID_EXECUTION_MODE:
            return "無效的執行模式";
        case PHRASE_ERROR_MESSAGE_INVALID_LIST_OPTION:
            return "不正確的選項引數 -- 'list'";
        case PHRASE_ERROR_MESSAGE_INVALID_NUMBER_OPTION:
            return "不正確的選項引數 -- 'number'";
        case PHRASE_ERROR_MESSAGE_INVALID_TIMESTAMP:
            return "不正確的時間戳引數";
        case PHRASE_MESSAGE_HELP_EXAMPLE_PART_1:
            return "嘗試 '";
        case PHRASE_MESSAGE_HELP_EXAMPLE_PART_2:
            return " --help' 以獲取更多資訊";
        default:
            return "未知的語句";
    }
}
