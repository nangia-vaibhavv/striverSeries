class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>ans;
        map<int,int>mp;
        // store pair in q
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            Node* node=it.first;
            int line=it.second;
            // mp[line]=node->data;
            if(!mp[line]){
                mp[line] = node->data;
            }
            
            if(node->left!=NULL)
            {
                q.push({node->left,line-1});
            }
            if(node->right!=NULL)
            {
                q.push({node->right, line+1});
            }
        }
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }

};
