class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        if(t.length()>n) return "";
        unordered_map<char,int>mp;
        for(char ch:t) mp[ch]++;
        int countReq=t.length();
        int minLen=INT_MAX;
        int left=0;
        int start_i=0;
        for(int right=0;right<n;right++){
            char ch=s[right];
            if(mp[ch]>0){
                countReq--;  
            }
            mp[ch]--;
            while(countReq==0){
                if(right-left+1<minLen){
                    minLen=right-left+1;
                    start_i=left;
                }
                 mp[s[left]]++;
            if(mp[s[left]]>0){
                countReq++;
            }
            left++;
            }
           
        }
        if(minLen==INT_MAX){
            return "";
        }
        return s.substr(start_i,minLen);

    }
};
