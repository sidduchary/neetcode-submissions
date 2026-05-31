class Solution {
public:
    int trap(vector<int>& height) {
        int l = 1, r = height.size()-2;
        int mxl = height[0], mxr = height[r+1], water = 0;
        while(l<=r) {
            if(mxl <= mxr) {
                if(mxl > height[l]) water += (mxl-height[l]);
                mxl = max(mxl, height[l]);
                l++;
            }
            else {
                if(mxr > height[r]) water += (mxr-height[r]);
                mxr = max(mxr, height[r]);
                r--;
            }
            cout<< water<<",";
        }
        return water;
    }
};
