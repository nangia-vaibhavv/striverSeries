class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>mp;
        int n=nums.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>p;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
//         push this hash map to minHeap
        for(auto it:mp)
        {
            p.push(make_pair(it.second,it.first));
            if(p.size()>k)
            {
                p.pop();
            }
        }
        while(p.size()>0)
        {
            pair<int, int> top = p.top();
            ans.push_back(top.second);
            p.pop();
        }
        return ans;
    }
};