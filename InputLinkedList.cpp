//inputing data till user enter -1 in a linked list.

#include<iostream>
using namespace std;

class node {
   public: 
    int data;
    node * next;

    node(int data){
        this->data = data;
        next = NULL;
    }
};

node* takeInput(){
    int data;
    cin >> data;
    node *head = NULL;
    node *tail = NULL;
    while(data != -1){
        if(head == NULL){
            node *newNode = new node(data);
            head = newNode;                  // when there will be first input ,there will be only one node 
            tail = newNode;                  // which will point as head as well as tail of the ll.   
        }
        else{
            node *newNode = new node(data);
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(node *head){
    while(head != NULL){
        cout << head->data << endl ;
        head = head->next;
    }
}

int main(){
    node *head = takeInput();
    print(head);
    return 0;
}
