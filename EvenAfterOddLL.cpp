#include<iostream>
using namespace std;

class Node {
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
    while(n>0) {
        cin >> data;
        Node *newNode = new Node(data);
        if(head == NULL){
            head = newNode ;
            tail = newNode ;
        }
        else{
            tail->next = newNode ;
            tail = newNode ;
        }
        n-- ;
    }
    return head ;
}

Node *splitAndMerge(Node *head){  //using splitAndMerge function I'm splitting my linked list in two parts , one will be
                                  //even part and other one will be odd part and at the end I'll merge both of them such
    Node *oddHead = NULL;         //it generates a LL in which odd term appear first and then even terms.
    Node *oddTail = NULL;
    Node *evenHead = NULL;
    Node *evenTail = NULL;

    while(head != NULL){
        int x = head->data;
        if(x%2 != 0){

            if(oddHead == NULL){
                oddHead = head ;
                oddTail = head ;
            }
            else{
                oddTail->next = head ;
                oddTail = head ;
            }

        }else{

            if(evenHead == NULL){
                evenHead = head ;
                evenTail = head ;
            }
            else{
                evenTail->next = head ;
                evenTail = head ;
            }

        }
        head = head->next ;
    }

    oddTail->next = NULL;
    evenTail->next = NULL;

    oddTail->next = evenHead;

    return oddHead;
}

void print(Node *head){
    while(head != NULL){
        cout << head->data << " " ;
        head = head->next ;
    }
}

int main()
{   
    int n;
    cin >> n;
    Node *head = takeInput(n);
    Node *newHead = splitAndMerge(head);
    print(newHead);
    return 0;
}