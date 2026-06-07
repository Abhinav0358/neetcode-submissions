class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int a = gcd(str1.size(),str2.size());
        string s;
        for(int i=0; i<a; i++){
            if(str1[i]!=str2[i])return "";
            s+=str1[i];
        }
        for(int i=a; i<str1.size(); i++){
            if(str1[i]!=s[i%s.size()])return "";
        }
        for(int i=a; i<str2.size(); i++){
            if(str2[i]!=s[i%s.size()])return "";
        }
        return s;
    }
    int gcd(int a, int b){
        for(int i=min(a,b); i>=1; i--){
            if(a%i==0&&b%i==0)return i;
        }
    }
};