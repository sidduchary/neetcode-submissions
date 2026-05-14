class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(auto& str: strs) {
            string hash(26,0);
            for(auto& ch: str) {
                hash[ch-'a']++;
            }
            mp[hash].push_back(str);
        }
        vector<vector<string>> res(mp.size());
        int i = 0;
        for(auto& [key,val]: mp) {
            res[i++] = val;
        }
        return res;
    }
};
