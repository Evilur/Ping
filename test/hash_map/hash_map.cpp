#include "hash_map.h"
#include "template/hash_map.h"

#include "../core/unit_test.h"

void hash_map_unit_test() {
    UnitTest test("HashMap");

    test.Run("Put(key, element) - 1", [](std::ofstream& file) {
        constexpr const char* const num_str[16] = {
            "one", "two", "three", "four",
            "five", "six", "seven", "eight",
            "nine", "ten", "eleven", "twelve",
            "thirteen", "fourteen", "fifteen", "sixteen"
        };
        HashMap<const char*, int> map(4);
        for (int i = 1; i <= 16; i++) map.Put(num_str[i - 1], i);
        for (const char* const num : num_str) file << map.Get(num) << std::endl;
    });

    test.Run("Put(key, element) - 2", [](std::ofstream& file) {
        constexpr const char* const num_str[16] = {
            "one", "two", "three", "four",
            "five", "six", "seven", "eight",
            "nine", "ten", "eleven", "twelve",
            "thirteen", "fourteen", "fifteen", "sixteen"
        };
        HashMap<const char*, int> map(8);
        for (int i = 1; i <= 16; i++) map.Put(num_str[i - 1], i);
        for (const char* const num : num_str) file << map.Get(num) << std::endl;
    });

    test.Run("Put(key, element) - 3", [](std::ofstream& file) {
        constexpr const char* const num_str[16] = {
            "one", "two", "three", "four",
            "five", "six", "seven", "eight",
            "nine", "ten", "eleven", "twelve",
            "thirteen", "fourteen", "fifteen", "sixteen"
        };
        HashMap<const char*, int> map(16);
        for (int i = 1; i <= 16; i++) map.Put(num_str[i - 1], i);
        for (const char* const num : num_str) file << map.Get(num) << std::endl;
    });
}