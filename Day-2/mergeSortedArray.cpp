class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i,k;
        for(i=0;i<m;i++)
        {
            if(nums1[i]<nums2[0])
            {
                int temp=nums1[i];
                nums1[i]=nums2[0];
                nums2[0]=temp;
            }
            int first=nums2[0];
            for( k=0;k<n && nums2[k]<first;k++)
            {
                nums2[k-1]=nums2[k];
            }
            nums2[k-1]=first;
        }
    }
};