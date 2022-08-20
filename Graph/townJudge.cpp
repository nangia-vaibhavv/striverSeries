class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // unordered_map<int,vector<int>>mp;
        // for(auto x:trust)
        // {
        //     vector<int>temp=x;
        //     int u=temp[0];
        //     int v=temp[1];
        //     mp[u].push_back(v);
        //     mp[v].push_back(u);
        // }
        vector<int>data(n+1,0);
        for(auto x:trust)
        {
            data[x[0]]--;
            data[x[1]]++;
        }
        for(int i=1;i<=n;i++)
        {
            int x=data[i];
            if(x==n-1)
                return i;
        }
        return -1;
    }
};