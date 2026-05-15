class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int zeros = 0, mul = 1, idx = -1;
        for(int i=0; i < n; i++) {
            if(nums[i] == 0) {
                zeros++;
                idx = i;
            }
            else mul *= nums[i];
        }

        vector<int> res(n,0);
        if(zeros > 1) return res;
        else if(zeros == 1) {
            res[idx] = mul;
            return res;
        }

        for(int i=0; i<n; i++) {
            res[i] = mul/nums[i];
        }
        return res;
    }
};
