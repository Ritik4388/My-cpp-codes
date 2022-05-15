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

void print(node *head,int n,node *add, int newData){
    int count=0;
    while(head != NULL){
        node *hea = head;
        if(count == n){
            node *temp = hea->next;
            hea->next = add;
            add->data = newData;
            add->next = temp;
        }
        else{
          hea = hea->next;
          count++;
          if(count > n){
              return ;
          }
        }
    }
    while(head != NULL){
        cout << head->data << " " ;
    }
}

int main(){
       int n,newData;
       cin >> n >> newData ;
       node *add = new node(newData);
       node *head = takeInput();
       print(head,n,add,newData); 
    return 0;
}
