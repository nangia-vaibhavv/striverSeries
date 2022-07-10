class Solution {
public:
    vector<int>res;
void inorderUtil(TreeNode*root)
{
    if(root==NULL) return;
    inorderUtil(root->left);
    res.push_back(root->val);
    inorderUtil(root->right);
}
    int kthSmallest(TreeNode* root, int k) {
        int ans=INT_MAX;
        inorderUtil(root);
//         for k smallest use max heap;
        priority_queue<int>pq;
        for(int i=0;i<res.size();i++)
        {
            pq.push(res[i]);
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        return pq.top();
    }
};