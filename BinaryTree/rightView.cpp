class Solution {
public:
    int maxLevel=0;
    void rightSideViewUtil(TreeNode*root,int level, vector<int>&ans)
    {
        if(root==NULL) return;
        if(maxLevel<level)
        {
            ans.push_back(root->val);
            maxLevel=level;
        }
        if(root->right)
        {
            rightSideViewUtil(root->right,level+1,ans);
        }
        if(root->left)
        {
            rightSideViewUtil(root->left,level+1,ans);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        rightSideViewUtil(root,1, ans);
        return ans;
    }
};