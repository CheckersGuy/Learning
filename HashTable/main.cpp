#include <iostream>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <thread>
#include <cstring>
#include <optional>
#include <vector>
#include <algorithm>



template<typename K, typename T, template<typename Ex> class Hasher = std::hash>
class SimpleTable {
    struct Entry {
        K key;
        T value;
    };

    using Bucket = std::vector<Entry>;
private:
    Hasher<K> hasher;
    size_t capacity;
    size_t size{0ull};
    std::unique_ptr<Bucket[]> buckets;

public:

    SimpleTable(const SimpleTable &other) = delete;

    SimpleTable(SimpleTable &&other) = delete;

    SimpleTable(size_t size) : capacity(size), buckets(std::make_unique<Bucket[]>(size)) {

    }

    void insert(K key, T value) {
        auto index = hasher(key);
        index %= capacity ;
        auto it = std::find_if(buckets[index].begin(), buckets[index].end(), [&](Entry &entry) {
            return entry.key == key;
        });
        if (it == buckets[index].end()) {
            size++;
            buckets[index].emplace_back(Entry{key, value});
        }
    }

    std::optional<T> get(K key) {
        auto index = hasher(key);
        index %= capacity ;
        auto it = std::find_if(buckets[index].begin(), buckets[index].end(), [&](Entry &entry) {
            return entry.key == key;
        });
        if (it != buckets[index].end()) {
            return std::make_optional((*it).value);
        }
        return std::nullopt;
    }

};


int main(int argl, const char **argc) {

    SimpleTable<int, int> table(128);
    table.insert(2, 2);
    auto val = table.get(2);
    if(val.has_value()){
        std::cout<<"Got the value: "<<val.value()<<std::endl;
    }


    return 0;
}

