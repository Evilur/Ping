#include "../core/unit_test.h"
#include "template/linked_list.h"

void linked_list_unit_test() {
    UnitTest test("LinkedList");

    test.Run("Fill", [](std::ofstream& file) {
        LinkedList<int> list;
        for (int i = 0; i <= 100; i++) list.Push(i);
        for (const int n : list) file << n << std::endl;
    });
}