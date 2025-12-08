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
struct Node;
public:
    /**
     * @param capacity Maximum number of elements without resizing
     */
    explicit HashMap(unsigned short capacity) noexcept;

    /**
     * Free the memory
     */
    ~HashMap() noexcept;

    /**
     * Delete the copy constructor
     */
    HashMap(const HashMap&) noexcept = delete;

    /**
     * Delete the copy operator
     */
    HashMap& operator=(const HashMap&) noexcept = delete;

    /**
     * Put an element into the hash map
     * @param key The key that can be used to retrieve the element
     * @param element Element to put into the map
     */
    void Put(K key, T element) noexcept;

    /**
     * Get the element from the hash map by the key
     * @param key The key to get the element by
     * @return Element with the similar key; nullptr if there is no such element
     */
    T Get(K key) const;

    /**
     * Iterator to go through the hash map
     */
    class Iterator {
    public:
        explicit Iterator(unsigned short index,
                          unsigned short capacity,
                          const LinkedList<Node>* lists,
                          LinkedList<Node>::Iterator iterator
                          ) noexcept;

        bool operator!=(const Iterator& other) const noexcept;

        const Node& operator*() const noexcept;

        Iterator& operator++() noexcept;

    private:
        unsigned short _index;
        const unsigned short _capacity;
        const LinkedList<Node>* const _lists;
        LinkedList<Node>::Iterator _iterator;
    };

    /**
     * Get the iterator for the first element
     * @return iterator for the first element
     */
    Iterator begin() const noexcept;

    /**
     * Get the iterator after the last element
     * @return iterator after the last element
     */
    Iterator end() const noexcept;

private:
    /**
     * Node to keep the element and its key in the linked list
     */
    struct Node {
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
    const unsigned short _capacity;

    /**
     * Calculate the hash
     * @param key A key for calculating the hash of
     * @return Calculated hash
     */
    unsigned short GetHash(K key) const;
};

template<typename K, typename T>
HashMap<K, T>::HashMap(const unsigned short capacity) noexcept :
        _lists(new LinkedList<Node>[capacity]), _capacity(capacity) { }

template <typename K, typename T>
HashMap<K, T>::~HashMap() noexcept { delete[] _lists; }

template<typename K, typename T>
void HashMap<K, T>::Put(K key, T element) noexcept {
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
HashMap<K, T>::Iterator HashMap<K, T>::begin() const noexcept {
    for (unsigned short i = 0; i < _capacity; ++i)
        if (_lists[i].begin() != _lists[i].end())
            return Iterator(i, _capacity, _lists, _lists[i].begin());
    return end();
}

template <typename K, typename T>
HashMap<K, T>::Iterator HashMap<K, T>::end() const noexcept {
    return Iterator(_capacity, _capacity, _lists,
                    typename LinkedList<Node>::Iterator(nullptr));
}

template <typename K, typename T>
HashMap<K, T>::Iterator::Iterator(
    const unsigned short index,
    const unsigned short capacity,
    const LinkedList<Node>* const lists,
    const typename LinkedList<Node>::Iterator iterator
) noexcept : _index(index), _capacity(capacity),
             _lists(lists), _iterator(iterator) { }

template <typename K, typename T>
bool HashMap<K, T>::Iterator::operator!=(const Iterator& other) const noexcept {
    if (_index == _capacity && other._index == other._capacity) return false;
    if (_index != other._index) return true;
    return _iterator != other._iterator;
}

template <typename K, typename T>
const HashMap<K, T>::Node& HashMap<K, T>::Iterator::operator*() const noexcept {
    return *_iterator;
}

template <typename K, typename T>
HashMap<K, T>::Iterator& HashMap<K, T>::Iterator::operator++() noexcept {
    if (_index == _capacity) return *this;

    ++_iterator;
    if (_iterator != _lists[_index].end()) return *this;

    ++_index;
    for (; _index < _capacity; ++_index) {
        if (_lists[_index].begin() != _lists[_index].end()) {
            _iterator = _lists[_index].begin();
            return *this;
        }
    }

    _index = _capacity;
    _iterator = typename LinkedList<Node>::Iterator(nullptr);
    return *this;
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