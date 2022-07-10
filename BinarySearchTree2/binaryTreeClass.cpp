class BSTIterator {
    vector<TreeNode*> inorder;
    int i;
    void solve(TreeNode* root) {
        if(!root)
            return;
        solve(root->left);
        inorder.push_back(root);
        solve(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        inorder={new TreeNode(-1)};
        solve(root);
        i=0;
    }
    
    int next() {
         return inorder[++i]->val;
    }
    
    bool hasNext() {
        return i<inorder.size()-1;
    }
};