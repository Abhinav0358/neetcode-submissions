class Solution {
public:
    bool isInterleave(string s1, string s2, string s3){
        if(s3.size()!=s1.size()+s2.size())return false;
        return next(s1,s2,s3,0,0);
    }
    bool next(string &s1, string &s2, string &s3, int index1, int index2) {
        
        if(index1>=s1.size()&&index2>=s2.size()){
            if(s1==""&&s2!=s3)return false;
            if(s2==""&&s1!=s3)return false;           
            return true;
        }
        bool a=false;
        bool b=false;
        if(index1<s1.size()&&s3[index1+index2]==s1[index1])a=next(s1,s2,s3,index1+1,index2);
        if(index2<s2.size()&&s3[index1+index2]==s2[index2])b=next(s1,s2,s3,index1,index2+1);
        return a||b;
    }
};
