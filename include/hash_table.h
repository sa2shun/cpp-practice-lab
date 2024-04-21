#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <list>
#include <utility>

template <typename K, typename V>
class HashTable {
public:
    HashTable(int size);
    void insert(const K& key, const V& value);
    bool remove(const K& key);
    V* find(const K& key);

private:
    int tableSize;
    std::vector<std::list<std::pair<K, V> > > table;

    int hashFunction(const K& key, int size);
};

#endif
