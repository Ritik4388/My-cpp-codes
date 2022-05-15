//program to find sum of all ghiven nodes of tree & to find out the largest node among all the given nodes
//& to print the given tree level by level ;
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class treeNode {

    public :
      int data;
      vector<treeNode*> child;

      treeNode(int data){
          this->data = data;
      }

};

treeNode* takeInput(){

    cout << "Enter root data: " ;
    int data;
    cin >> data;
    treeNode* root = new treeNode(data);
    queue<treeNode*> inputQueue;
    inputQueue.push(root);

    while(!inputQueue.empty()){

        treeNode* frontNode = inputQueue.front();
        inputQueue.pop();
        cout << "Number of child of " << frontNode->data << ": " ;
        int nChild;
        cin >> nChild;
        for(int i=0; i<nChild; i++){
            cout << "Enter " << i+1 << "th child of " << frontNode->data << ": ";
            int childData;
            cin >> childData;
            treeNode* children = new treeNode(childData);
            frontNode->child.push_back(children);
            inputQueue.push(children);
        }
        
    }
    return root;
}

int printTree(treeNode* root){

    queue<treeNode*> outputQueue;
    outputQueue.push(root);
    int largest = 0;

    while(!outputQueue.empty()){

        treeNode* frontN = outputQueue.front();
        if(largest<frontN->data){   // to find out the largest nodes among all given nodes
            largest = frontN->data;
        }
        cout << frontN->data << ": ";
        outputQueue.pop();
        for(int i=0; i<frontN->child.size(); i++){
            cout << frontN->child[i]->data << "," ;
            outputQueue.push(frontN->child[i]);
        }
        cout << endl;
    }
    return largest;

}

int sum(treeNode* root){        //we don't require this function specifically for sum of all nodes , we can instead 
                                //apply all logic of sum to printTree function. 
    int sum = root->data;       // created specific function just for simplicity .
    queue<treeNode*> outputQueue;
    outputQueue.push(root);

    while(!outputQueue.empty()){

        treeNode* frontN = outputQueue.front();
        outputQueue.pop();
        for(int i=0; i<frontN->child.size(); i++){
            sum += frontN->child[i]->data ;
            outputQueue.push(frontN->child[i]);
        }
    }
    return sum ;
}

int main()
{
    treeNode* root = takeInput();
    int largest = printTree(root);
    cout << "Sum of all nodes is: " << sum(root) << endl;
    cout << "largest node among all is: " << largest << endl;
 return 0;
}