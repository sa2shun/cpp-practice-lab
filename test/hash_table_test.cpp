#include <cassert> 
#include "../include/hash_table.h"

int main() {
    HashTable<int, std::string> hashTable(10);

    // 挿入のテスト
    hashTable.insert(1, "One");
    hashTable.insert(2, "Two");
    hashTable.insert(3, "Three");

    // 検索のテスト
    assert(*hashTable.find(1) == "One");
    assert(*hashTable.find(2) == "Two");
    assert(*hashTable.find(3) == "Three");

    // 上書きのテスト
    hashTable.insert(1, "Uno");
    assert(*hashTable.find(1) == "Uno");

    // 削除のテスト
    hashTable.remove(2);
    assert(hashTable.find(2) == nullptr); // 削除後に見つからないことを確認

    // ハッシュ衝突のテスト
    hashTable.insert(5, "Five");
    hashTable.insert(15, "Fifteen"); // 衝突を期待
    assert(*hashTable.find(5) == "Five");
    assert(*hashTable.find(15) == "Fifteen");

    // 存在しないキーを検索するテスト
    assert(hashTable.find(100) == nullptr); // 存在しないキーを確認

    return 0; // テストが成功したことを示す
}
