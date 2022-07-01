class Solution {
public:
    void inorderUtil(TreeNode *root, vector<int>&ans)
    {
        if(root==NULL)
            return;
        if(root->left)
        {
            inorderUtil(root->left,ans);
        }
        ans.push_back(root->val);
        if(root->right)
        {
            inorderUtil(root->right,ans);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        inorderUtil(root,ans);
        return ans;
    }
};