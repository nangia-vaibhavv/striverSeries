vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    priority_queue<int,vector<int>,greater<int>>p;
    int n1=A.size(), n2=B.size();
    vector<int>ans;
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            p.push(A[i]+B[j]);
            if(p.size()>C)
            {
                p.pop();
            }
        }
    }
    while(p.size()>0)
    {
        ans.push_back(p.top());
        p.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
