class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
//         brute force
       // vector<int>ans;
       //  int n=nums.size();
       //  for(int i=0;i<n;i++)
       //  {
       //      for(int j=i+1;j<n;j++)
       //      {
       //          if(nums[i]+nums[j]==target)
       //          {
       //              ans.push_back(i);
       //              ans.push_back(j);
       //          }
       //      }
       //  }
       //  return ans;
        
        
//         effi
       //  vector<int>ans;
       //   map<int,int>mp;
       //  int remainValue=0;
       //  for(int i=0;i<nums.size();i++)
       //  {       remainValue=target-nums[i];
       // if(mp.find(remainValue)!=mp.end())
       // {
       //     ans.push_back(i);
       //     ans.push_back(mp[remainValue]);
       // }
       //   mp[nums[i]]=i;
       //  }
       //  return ans;
        vector<int>ans;
        map<int,int>mp;
        int remainValue=0;
        for(int i=0;i<nums.size();i++)
        {
            remainValue=target-nums[i];
//             if found inside map
            if(mp.find(remainValue)!=mp.end())
            {
                ans.push_back(i);
                ans.push_back(mp[remainValue]);
            }
                                 mp[nums[i]]=i;
        }
                                 return ans;
    }
};