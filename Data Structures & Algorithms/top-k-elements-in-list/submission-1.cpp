class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> hash(2000+1,0);
        for(int& it: nums) hash[it+1000]++;

        map<int,vector<int>, greater<int>> mp;
        for(int i=2000; i>=0; i--) {
            if(hash[i] > 0) {
                mp[hash[i]].push_back(i-1000);
            }
        }

        int i=0;
        vector<int> res(k);
        for(auto& [key,val]: mp) {
            for(int& it: val) {
                k--;
                res[i++] = it;
                if(k==0) return res;
            }
        }

        return res;
    }
};