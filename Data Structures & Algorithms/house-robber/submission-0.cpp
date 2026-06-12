class Solution {
public:
    int rob(vector<int>& nums) {
        int p1=0,p2=0;
        for(int val:nums){
            int pick=val+p2;
            int skip=p1;
            int curr=max(pick,skip);
            p2=p1;
            p1=curr;
        }
        return p1;
    }
};
