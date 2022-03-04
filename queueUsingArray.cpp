//Program to implement queue using array

#include<iostream>
using namespace std;

template<typename T>
class queue {
    T *arr;
    int nextIndex;
    int frontIndex;
    int capacity = 4;

   public:

    queue(){
        arr = new T[capacity];
        nextIndex = 0;
        frontIndex = -1;
    } 

    int size(){
        return nextIndex-frontIndex;
    }

    bool isEmpty(){
        return nextIndex == 0;
    }

    void enqueue(T element){
        if(nextIndex == capacity){
            T *newArr = new T[2*capacity];
            for(int i=0; i<capacity; i++){
                newArr[i] = arr[i];
            }
            delete [] arr;
            arr = newArr;
        }
        arr[nextIndex] = element;
        nextIndex++;
        if(frontIndex == -1){
            frontIndex++;
        }
    }

    T dequeue(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return 0;
        }
        frontIndex++;
        return arr[frontIndex-1];
    }

    T front(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return 0;
        }
        if(frontIndex == -1){
            return arr[frontIndex++];
        }
        return arr[frontIndex];
    }
};

int main()
{
    queue<int> q;

    cout << "Front element is: " << q.front() << endl;
    q.enqueue(10);
    cout << "Front element is: " << q.front() << endl;
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << q.dequeue() << endl;
    cout << "Front element is: " << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << "Front element is: " << q.front() << endl;
    cout << q.dequeue() << endl;

    cout << "Size of queue is: " << q.size() ;
 return 0;
}