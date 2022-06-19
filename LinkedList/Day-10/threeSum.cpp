class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<int>ans;
//         vector<vector<int>>finalAns; 
//         unordered_set<vector<vector<int>>>s;
//         int n=nums.size();
        
//         for(int i=0;i<n-2;i++)
//         {
//           for(int j=i+1;j<n-1;j++)
//           {
//               for(int k=j+1;k<n;k++)
//               {
//                  ans.clear();
//                   if(nums[i]+nums[j]+nums[k]==0)
//                   {
//                        ans.push_back(nums[i]);
//                       ans.push_back(nums[j]);
//                       ans.push_back(nums[k]);
//                       // finalAns.push_back(ans);
//                   }
//                    if (ans.size() != 0){
//                                  finalAns.push_back(ans);
// s.insert(finalAns);
//                    }
//               }
//           }
            
//         }
//         return s;
    sort(nums.begin(), nums.end());
    vector<vector<int>>ans;
        if(nums.size()==1 || nums.size()==0)
        {
            return ans;
        }
//     a
    for(int i=0;i<nums.size()-2;i++)
    {
         if(i==0 || (i>0 && nums[i]!=nums[i-1]))
         {
            int low=i+1, high=nums.size()-1,sum=0-nums[i];
             while(low<high)
             {
                 if(nums[low]+nums[high]==sum)
                 {
                     vector<int>temp;
                     temp.push_back(nums[i]);
                     temp.push_back(nums[low]);
                     temp.push_back(nums[high]);
                     ans.push_back(temp);
//                      logic such that after insertion it should low and high should move until they reaches to diff values other that that of already inserted
                     while(low<high && nums[low]==nums[low+1])low++;
                     while(low<high && nums[high]==nums[high-1])high--;
//                      else
                     low++;
                     high--;
                 }
                 else if(nums[low]+nums[high]<sum)low++;
                 else high--;
                 
             }
         }
    }
            return ans;
    }
};