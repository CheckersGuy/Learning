#include <iostream>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <thread>
#include <cstring>
#include <optional>
#include <vector>
#include <algorithm>



template<class K, class T>class SimpleHash{
    struct Entry{
        K key;
        T value;
    };

    using Bucket =std::vector<Entry>;


private:
    size_t capacity;
    size_t size;
    std::unique_ptr<Bucket[]>array;
    std::hash<T>hasher;

public:

    SimpleHash(size_t capacity):capacity(capacity),size(0){
        array=std::make_unique<Bucket[]>(capacity);

    }

    void put(K key, T value){
        size++;
        auto hash=hasher(key);
        size_t index=hash%capacity;
        Entry next;
        next.key=key;
        next.value=value;
        array[index].emplace_back(next);
    }

    std::optional<T>get(K key)const{
        std::optional<T>result;
        auto hash=hasher(key);
        size_t index=hash%capacity;

        auto it=std::find_if(array[index].begin(),array[index].end(),[&](const Entry& other){
            return other.key==key;
        });

        if(it!=array[index].end()){
            result=(*it).value;
        }

        return result;
    }

    bool has(K key)const{
        auto hash=hasher(key);
        size_t index=hash%capacity;
        auto it=std::find_if(array[index].begin(),array[index].end(),[&](const Entry& other){
            return other.key==key;
        });

        return (it!=array[index].end());
    }

    size_t getSize()const{
        return size;
    }

    size_t getCapacity()const{
        return capacity;
    }

    bool isEmpty()const{
        return size==0;
    }

};


int main() {

    SimpleHash<int,int>hash(1<<16);

    hash.put(1,1);
    hash.put(2,2);
    hash.put(3,3);

    std::cout<<"Has: "<<hash.has(1)<<std::endl;
    std::cout<<"Has: "<<hash.has(2)<<std::endl;
    std::cout<<"Has: "<<hash.has(4)<<std::endl;



    return 0;
}
