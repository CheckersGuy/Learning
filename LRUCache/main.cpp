#include <iostream>
#include <functional>
#include "Cache.h"




int main() {
    Cache<int,int> cache(100);
    cache.put(1,1);
    cache.put(2,2);
    cache.put(3,3);

    for(auto& [key, value] : cache){
        std::cout<<"Key"<<key<<" Value "<<value<<std::endl;
    }


    return 0;
}