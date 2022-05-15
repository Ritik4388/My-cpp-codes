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

Node *takeInput(int n){

    int data;
    Node *head = NULL;
    Node *tail = NULL;

    while(n>0){

        cin >> data;
        Node *newNode = new Node(data);

        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }

        n--;
    }

    return head;
}

Node *reverse(Node *head){

    Node *temp = head;
    if(head->next == NULL || head == NULL){
        return head;
    }
    while(temp->next->next != NULL){

        temp = temp->next;

    }
    Node *newHead = temp->next;
    temp->next = NULL;
    newHead->next = reverse(head);
    return newHead;
}

void print(Node *head){

    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }

}

int main()
{
    int n;
    cin >> n ;
    Node *head = takeInput(n);
    Node *newHead = reverse(head);
    print(newHead);
 return 0;
}