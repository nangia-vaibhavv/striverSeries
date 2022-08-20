class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
//         adj list
        unordered_map<int,vector<int>>mp;
        for(auto x:edges)
        {
            vector<int>temp=x;
            int u=temp[0];
            int v=temp[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<int>visited(n+1,false);
        queue<int>q;
        q.push(source);
        while(q.empty())
        {
            int node=q.front();
            q.pop();
//             passing neighbours
           vector<int>temp=mp[node];
// for(auto x:mp[node])
// {
for(int i=0;i<temp.size();i++)
{
int vertex=temp[i];
if(visited[vertex]==false)
{
visited[vertex]=true;
q.push(vertex);
}
}
// }
}
return visited[destination];
}

};