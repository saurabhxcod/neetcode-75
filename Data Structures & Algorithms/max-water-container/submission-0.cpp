class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxWater=0;
        int left=0, right=heights.size()-1;
        while(left<right){
            int width=right-left;
            int water=min(heights[left],heights[right])*width;
            maxWater=max(maxWater,water);
            if(heights[left]<heights[right]) left++;
            else right--;
        }
        return maxWater;
    }
};
