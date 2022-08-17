class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()==1)
        {
            return nums;
        }
        sort(nums.begin(),nums.end());
        
        vector<int>dp(nums.size(),0);
        vector<int>index(nums.size());
        
        dp[0]=1;
        index[0]=-1;
        
        int temp_val=INT_MIN;
        int temp_idx=-1;
        
        for(int i=1;i<nums.size();i++)
        {
            int val=nums[i];
            int temp=0;
            int idx=-1;
            
            for(int j=i-1;j>=0;j--)
            {
               if((nums[i]%nums[j])==0)
               {
                   if(dp[j]>temp)
                   {
                       temp=dp[j];
                       idx=j;
                   }
               }
            }
            dp[i]=1+temp;
            index[i]=idx;
            
            if(temp_val<dp[i])
            {
                temp_val=dp[i];
                temp_idx=i;
            }
        }
        vector<int>v;
        v.push_back(nums[temp_idx]);
        while(temp_idx!=-1)
        {
            temp_idx=index[temp_idx];
            if(temp_idx==-1)
            {
                break;
            }
            v.push_back(nums[temp_idx]);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};