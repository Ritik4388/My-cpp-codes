#include<iostream>
using namespace std;

template<typename T>
class stackArray {
    T *data;
    int top;
    int capacity;

    public:

    stackArray(int totalSize){
        data = new T[totalSize];
        top = 0;
        capacity = totalSize;
    }

    //to get the present size of stack

    T size(){
        return top;
    }

    //to check if stack is empty

    bool isEmpty(){
        if(top==0){
            return true;
        }else{
            return false;
        }
    }

    //to insert a new element to the stack

    void push(int element){
        if(top ==  capacity){
            cout << "Stack overflow" << endl ;
            return;
        }
        data[top] = element;
        top++;
    }

    //to delete the top element from the stack

    T pop(){
        if(top == 0){
            cout << "stack is empty" << endl;
            return 0;
        }
        top--;
        return data[top];
    }

    //to check the top element of the stack

    T topElement(){
        if(top == 0){
            cout << "Stack is empty" << endl;
            return 0;
        }
        return data[top-1];
    }
};

int main()
{
    stackArray<int> s1(4);
    
    s1.push(105);
    s1.push(150);
    s1.push(125);
     cout << "current size of stack is : " << s1.size() << endl;
    s1.push(135);
    s1.push(145);
    
    cout << "current size of stack is : " << s1.size() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
     cout << "current size of stack is : " << s1.size() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;

    cout << s1.topElement() << endl;
     cout << "current size of stack is : " << s1.size() << endl;
     cout << "stack is empty ? " << s1.isEmpty() ;
 return 0;
}