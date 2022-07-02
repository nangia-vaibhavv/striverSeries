class Solution {
public:
    void tree(TreeNode *root, vector<string>&ans, string s)
    {
        if(root==NULL)return;
         s+=to_string(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(s);
        }
               s+="->";
        tree(root->left,ans,s);
        tree(root->right,ans,s);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string res="";
        tree(root, ans,res);
        return ans;
    }
};