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
        case PHARSE_ERROR_DIRHIST_FILE_NOT_FOUND:
            return "錯誤：找不到目錄歷史檔案";
        case PHARSE_ERROR_OPEN_FILE_FAILED:
            return "錯誤：檔案開啟失敗";
        case PHARSE_ERROR_FORMAT_CONVERSION_FAILED:
            return "錯誤：格式轉換失敗";
        case PHARSE_ERROR_DOCUMENT_IS_NOT_DEFINE:
            return "錯誤：未定義文檔";
        case PHARSE_ERROR_PRINT_ACTION_IS_NOT_DEFINE:
            return "錯誤：未定義顯示動作";
        case PHARSE_ERROR_EXECUTE_ACTION_IS_NOT_DEFINE:
            return "錯誤：未定義執行動作";
        case PHARSE_ERROR_NO_EXECUTABLE_ACTION_AVAILABLE:
            return "錯誤：沒有可執行的動作";
        case PHARSE_ERROR_FORMAT_DIRHIST_FILE_IS_INCORRECT:
            return "錯誤：目錄歷史檔案格式錯誤";
        case PHARSE_ERROR_COORDINATE_MISALIGNMENT:
            return "錯誤：目錄歷史座標錯位";
        case PHARSE_ERROR_AUTO_CORRECTION_FAILED:
            return "錯誤：自動校正失敗";
        case PHARSE_ERROR_UNEXPECTED_DESTINATION:
            return "錯誤：非預期的目標目錄";
        case PHARSE_MESSAGE_ALREADY_ON_FIRST_DIRECTORY:
            return "已位於第一個目錄";
        case PHARSE_MESSAGE_ALREADY_ON_LAST_DIRECTORY:
            return "已位於最後一個目錄";
        case PHARSE_MESSAGE_TOO_MANY_DIRECTORIES_TO_GO_BACK:
            return "退回目錄數過多";
        case PHARSE_MESSAGE_TOO_MANY_DIRECTORIES_TO_GO_AHEAD:
            return "前進目錄數過多";
        default:
            return "未知的語句";
    }
}
