void leftViewUtil(Node *root, int level, vector<int>&ans)
{
    if(root==NULL) return;
    if(level==ans.size())
    {
        ans.push_back(root->data);
        // maxLevel=level;
    }
    if(root->left)
    {
        leftViewUtil(root->left,level+1,ans);
    }
    if(root->right)
    {
        leftViewUtil(root->right,level+1,ans);
    }
}
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>ans;
   leftViewUtil(root,0,ans);
   return ans;
}