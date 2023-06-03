#ifndef __SETTINGS_HPP__
#define __SETTINGS_HPP__

// how many directories visited can be stored in the dir.hist file
#define USER_SETTING_HISTORY_ENTRIES_COUNT \
        1000

// using the standard conversion format
#define USER_SETTING_USE_STANDARD_CONVERSION_FORMAT \
        true

// what format should the directory visit time be displayed on the screen
#define USER_SETTING_TIME_FORMAT \
        "yyyy-MM-dd HH:mm:ss"

// use the language of the current environment
#define USER_SETTING_USE_CURRENT_ENV_LANG \
        false

// use the specific language, note that this is only applicable when not using
// the language of the environment
#define USER_SETTING_LANG \
        "en_US"

#endif
