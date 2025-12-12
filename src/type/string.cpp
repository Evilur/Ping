#include "type/string.h"

#include <cstring>

String::String(const unsigned long str_size) noexcept :
    _str(new char[str_size + 1]), _size(str_size) {
    _str[str_size] = '\0';
}

String::String(const char* const str) noexcept : String(str, strlen(str)) { }

String::String(const char* str, const unsigned long str_size) noexcept :
    String(str_size) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstringop-truncation"
    strncpy(_str, str, str_size);
#pragma GCC diagnostic pop
}

String::String(const String& string) noexcept :
    String(string._str, string._size) { }

String::~String() noexcept {
    delete[] _str;
}

String String::operator+(const char symbol) const noexcept {
    String result(_str, _size + 1);
    result._str[_size] = symbol;
    return result;
}

String::operator const char*() const noexcept {
    return _str;
}

String::operator std::string_view() const noexcept {
    return std::string_view(_str);
}