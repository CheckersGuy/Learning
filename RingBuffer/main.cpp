#include <iostream>
#include <memory>


/*
 * need to check that implementation for correctness
 */

template<class T>
class RingBuffer{
private:
    size_t size,back,front;
    const size_t capacity;
    std::unique_ptr<T[]>array;

public:

    RingBuffer(const size_t capacity):capacity(capacity),size(0),front(0),back(0),array(std::make_unique<T[]>(capacity)){}

    void put(T value){
        array[back]=value;
        back=(back+1)%capacity;
        if(size==capacity){
            front=(front+1)%capacity;
        }else{
            size++;
        }

    }

    T pop(){
        T temp=array[front];
        front=(front+1)%capacity;
        size--;
        return temp;
    }

    T top(){
        return array[front];
    }

    bool isEmpty()const{
        return size==0;
    }

    bool isFull()const{
        return size==capacity;
    }

    void reset(){
        front=0;
        back=capacity-1;
    }

    size_t length(){
        return size;
    }

};



int main() {

    RingBuffer<int> buffer(5);

    buffer.put(1);
    buffer.put(2);
    buffer.put(3);
    buffer.put(4);
    buffer.put(5);
    buffer.put(6);
    while(!buffer.isEmpty()){
        std::cout<<buffer.pop()<<std::endl;
    }



    return 0;
}