/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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