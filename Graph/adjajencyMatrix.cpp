#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=1;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        // if directed edge between u and v and not between v and u so remove push_back(u)
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}