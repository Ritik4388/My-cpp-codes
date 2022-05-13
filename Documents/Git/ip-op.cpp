#include<iostream>
#include "treeNode.h"
#include<queue>
using namespace std;

treeNode<int>* takeInput(){
      
    

    int rootData;
    cout << "Enter Root data: " ;
    cin >> rootData;
    if(rootData == -1){
        return NULL;
    }

    treeNode<int>* root = new treeNode<int>(rootData);
    queue<treeNode<int>*> nodes;
    nodes.push(root);

    while(nodes.size() != 0){

        treeNode<int>* front = nodes.front();
        nodes.pop();
                int leftChild;
                cout << "Enter left child of " << front->data << endl;
                cin >> leftChild;
                if(leftChild != -1){
                    treeNode<int>* childNode = new treeNode<int>(leftChild);
                    front->left = childNode;
                    nodes.push(childNode);
                }
                int rightChild;
                cout << "Enter right child of " << front->data << endl;
                cin >> rightChild;
               if(rightChild != -1){
                    treeNode<int>* childNode = new treeNode<int>(rightChild);
                    front->right = childNode;
                    nodes.push(childNode);
               }

        }

    return root;
}

void printTree(treeNode<int>* root){

    if(root == NULL){
        return;
    }
    
    queue<treeNode<int>*> nodes;
    nodes.push(root);

    while(nodes.size() != 0){

        treeNode<int>* front = nodes.front();
        nodes.pop();
        cout << front->data << ": " ;
        if(front->left != NULL){
            cout << "L" << front->left->data;
            nodes.push(front->left);
        }
        if(front->right != NULL){
            cout << " R" << front->right->data;
            nodes.push(front->right);
        }
        cout << endl;
    }
}

int height(treeNode<int>* root){
    
    if(root == NULL){
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);

    return 1 + max(lh,rh) ;
}

void preOrder(treeNode<int>* root){
    
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(treeNode<int>* root){
    
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
    
}

void inOrder(treeNode<int>* root){
    
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);  

}

//1 2 3 4 5 6 7 -1 -1 -1 -1 8 -1 -1 9 -1 -1 -1 -1

int main(){

    treeNode<int>* root = takeInput();
    printTree(root);
    cout << "height of tree is " << height(root)-1 << endl;
    cout << "Pre-Order : ";
    preOrder(root); 
    cout << endl << "Post-Order : ";
    postOrder(root);
    cout << endl << "In-Order : ";
    inOrder(root);

}