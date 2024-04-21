#include "../include/hash_table.h"

template <typename K, typename V>
HashTable<K, V>::HashTable(int size) : tableSize(size), table(size) {}

template <typename K, typename V>
void HashTable<K, V>::insert(const K& key, const V& value) {
    int index = hashFunction(key, tableSize);

    auto& chain = table[index];
    for (auto& entry : chain) {
        if (entry.first == key) {
            entry.second = value;
            return;
        }
    }

    chain.emplace_back(key, value);
}

template <typename K, typename V>
bool HashTable<K, V>::remove(const K& key) {
    int index = hashFunction(key, tableSize);

    auto& chain = table[index];
    for (auto it = chain.begin(); it != chain.end(); ++it) {
        if (it->first == key) {
            chain.erase(it);
            return true;
        }
    }
    return false;
}

template <typename K, typename V>
V* HashTable<K, V>::find(const K& key) {
    int index = hashFunction(key, tableSize);

    auto& chain = table[index];
    for (auto& entry : chain) {
        if (entry.first == key) {
            return &entry.second;
        }
    }
    return nullptr;
}

template <typename K, typename V>
int HashTable<K, V>::hashFunction(const K& key, int size) {
    return key % size;
}

template class HashTable<int, std::string>;