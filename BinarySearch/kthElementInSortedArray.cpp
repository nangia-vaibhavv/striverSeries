class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        // brute
        
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back(arr1[i]);
        }
        for(int j=0;j<m;j++)
        {
            ans.push_back(arr2[j]);
        }
        sort(ans.begin(), ans.end());
        return ans[k-1];
    }
};