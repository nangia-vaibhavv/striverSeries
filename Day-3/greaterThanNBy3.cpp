class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int k=nums.size()/3;
        vector<int> vec;
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++) map[nums[i]]++;
        for(auto i: map) if(i.second>k) vec.push_back(i.first);
        return vec;
    }
};