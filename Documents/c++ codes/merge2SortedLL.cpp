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

Node *merge(Node *head1, Node *head2){

    Node *newHead = NULL;
    Node *newTail = NULL;
    while(head1 != NULL && head2 != NULL){
        int x = head1->data;
        int y = head2->data;
        if(x < y){
            if(newHead == NULL){
                newHead = head1;
                newTail = head1;
            }else{
                newTail->next = head1;
                newTail = head1;
            }
            head1 = head1->next;
        }else{
            if(newHead == NULL){
                newHead = head2;
                newTail = head2;
            }
            else{
                newTail->next = head2;
                newTail = head2;
            }
            head2 = head2->next;
        }
    }
    if(head1 == NULL){
        newTail->next = head2;
    }else{
        newTail->next = head1;
    }

    return newHead;
}

void print(Node *newHead){
    while(newHead != NULL){
        cout << newHead->data << " ";
        newHead = newHead->next ;
    } 
}

int main()
{
    int n,m;
    cin >> n >> m;
    Node *head1 = takeInput(n);
    Node *head2 = takeInput(m);

    Node *newHead = merge(head1,head2);
    print(newHead);
    return 0;
}