class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int counter=0;
        int maxOne=0;
        int it=0;
       for(int i=0;i<n;i++)
       {
          if(nums[i]==1)
          {
              counter++;
          }
           else
               counter=0;
           maxOne=max(maxOne,counter);
       }
        return maxOne;
    }
};