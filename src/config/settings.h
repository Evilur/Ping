#pragma once

#include "container/dictionary.h"
#include "util/class.h"

#if defined(CLIENT_MODE)
/* Substructs to store the parameters */
#define PARAMETERS_IN_HEADER                                                  \
struct UI {                                                                   \
    static inline Parameter chat_list_width = 500;                            \
    static inline Parameter language = "ru_RU";                               \
};

/* Defining the parameter dictionaries */
#define PARAMETERS_DICTIONARIES                                               \
section_map* ui_map = new section_map(5);                                     \
_settings_map->Put("UI", ui_map);

/* Put the parameters to the dictionary */
#define PARAMETERS_IN_DICTIONARIES                                            \
ui_map->Put("chat_list_width", &UI::chat_list_width);                         \
ui_map->Put("language", &UI::language);

#elif defined(SERVER_MODE)
/* Substructs to store the parameters */
#define PARAMETERS_IN_HEADER

/* Defining the parameter dictionaries */
#define PARAMETERS_DICTIONARIES

/* Put the parameters to the dictionary */
#define PARAMETERS_IN_DICTIONARIES
#endif

class Settings final {
public:
    PREVENT_INSTANTIATION(Settings);

    static void Init();

    static void Save();

private:
    class Parameter {
    public:
        PREVENT_COPY_AND_MOVE(Parameter);

        enum Type : char { INTEGER, FLOAT, STRING };

        Parameter(int data) noexcept;

        Parameter(float data) noexcept;

        Parameter(const char* data) noexcept;

        ~Parameter();

        Parameter& operator=(int data);

        Parameter& operator=(float data);

        Parameter& operator=(const char* data);

        explicit operator int() const;

        explicit operator float() const;

        explicit operator const char*() const;

    private:
        const Type _type;
        void* _data = nullptr;
    };

    using section_map = Dictionary<const char*, Parameter*>;
    static inline Dictionary<const char*, section_map*>* _settings_map =
        nullptr;

public:
    PARAMETERS_IN_HEADER;
};

#include "setting_imp.h"
