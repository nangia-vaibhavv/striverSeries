class Solution {
public:
    void preorderUtil(TreeNode *root, vector<int>&ans)
    {
        if(root==NULL) return;
        ans.push_back(root->val);
        if(root->left)
        {
            preorderUtil(root->left,ans);
        }
        if(root->right)
        {
            preorderUtil(root->right,ans);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        preorderUtil(root,ans);
        return ans;
    }
};