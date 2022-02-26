#include<iostream>
using namespace std;

class Node {

    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL ;
    }
};

Node *takeInput(int n){

    int data;

    Node *head = NULL ;
    Node *tail = NULL ;

    while(n>0){
        cin >> data;
        Node *newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        n--;
    }
    return head;
}

void midPoint(Node *head,int n){

    Node *mid = head ;
    Node *end = head->next ;

    if(n%2 != 0){
        while(end != NULL){
            mid = mid->next;
            end = end->next->next;
        }
    }else{
        while(end->next != NULL){
            mid = mid->next;
            end = end->next->next;
        }
    }
    cout << mid->data ;
}

int main()
{
    int n;
    cin >> n;
    Node *head = takeInput(n);
    midPoint(head,n);
    return 0;
}