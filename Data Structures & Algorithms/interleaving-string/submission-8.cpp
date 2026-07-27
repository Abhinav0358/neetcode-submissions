class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size()!=s1.size()+s2.size())return false;
        return isInterLeavethings(s1,s2,s3,0,0,0);
    }
    bool isInterLeavethings(string &s1, string &s2, string &s3, int left1, int left2, int index){
        if(left1+left2>=s3.size())return true;
        bool a=false;
        bool b=false;
        // cout<<s1[left1]<<" "<<s2[left2]<<" "<<index<<endl;
        if(left1<s1.size()&&s3[left1+left2]==s1[left1]) a = isInterLeavethings(s1,s2,s3,left1+1,left2, index+1);
        if(left2<s2.size()&&s3[left1+left2]==s2[left2]) b = isInterLeavethings(s1,s2,s3,left1,left2+1, index+1);
        
        return a||b;
    }
};