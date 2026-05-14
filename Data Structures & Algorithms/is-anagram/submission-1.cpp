class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hash(26,0);
        for(auto& ch: s) hash[ch-'a']++;
        for(auto& ch: t) {
            hash[ch-'a']--;
            if(hash[ch-'a'] < 0) return 0;
        }
        for(auto& it: hash) {
            if(it > 0) return 0;
        }
        return 1;
    }
};
