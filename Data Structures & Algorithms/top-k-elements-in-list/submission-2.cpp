class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> mp;
        for(int& it: nums) mp[it]++;

        int n = nums.size();
        vector<vector<int>> freq(n+1);
        for(auto& [val,f]: mp) {
            freq[f].push_back(val);
        }

        vector<int> res;
        for(int i=n; i>0; i--) {
            for(int& it: freq[i]) {
                if(k==0) return res;
                k--;
                res.push_back(it);
            }
        }

        return res;
    }
};