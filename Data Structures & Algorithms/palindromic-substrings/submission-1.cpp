class Solution {
public:
    int expand(string &s,int left,int right){
        int count=0;
        while(left>=0 && right<s.size() && s[left]==s[right]){
            count++;
            left--;
            right++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int total=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            total+=expand(s,i,i);
            total+=expand(s,i,i+1);
        }
        return total;
    }
};
