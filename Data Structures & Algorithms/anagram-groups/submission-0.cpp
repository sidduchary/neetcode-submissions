class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;

        for(auto& str: strs) {
            vector<int> hash(26,0);
            for(auto& ch: str) {
                hash[ch-'a']++;
            }
            mp[hash].push_back(str);
        }
        vector<vector<string>> res;
        for(auto& [key,val]: mp) {
            res.push_back(val);
        }
        return res;
    }
};
