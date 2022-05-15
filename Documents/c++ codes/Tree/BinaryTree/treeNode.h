
template<typename T>
class treeNode {

    public:
    T data;
    treeNode* left;
    treeNode* right;

    treeNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

    // ~treeNode(treeNode<int>* root){
    //     delete root;
    // }
};