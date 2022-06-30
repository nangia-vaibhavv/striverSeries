class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
//         using map or O(n) approach
        
        // int n=nums.size();
        // map<int,int>mp;
        // for(int i=0;i<n;i++)
        // {
        //     mp[nums[i]]++;
        // }
        // for(auto it:mp)
        // {
        //     if(it.second==1)
        //     {
        //         return it.first;
        //     }
        // }
        // return 0;
       
//         O(logn)
        int n=nums.size();
        int low=0, high=n-2;
        while(low<=high)
        {
           int mid=(low+high)/2;
            if(nums[mid]==nums[mid^1])
            {
                low=mid+1;
            }
            else high=mid-1;
        }  
        return nums[low];
    }
};