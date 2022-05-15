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


Node *merge(Node *head , Node *head2){

    Node *newhead = NULL;
    Node *newTail = NULL;

    while(head != NULL && head2 != NULL){

        int x = head->data;
        int y = head2->data;
        if(x < y){

            if(newhead == NULL){
                newhead = head ;
                newTail = head ; 
            }else{
                newTail->next = head;
                newTail = head;
            }
            head = head->next;

        }else{

            if(newhead == NULL){
                newhead = head2 ;
                newTail = head2 ; 
            }else{
                newTail->next = head2;
                newTail = head2;
            }
            head2 = head2->next;

        }

    }

    if(head == NULL){
        newTail->next = head2;
    }else{
        newTail->next = head;
    }

    return newhead;
}

Node *mergeSort(Node *head, int n){
    
    Node *temp = head;
    if(temp == NULL || temp->next == NULL){
        return temp;
    }
        int t = (n-1)/2;
        while(t>0){
        temp = temp->next;
        t--;
        }

        Node *head2 = temp->next;
        temp->next = NULL;

        head = mergeSort(head,n/2);
        int n2 = n - n/2 ;
        head2 = mergeSort(head2,n2);
        Node *newHead = merge(head,head2);

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
    Node *newHead = mergeSort(head,n);
    print(newHead);
 return 0;
}