class Solution {
public:
    int search(vector<int>& nums, int target) {
    int n=nums.size();
        int low=0, high=nums.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
                return mid;
//             check if left half is sorted
             if(nums[low]<=nums[mid])
             {
                 if(target>=nums[low] && target<=nums[mid])
                 {
                     high=mid-1;
                 }
                 else low=mid+1;
             }
            else
            {
//                 check if it lies in right side
                if(target>nums[mid] && target<=nums[high])
                {
                    low=mid+1;
                }
                else high=mid-1;
            }
        }
        return -1;
    }
};
