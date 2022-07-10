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

// or
class Solution {
    unordered_set<int> s;
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;

        if(s.count(k - root->val))
            return true;
        else
            s.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};