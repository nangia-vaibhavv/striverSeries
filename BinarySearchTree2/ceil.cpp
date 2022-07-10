
int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int ceil=-1;
    while(node)
    {
        if(node->data==x)
        {
            ceil=node->data;
            return ceil;
        }
        if(x<node->data)
        {
            ceil=node->data;
            node=node->left;
        }
        else node=node->right;
    }
    return ceil;
}