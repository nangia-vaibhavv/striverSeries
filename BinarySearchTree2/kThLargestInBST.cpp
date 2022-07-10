// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public:
    vector<int>res;
    void inorderUtil(Node*root)
{
if(root==NULL) return;
inorderUtil(root->left);
res.push_back(root->data);
inorderUtil(root->right);
}
    int kthLargest(Node *root, int K)
    {
        //Your code here
        inorderUtil(root);
        int n=res.size();
        return res[n-K];
    }
};