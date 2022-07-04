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
    int preIndex=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return createTree(preorder, inorder, 0, inorder.size()-1);
    }
    TreeNode * createTree(vector<int>&preorder, vector<int>&inorder, int start, int end)
    {
        if(start>end)return NULL;
        TreeNode* root=new TreeNode(preorder[preIndex++]);
//         search this root in inorder vectro
        int inIndex;
        for(int i=0;i<inorder.size();i++)
        {
            if(inorder[i]==root->val)
            {
                inIndex=i;
                break;
            }
        }
//         call for left and right
        root->left=createTree(preorder, inorder, start, inIndex-1);
        root->right=createTree(preorder, inorder, inIndex+1, end);
        return root;
    }
};