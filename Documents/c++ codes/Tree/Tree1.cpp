#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class TreeNode {

    public:
      
      T data;
      vector<TreeNode<T>*> child ;

      TreeNode(T data){
          this->data = data;
      }

};

void printTree(TreeNode<int>* root){

    if(root == NULL){
        return;
    }
    cout << root->data << ": ";
    for(int i=0; i<root->child.size(); i++){
        cout << root->child[i]->data << "," ;
    }
    cout << endl;
    for(int i=0; i<root->child.size(); i++){
        printTree(root->child[i]);
    }
}

int main()
{

    TreeNode<int> *root = new TreeNode<int>(1);
    TreeNode<int> *child1 = new TreeNode<int>(2);
    TreeNode<int> *child2 = new TreeNode<int>(3);
    TreeNode<int> *child3 = new TreeNode<int>(4);

    root->child.push_back(child1);
    root->child.push_back(child2);
    child1->child.push_back(child3);
    printTree(root);
    return 0;
}
