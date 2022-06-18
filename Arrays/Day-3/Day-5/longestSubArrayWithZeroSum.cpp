class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n=nums.size();
        if(n<=1) return n;
        sort(nums.begin(), nums.end());
        int len=1, curr=1, prev=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=nums[i-1])
            {
                if(nums[i]==nums[i-1]+1)
                {
                    prev=nums[i];
                    curr++;
                }
                else 
                {
                    prev=nums[i];
                                        len=max(len,curr);

                    curr=1;
                }
            }
        }
        len=max(len,curr);
        return len;
    }
};