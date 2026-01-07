#pragma once
#include "container/dictionary.h"
#include "util/class.h"

class Settings final {
public:
    PREVENT_INSTANCE(Settings);

    static void Init();

    static void Save();

private:
    class Parameter {
    public:
        PREVENT_COPY_ALLOW_MOVE(Parameter);

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
    struct UI {
        static inline Parameter chat_list_width = 500;
        static inline Parameter language = "ru_RU";
    };
};
