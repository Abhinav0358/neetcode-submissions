class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> um;
        int left=0;
        int maxfreq=0;
        int maxlength=0;
        for(int i=0; i<s.size(); i++){
            um[s[i]]++;
            if(um[s[i]]>maxfreq)maxfreq=um[s[i]];
            while(i-left+1-maxfreq>k){
                um[s[left]]--;
                left++;
            }
            if(i-left+1>maxlength)maxlength=i-left+1;
        }
        return maxlength;
    }

};
