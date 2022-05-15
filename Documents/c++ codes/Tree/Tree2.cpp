//Basic method implementat

#include<iostream>
#include<vector>
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
    int data,n;
    cout << "Enter data: " ;
    cin >> data;
    TreeNode<int>* root = new TreeNode<int>(data);
    cout << "Enter number of children of " << data << ": " ;
    cin >> n;
    for(int i=0; i<n; i++){
        cout << "child number " << i+1 << " of " << data << endl;
        root->child.push_back(takeInput());
    }
    return root;
}

void printTree(TreeNode<int>* root){
    if(root == NULL){
        return ;
    }
    cout << root->data << ": ";
    for(int i=0; i<root->child.size(); i++){
        cout << root->child[i]->data << ",";
    }
    cout << endl;
    for(int i=0; i<root->child.size(); i++){
        printTree(root->child[i]);
    }
}

int main()
{
    TreeNode<int>* root = takeInput();
    printTree(root);
 return 0;
}