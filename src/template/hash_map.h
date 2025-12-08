#pragma once

#include "linked_list.h"

/**
 * Simple minimalistic implementation of hash map
 * @author Evilur <the.evilur@gmail.com>
 * @tparam K Key typename
 * @tparam T Element typename
 */
template<typename K, typename T>
class HashMap final {
public:
    /**
     * @param capacity Maximum number of elements without resizing
     */
    explicit HashMap(u_int capacity);

    /**
     * Free the memory
     */
    ~HashMap();

    /**
     * Delete copy constructor
     */
    HashMap(const HashMap&) = delete;

    /**
     * Delete copy operator
     */
    HashMap& operator=(const HashMap&) = delete;

    /**
     * Put an element into the hash map
     * @param key The key that can be used to retrieve the element
     * @param element Element to put into the map
     */
    void Put(K key, T element);

    /**
     * Get the element from the hash map by the key
     * @param key The key to get the element by
     * @return Element with the similar key; nullptr if there is no such element
     */
    T Get(K key) const;

private:
    /**
     * A node to keep in the linked list
     */
    class Node {
    public:
        K key;
        T element;
    };

    /**
     * A pointer to the dynamic array with linked lists for resolving collisions
     */
    LinkedList<Node>* const _lists;

    /**
     * A size of the array with linked lists
     */
    const u_int _capacity;

    /**
     * Calculate the hash
     * @param key A key for calculating the hash of
     * @return Calculated hash
     */
    unsigned short GetHash(K key) const;
};

template<typename K, typename T>
HashMap<K, T>::HashMap(const u_int capacity) :
        _lists(new LinkedList<Node>[capacity]), _capacity(capacity) { }

template <typename K, typename T>
HashMap<K, T>::~HashMap() { delete[] _lists; }

template<typename K, typename T>
void HashMap<K, T>::Put(K key, T element) {
    auto penis = GetHash(key);

    /* Put the node to the one of the linked lists, according to the hash */
    _lists[GetHash(key)].Push({ key, element });
}

template<typename K, typename T>
T HashMap<K, T>::Get(K key) const {
    /* Calculate the hash */
    unsigned short hash = GetHash(key);

    /* Try to get the node from the linked list */
    for (Node node : _lists[hash])
        if (node.key == key)
            return node.element;

    /* If there is NOT an element in the linked list, throw an error */
    throw std::runtime_error("HashMap: Get() no such an element");
}

template <typename K, typename T>
unsigned short HashMap<K, T>::GetHash(const K key) const {
    /* The variable to store the hash (751 - random prime number) */
    unsigned long hash = 751;

    /* Get the byte array from the key */
    const unsigned char* byte_array_ptr = (unsigned char*)(void*)&key;
    const unsigned char* const byte_array_end = byte_array_ptr + sizeof(key);

    /* Evaluate the hash */
    do {
        const unsigned char byte = *byte_array_ptr;
        hash = (hash << 5) - hash + byte;
    } while (++byte_array_ptr < byte_array_end);

    /* Return the result */
    return hash % _capacity;
}