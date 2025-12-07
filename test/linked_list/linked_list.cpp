#include "../core/unit_test.h"
#include "template/linked_list.h"

static void fill_list(LinkedList<int>& list);

static void print_list(std::ofstream& file, const LinkedList<int>& list);

void linked_list_unit_test() {
    UnitTest test("LinkedList");

    test.Run("Head - Exception", [](std::ofstream& file) {
        const LinkedList<int> list;
        file << list.Head();
    });

    test.Run("Tail - Exception", [](std::ofstream& file) {
        const LinkedList<int> list;
        file << list.Tail();
    });

    test.Run("Push", [](std::ofstream& file) {
        LinkedList<int> list;
        fill_list(list);
        print_list(file, list);
    });

    test.Run("Pop", [](std::ofstream& file) {
        LinkedList<int> list;
        fill_list(list);
        for (int i = 0; i < 8; i++) list.Pop();
        print_list(file, list);
    });

    test.Run("Pop - Exception", [](std::ofstream& file) {
        LinkedList<int> list;
        list.Pop();
    });

    test.Run("TryPop", [](std::ofstream& file) {
        LinkedList<int> list;
        fill_list(list);
        for (int i = 0; i < 8; i++) list.TryPop();
        print_list(file, list);
    });
}

static void fill_list(LinkedList<int>& list) {
    for (int i = 1; i <= 16; i++) list.Push(i);
}

static void print_list(std::ofstream& file, const LinkedList<int>& list) {
    /* Print all elements */
    for (const int n : list) file << n << std::endl;

    /* Print the head and the tail */
    file << "---" << std::endl;
    file << "Head: " << list.Head() << std::endl;
    file << "Tail: " << list.Tail() << std::endl;
}