class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++) {
            int l=i+1, r=n-1;
            if(i>0 && nums[i] == nums[i-1]) continue;

            while(l<r) {

                int s = nums[l]+nums[r]+nums[i];
                if(s > 0) r--;
                if(s < 0) l++;
                if(s == 0) {
                    ans.push_back({nums[l], nums[r], nums[i]});
                    l++, r--;

                    while(l<r && nums[l]==nums[l-1]) l++;
                    while(l<r && nums[r]==nums[r+1]) r--;
                }
            }
        }
        return ans;
    }
};