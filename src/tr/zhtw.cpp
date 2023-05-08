#include "translator.hpp"

std::string Translator::toZhTw(const Phrase phrase) {
    switch (phrase) {
        case PHRASE_HELLO_WORLD:
            return "哈囉，世界。";
        case PHARSE_ERROR_ARG_NO_EXECUTION_MODE:
            return "錯誤：未設定執行模式";
        case PHARSE_ERROR_ARG_INVALID_EXECUTION_MODE:
            return "錯誤：不存在的執行模式";
        case PHARSE_ERROR_ARG_NO_EXECUTION_ACTION:
            return "錯誤：未設定執行動作";
        case PHARSE_ERROR_ARG_INVALID_EXECUTION_ACTION:
            return "錯誤：不存在的執行動作";
        case PHARSE_ERROR_ARG_NO_PATH_FILE:
            return "錯誤：未設定目錄歷史檔案路徑";
        case PHARSE_ERROR_ARG_NO_SOURCE:
            return "錯誤：未設定來源目錄";
        case PHARSE_ERROR_ARG_NO_DESTINATION:
            return "錯誤：未設定目標目錄";
        case PHARSE_ERROR_OPEN_FILE_FAILED:
            return "錯誤：檔案開啟失敗";
        case PHARSE_ERROR_FORMAT_CONVERSION_FAILED:
            return "錯誤：格式轉換失敗";
        default:
            return "未知的語句";
    }
}
