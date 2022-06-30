int Solution::findMedian(vector<vector<int> > &A) {
    int n=A.size();
    int m=A[0].size();
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            ans.push_back(A[i][j]);
        }
    }
    sort(ans.begin(), ans.end());
    int low=0, high=n*m-1;
    // return ans[high];
    int mid=(low+high)/2;
    return ans[mid];
}
