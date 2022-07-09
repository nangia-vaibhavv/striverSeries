class Solution {
public:
    TreeNode *solve(vector<int>&preorder)
    {
        if(preorder.size()==0) return 0;
     TreeNode *root=new TreeNode(preorder[0]);

        if(preorder.size()==1)return root;
vector<int>left;
        vector<int>right;
        for(int i=1;i<preorder.size();i++)
        {
            if(preorder[i]<preorder[0])
            {
             left.push_back(preorder[i]) ;   
                }
             if(preorder[i]>preorder[0])
            {
           right.push_back(preorder[i]);            
             }
        }
        root->left=solve(left);
        root->right=solve(right);
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
//         prerder array given->first elemnt has to be root, 
//         all elements <root ->left subtree
//         aall elements >root->val lie on right subtree of given bst
        return solve(preorder);
    }
};