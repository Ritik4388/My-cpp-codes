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

node* inputData(int n){
    int data;
    cin >> data;
    n--;
    node *head = NULL;
    node *tail = NULL;

    while(n>=0){

        node *newNode = new node(data);

        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode ;
            tail = newNode ;
        }
        if(n==0) break;
        else  cin >> data ;
        n--;
    }
    return head ;
}

node *insert(int i, int newData, node *head){

    node *newNode = new node(newData);
    node *temp = head;

    if(i == 0){
        newNode->next = head;
        head = newNode;
    }
    else{
      for(int j=0; j<i; j++){
        if(j == i-1){
            node *old = temp->next;
            temp->next = newNode;
            newNode->next = old ;
        }
        temp = temp->next;
      }
    }
    return head;
}

void print(node *head){
    node *temp = head;
    while(temp != NULL){
        cout << temp->data << " " ;
        temp = temp->next;
    }
}

int main()
{
    int n;
    cin >> n;
    node *head = inputData(n);
    
    int i ,newData;
    cin >> i >> newData;
    head = insert(i,newData,head);

    print(head);

 return 0;
}