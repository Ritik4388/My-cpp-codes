#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class TreeNode {

    public:
      T data;
      vector<TreeNode<T>*> child;

      TreeNode(T data){
          this->data = data;
      }

};

TreeNode<int>* takeInput(){

    int data;
    cout << "Enter data: ";
    cin >> data;
    TreeNode<int> *root = new TreeNode<int>(data);
    queue<TreeNode<int>*> node;
    node.push(root);

    while(node.size() != 0){
        
        TreeNode<int>* frontNode = node.front();
        node.pop();
        cout << "Number of children of " << frontNode->data << ": ";
        int numOfChild;
        cin >> numOfChild;
        for(int i=1; i<=numOfChild; i++){
            cout << "Enter " << i << "th child of " << frontNode->data<< ": "; 
            int child;
            cin >> child;
            TreeNode<int>* childNode = new TreeNode<int>(child); 
            frontNode->child.push_back(childNode);
            node.push(childNode);      
        }
    }
    return root;
}


void printTree(TreeNode<int>* root){

    if(root == NULL){
        return;
    }
    queue<TreeNode<int>*> outputQueue ;
    outputQueue.push(root);

    while(!outputQueue.empty()){
        
        TreeNode<int>* frontNode = outputQueue.front();
        outputQueue.pop();
        cout << frontNode->data << ": " ;
        for(int i=0; i<frontNode->child.size(); i++){
            cout << frontNode->child[i]->data << "," ;
            outputQueue.push(frontNode->child[i]);
        }
        cout << endl;
    }
    
} 

int main()
{
    TreeNode<int>* root = takeInput();
    printTree(root);
 return 0;
}