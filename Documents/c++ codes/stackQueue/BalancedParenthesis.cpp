//Program to check if given string of paranthesis is balanced or not 

#include<iostream>
#include<string>
using namespace std;

template<typename T>
class stack {
    T *data;
    int top;
    int capacity;

   public:

    stack(){
        data = new T[4];
        top = 0;
        capacity = 4;
    } 

    int size(){
        return top;
    }

    bool isEmpty(){
        return top <= 0;
    }

    void push(T element){
        if(top == capacity){
            T *newData = new T[2*capacity];
            for(int i=0; i<capacity; i++){
                newData[i] = data[i];
            }
            delete [] data;
            data = newData;
        }
        data[top] = element;
        top++;
    }

    T pop(){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
            return 0;
        }
        top--;
        return data[top];
    }

    T topElement(){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
            return 0;
        }
        return data[top-1];
    }

};

int main()
{
    stack<char> s;
    int flag = 0;
    string str;
    cin >> str;

    for(int i=0; i<str.length(); i++){
        if(str[i] == '[' || str[i] == '{' || str[i] == '('){
            s.push(str[i]);
        }
        else{
            char x = s.pop();
            if(x == '(' && str[i] == ')'){
                flag++;
            }else if(x == '{' && str[i] == '}'){
                flag++;
            }else if(x == '[' && str[i] == ']'){
                flag++;
            }else{
                flag = 0;
                break;
            }
        }
    }
    if(s.size()>0){
            flag = 0;
        }
    if(flag!= 0){
        cout << "balanced" << endl;
    }else{
        cout << "unbalanced" << endl;
    }
 return 0;
}