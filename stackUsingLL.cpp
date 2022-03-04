#include<iostream>
using namespace std;

class Node{
  public:
    int data;
    Node *next;
    
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class stackLL{
    Node *head;
    int totalNode;

    public:

    //initialising constructor
    stackLL(){ 
        head = NULL;
        totalNode = 0;
    }

    int size(){
        return totalNode;
    }

    bool isEmpty(){
        return totalNode==0 ;
    }

    void push(int element){
        Node *newNode = new Node(element);
        newNode->next = head;
        head = newNode;
        totalNode++;
    }

    void pop(){
        if(totalNode == 0){
            cout << "Stack is empty" << endl;
            return;
        }
        cout << head->data << endl;
        Node *temp = head;
        head = head->next;
        delete [] temp;
        totalNode--;
    }

    void top(){
        if(totalNode == 0){
            cout << "Stack is empty" << endl;
            return;
        }
        cout << head->data << endl;
    }
};

int main()
{
    stackLL s;

    cout << "size of stack is: " << s.size() << endl;
    s.push(10);
    s.push(120);
    s.push(104);
    cout << "size of stack is: " << s.size() << endl;
    s.pop();
    s.pop();
    cout << "size of stack is: " << s.size() << endl;
    s.top();
    s.pop();

   cout << s.isEmpty() << endl;
 return 0;
}