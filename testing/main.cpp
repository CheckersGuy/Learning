#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <iostream>
#include <future>
#include <list>
#include <algorithm>
#include <unordered_map>


template<typename K, typename T>
class LRUCache {
private:
    mutable std::list<std::pair<K, T>> liste;
    std::unordered_map<K, decltype(liste.begin())> map;
    size_t cacheSize;
public:

    LRUCache(size_t capacity) : cacheSize(capacity) {}

    LRUCache(const LRUCache &other) = delete;

    LRUCache &operator=(const LRUCache &other) = delete;

    void put(K key, T value) {
        auto it = map.find(key);
        if (it == map.end()) {
            //not in our list
            if (map.size() > cacheSize) {
                auto &back = liste.back();
                liste.pop_back();
                map.erase(back.first);
            }
            auto pair = std::make_pair(key, value);
            liste.push_front(pair);
            map.insert(std::make_pair(key, liste.begin()));
        } else {
            liste.splice(liste.begin(), liste, it->second);
        }
    }

    std::optional<T> get(K key) const {
        std::optional<T> result;
        auto it = map.find(key);
        if (it != map.end()) {
            result = it->second->second;
            liste.splice(liste.begin(), liste, it->second);
        }
        return result;
    }

    auto capacity() const {
        return cacheSize;
    }

    auto size() const {
        return map.size();
    }

    auto begin() {
        return liste.begin();
    }

    auto end() {
        return liste.end();
    }


};


int main(int argl, const char **argc) {

    LRUCache<int, int> cache(100);
    cache.put(1, 1);
    cache.put(2,2);
    cache.put(3,3);
    std::cout << "size: " << cache.size() << std::endl;

    auto result=cache.get(1);



    for(auto& [key, val] : cache){
        std::cout<<"Value: "<<val<<std::endl;
    }


    return 0;
}