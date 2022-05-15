// Given a generic tree and an integer x, check if x is present in the given tree or not. Return true 
//if x is present, return false otherwise.
// Input format :
// The first line of input contains data of the nodes of the tree in level order form. 
//The order is: data for root node, number of children to root node, data of each of child 
//nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.  
// The following line contains an integer, that denotes the value of x.

// Output format :
// The first and only line of output contains true, if x is present and false, otherwise.


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

bool checkData(treeNode* root,int x){
    
    int flag = 0;
    if(root == NULL){
        return 0;
    }
    for(int i=0; i<root->child.size(); i++){
        if(root->child[i]->data == x){
            flag++;
            break;
        }
    }
    return flag != 0;
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
    cout << "Enter an integer to search in tree: " ;
    cin >> x;
    bool ans = checkData(root,x);

    if(ans) cout << "yes" ;
    else {
        cout << "false" ; 
        printTree(root);
    }
    return 0;
}