class Solution {
public:
    void reverseString(vector<char>& s) {
        char *l = &s[0];
        char *r = &s[s.size()-1];
        for(char i=0; i<s.size()/2; i++){
            char tmp = *l;
            *l=*r;
            *r=tmp;
            l++;
            r--;
        }
    }
};