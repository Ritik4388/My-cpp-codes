#include<iostream>
using namespace std;

//template<typename T>
class Node {
   public: 
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

//template<typename T>
class queue {
    Node *head;
    Node *tail;
    int totalNode;

  public:
    queue(){
        head = NULL;
        tail = NULL;
        totalNode = 0;
    }

    int size(){
        return totalNode;
    }

    bool isEmpty(){
        return totalNode == 0;
    }

    void enqueue(int element){
        Node *newNode = new Node(element);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            totalNode++;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        totalNode++;
    }

    int dequeue(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return 0;
        }
        int ans = head->data;
        Node *temp = head;
        head = head->next;
        delete [] temp;
        totalNode--;
        return ans;
    }

    int front(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return 0;
        }
        return head->data;
    }
};

int main()
{
    queue q;

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

    cout << "Size of queue is: " << q.size() << endl;
    cout << "Front element is: " << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << "Size of queue is: " << q.size() << endl ;
    cout << "Front element is: " << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << "Size of queue is: " << q.size() << endl ;
 return 0;
}