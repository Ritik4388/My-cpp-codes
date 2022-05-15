// Given a tree and an integer x, find and return the number of nodes which contains data greater than x.
// Input format:
// The first line of input contains data of the nodes of the tree in level order form. 
// The order is: data for root node, number of children to root node, data of each of child 
// nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.  
// The following line contains an integer, that denotes the value of x.

// Output Format :
// The first and only line of output prints the count of nodes greater than x.



#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class treeNode {

    public:
      int data;
      vector<treeNode*> child;

      treeNode(int data){
          this->data = data;
      }

};

treeNode* takeInput(){

    int data;
    cout << "Enter data: " ;
    cin >> data;
    treeNode* root = new treeNode(data);
    queue<treeNode*> inputQueue;
    inputQueue.push(root);

    while(!inputQueue.empty()){

        treeNode* frontNode = inputQueue.front();
        inputQueue.pop();
        int nChild;
        cout << "Enter No. of children of " <<frontNode->data << ": ";
        cin >> nChild;
        for(int i=0; i<nChild; i++){
            cout << "Enter " << i+1 <<"th child of " << frontNode->data << ": " ;
            int childData;
            cin >> childData;
            treeNode* childNode = new treeNode(childData);
            frontNode->child.push_back(childNode);
            inputQueue.push(childNode);
        }
    }
    return root;
}

int greaterNodes(treeNode* root, int x){
    
    if(root == NULL){
        return 0;
    }
    int count = 0;
    if(root->data > x) count++;
    queue<treeNode*> outputQueue;
    outputQueue.push(root);
    while(!outputQueue.empty()){
        treeNode* frontData = outputQueue.front();
        outputQueue.pop();
        for(int i=0; i<frontData->child.size(); i++){
            if(frontData->child[i]->data > x){
                count++;
            }
            outputQueue.push(frontData->child[i]);
        }
    }
   return count;
}

void printTree(treeNode* root){

    if(root == NULL){
        return ;
    }
    queue<treeNode*> outputQueue;
    outputQueue.push(root);
    while(!outputQueue.empty()){
        
        cout << endl;
        treeNode* frontData = outputQueue.front();
        outputQueue.pop();
        cout << frontData->data << ": ";
        for(int i=0; i<frontData->child.size(); i++){
            cout << frontData->child[i]->data << "," ;
            outputQueue.push(frontData->child[i]);
        }
    }
}

int main(){
    //1 2 2 3 2 4 5 0 0 0
    treeNode* root = takeInput();
    int x;
    cout << "Enter an Integer to check how much tree node data are greater than that: " ;
    cin >> x;
    cout << "No. of nodes greater than " << x << " is " << greaterNodes(root,x) ;
    return 0;
}