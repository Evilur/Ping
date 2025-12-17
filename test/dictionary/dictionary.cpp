#include "dictionary.h"
#include "container/dictionary.h"

#include "../core/unit_test.h"

void dictionary_unit_test() {
    UnitTest test("Dictionary");
    constexpr const char* const num_str[16] = {
        "one", "two", "three", "four",
        "five", "six", "seven", "eight",
        "nine", "ten", "eleven", "twelve",
        "thirteen", "fourteen", "fifteen", "sixteen"
    };

    test.Run("Put(key, element) - 1", [num_str] {
        Dictionary<const char*, int> dict(4);
        for (int i = 1; i <= 16; i++) dict.Put(num_str[i - 1], i);
        char str[16];
        for (const char* const num : num_str) {
            strcpy(str, num);
            std::cout << dict.Get(num) << std::endl;
        }
    });

    test.Run("Put(key, element) - 2", [num_str] {
        Dictionary<const char*, int> dict(8);
        for (int i = 1; i <= 16; i++) dict.Put(num_str[i - 1], i);
        char str[16];
        for (const char* const num : num_str) {
            strcpy(str, num);
            std::cout << dict.Get(num) << std::endl;
        }
    });

    test.Run("Put(key, element) - 3", [num_str] {
        Dictionary<const char*, int> dict(16);
        for (int i = 1; i <= 16; i++) dict.Put(num_str[i - 1], i);
        char str[16];
        for (const char* const num : num_str) {
            strcpy(str, num);
            std::cout << dict.Get(num) << std::endl;
        }
    });

    test.Run("Put(key, element) - 4", [num_str] {
        Dictionary<int, const char*> dict(4);
        for (int i = 1; i <= 16; i++) dict.Put(i, num_str[i - 1]);
        for (int i = 1; i <= 16; i++) {
            std::cout << dict.Get(i) << std::endl;
        }
    });

    test.Run("Put(key, element) - 5", [num_str] {
        Dictionary<int, const char*> dict(8);
        for (int i = 1; i <= 16; i++) dict.Put(i, num_str[i - 1]);
        for (int i = 1; i <= 16; i++) {
            std::cout << dict.Get(i) << std::endl;
        }
    });

    test.Run("Put(key, element) - 6", [num_str] {
        Dictionary<int, const char*> dict(16);
        for (int i = 1; i <= 16; i++) dict.Put(i, num_str[i - 1]);
        for (int i = 1; i <= 16; i++) {
            std::cout << dict.Get(i) << std::endl;
        }
    });
}