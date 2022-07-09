class Solution {

public:
          vector<int>res;

    void inorder(TreeNode *root)
    {
        if(root==NULL) return;
         inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);

    }
    bool isValidBST(TreeNode* root) {
         if (!root)
            return true;
        inorder(root);
//         since inorder traversal of bst given nodes in non devcreasing order hence
//         compute inorder traversal of given node and than checkig its order
        for(int i=1;i<res.size();i++)
        {
            if(res[i]<=res[i-1])
                return false;
        }
        return true;
    }
};