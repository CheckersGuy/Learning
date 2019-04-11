#include <iostream>
#include <cstring>
#include <memory>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <random>

//Will test if this works tomorrow

template <class T> class ExSort{

private:
    const std::string path;
    std::ifstream stream;
    std::ofstream stream2;
    static constexpr int chunkSize =10000;

    void sortChunk(size_t begin, size_t end){
        std::unique_ptr<T[]>array=std::make_unique<T[]>((end-begin));
        auto position=stream.tellg();
        stream.read((char*)array.get(),sizeof(T)*(end-begin));
        stream.seekg(position);
        std::sort(array.get(),array.get()+(end-begin));
        stream2.write((char*)array.get(),sizeof(T)*(end-begin));
    }

    void sort(size_t begin,size_t end){
        if((end-begin)<=chunkSize){
            sortChunk(begin,end);
            return;
        }

    }

    size_t getFileSize(){
        stream.seekg(0,stream.beg);
        stream.ignore(std::numeric_limits<std::streamsize >::max());
        auto count= stream.gcount();
        stream.seekg(0,stream.beg);
        return count;
    }


public:

    ExSort(const std::string path):path(path){
        stream.open(path,std::ios::binary);
        stream2.open(path,std::ios::binary);
    }



    void sort(){
        auto fileSize=getFileSize();
        auto numObjects=fileSize/sizeof(T);

        sort(0,numObjects);

    }

};



int main() {

    //in theory counting the number of "read input" is quite simple


    ExSort<int>sorter("num.test");
    sorter.sort();

    std::ifstream stream("num.test");

    int array[8];

    stream.read((char*)array,sizeof(int)*8);

    for(int i=0;i<8;++i)
        std::cout<<array[i]<<std::endl;
    return 0;
}