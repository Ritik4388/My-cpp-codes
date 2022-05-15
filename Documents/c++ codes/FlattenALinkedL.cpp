#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node *next;
    Node *child;

    Node(int data){
        this->data = data;
        next = NULL;
        child = NULL;
    }

};

Node *takeInput(int n){

    int data;
    int childData;
    Node *head = NULL;
    Node *tail = NULL;
    
    while(n>0){
        cin >> data;
        Node *newNode = new Node(data);
        if(head == NULL){

            head = newNode;
            tail = newNode;
            cin >> childData;
            Node *childTail = NULL;
            while(childData != -1){

                Node *newChildNode = new Node(childData);
                childTail->child = newChildNode;
                childTail = newChildNode;
                cin >> childData;
            }

        }else{

            tail->next = newNode;
            tail = newNode;
            
            cin >> childData;
            Node *childTail = NULL;
            while(childData != -1){

                Node *newChildNode = new Node(childData);
                childTail->child = newChildNode;
                childTail = newChildNode;
                cin >> childData;
            }
        }
        n--;
    }

    return head;
}

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
    if(head->next == NULL || head == NULL){
        return head;
    }
    Node *left = head;
    left->next = NULL;
    while(left->child != NULL){
        left = left->child; 
    }  
    Node *right = flattenLinkedList(head->next);  
    left->child = right;

    return head;   
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
    cin >> n;
    Node *head = takeInput(n);
    Node *newHead = flattenLinkedList(head);
    print(newHead);
 return 0;
}