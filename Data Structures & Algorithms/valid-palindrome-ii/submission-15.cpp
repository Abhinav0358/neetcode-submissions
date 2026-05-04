class Solution {
public:
    bool validPalindrome(string s) {
        return isPalindrome(s,0,s.size()-1);
    }
    bool isPalindrome(string s, int i, int j){
       char left = i;
       char right= j;
       bool warn = false;
        while(right>left){
            cout<<s[left]<<s[right]<<endl;
            if(s[left]!=s[right]){
                if(warn) return false;
                warn = true;
                if(s[right-1]==s[left]&&s[left+1]==s[right]){
                    return isPalindrome(s,left,right-1)||isPalindrome(s,left-1,right);
                }else if(s[right-1]==s[left]){
                    right--;
                    continue;
                }else if(s[left+1]==s[right]){
                    left++;
                    continue;
                }else return false;
            }
            left++;
            right--;
        }
        return true;
    }
};