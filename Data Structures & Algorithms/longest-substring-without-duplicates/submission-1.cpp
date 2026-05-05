class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> us;
        int left=0;
        int right=0;
        int maxlength=0;

        while(right<s.size()){
            while(us.find(s[right])!=us.end()){
                us.erase(s[left]);
                left++;
            }
            us.insert(s[right]);
            if(right-left+1>maxlength)maxlength=right-left+1;
            right++;
        }
        return maxlength;
    }
};
