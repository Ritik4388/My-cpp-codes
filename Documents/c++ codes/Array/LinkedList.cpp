
#include<iostream>
using namespace std;

class node {
   public: 
    int data;
    node *next;

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
            head = newNode;
            tail = newNode;
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
    node *temp = head;
    while(temp->next != NULL){
        cout << temp->data << " "  ;
        temp = temp->next;
    }
    cout << temp->data;
}

int main()
{

    node *head = takeInput();
    print(head);
    return 0;

}