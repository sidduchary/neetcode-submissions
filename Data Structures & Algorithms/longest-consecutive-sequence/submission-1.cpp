class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> ust(nums.begin(), nums.end());
        int n = nums.size();

        int mxlen = 0, len;
        for(int i=0; i<n; i++) {
            len = 1;
            if (!ust.count(nums[i]-1)) {
                int succ = nums[i]+1;
                while(ust.count(succ)) {
                    succ++;
                    len++;
                }
                mxlen = max(mxlen, len);
            }
        }
        return mxlen;
    }
};
