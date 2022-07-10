class Solution {
public:
    void inorderUtil(TreeNode*root, vector<int>&res)
    {
        if(root==NULL) return;
        inorderUtil(root->left,res);
        res.push_back(root->val);
        inorderUtil(root->right,res);
    }
    bool findTwoSum(vector<int>&res, int k)
    {
        int n=res.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(res[i]+res[j]==k)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>res;
        inorderUtil(root,res);
//         after getting inorderTraversal array
       return findTwoSum(res,k);
    }
};