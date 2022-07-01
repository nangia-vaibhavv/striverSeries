class Solution {
public:
    void postorderUtil(TreeNode *root, vector<int>&ans)
    {
        if(root==NULL) return;
        if(root->left)
        {
            postorderUtil(root->left,ans);
        }
        if(root->right)
        {
            postorderUtil(root->right,ans);
        }
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        postorderUtil(root,ans);
        return ans;
    }
};