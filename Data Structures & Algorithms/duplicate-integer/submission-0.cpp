class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> ump;
        for(int& it: nums) {
            ump[it]++;
            if(ump[it]==2) return 1;
        }
        return 0;
    }
};