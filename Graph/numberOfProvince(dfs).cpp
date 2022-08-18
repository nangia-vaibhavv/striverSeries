class Solution {
public:
    void dfs(int node, vector<int>& vis,vector<int> adjList[])
    {
        vis[node]=1;
        for(auto it:adjList[node])
        {
            if(!vis[it])
            {
                vis[it]=1;
                dfs(it,vis,adjList);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        vector<int>vis(v,0);
        vector<int>adjList[v];
//         convert matrix to list
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int count=0;
        for(int i=0;i<v;i++)
        {
            if(!vis[i])
            {
                count++;
                dfs(i,vis,adjList);
            }
        }
        return count;
    }
};