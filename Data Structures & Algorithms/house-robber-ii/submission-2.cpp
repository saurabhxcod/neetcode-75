class Solution {
public:
    int solve(vector<int>&nums,int l,int r){
        int p1=0,p2=0;
        for(int i=l;i<=r;i++){
            int pick=p2+nums[i];
            int skip=p1;
            int curr=max(pick,skip);
            p2=p1;
            p1=curr;
        }
        return p1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        return max(solve(nums,0,n-2),solve(nums,1,n-1));
    }
};
