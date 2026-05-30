class Solution {
public:
    string longestPalindrome(string s) {
        string longest;
        int length=0;
        // if(ispalindrome(s))return s;
    
        for(int i=0; i<s.size(); i++){
            int left=0;
            int right=0;
            if(i<s.size()-1&&s[i]==s[i+1])right=1;
            if(i>0&&s[i]==s[i-1])left=1;
            // all same character case
            if(left==1&&right==1){
                while(i>=left+1&&s[i-left-1]==s[i]){
                    left++;
                    // cout<<i<<" left "<<left<<endl;
                }
                // cout<<endl;
                while(i<s.size()-right-1&&s[i]==s[i+right+1]){
                    right++;
                    // cout<<i<<" right "<<left<<endl;
                }
                if(left+right+1>length){
                    length=left+right+1;
                    longest=s.substr(i-left,left+right+1);
                }
                left=1;
                right=1;
            }

            while(i>=left&&i<s.size()-right&&s[i-left]==s[i+right]){
                // cout<<"left "<<left<<" right "<<right;
                if(left+right+1>length){
                    length=left+right+1;
                    longest=s.substr(i-left,left+right+1);
                }
                left++;
                right++;
            }

            
            // cout<<endl;
        }
        return longest;
    }bool ispalindrome(string &s){
        int left=0;
        int right=s.size()-1;
        while(left<right){
            if(s[left]!=s[right])return false;
            left++;
            right--;
        }
        return true;
    }
};
