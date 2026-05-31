class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            unordered_set<int> uset;
            for(int j=i+1; j<n; j++) {
                if(i==j) continue;
                int f = 0-(nums[i]+nums[j]);

                if(uset.count(f)) {
                    vector<int> t = {nums[i], nums[j], f};
                    sort(t.begin(), t.end());
                    ans.insert(t);
                }
                uset.insert(nums[j]);
            }
        }
        return vector<vector<int>> (ans.begin(), ans.end());
    }
};
