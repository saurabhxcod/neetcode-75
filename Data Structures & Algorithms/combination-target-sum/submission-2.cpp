class Solution {
public:
    vector<vector<int>>ans;
    vector<int>curr;
    void backtrack(vector<int>& nums,int start, int target){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        for(int i=start;i<nums.size();i++){
            if(nums[i]>target) break;
            curr.push_back(nums[i]);
            backtrack(nums,i,target-nums[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        backtrack(nums,0,target);
        return ans;
    }
};
