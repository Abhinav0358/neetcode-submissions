#include <string>

class Solution {
public:
    int numDecodings(std::string s) {
        int count=1;
        int paired=0;
        int unpaired=1;
        if(s[0]=='0')return 0;
        for(int i=1; i<s.size(); i++){
            // ye to hona hi hai unless u have 0 
            int tmp=unpaired;

            if(s[i]!='0'){
                unpaired+=paired;
            }else unpaired=0;
            


            // ye hoga if u have a valid pair
            int a = s[i]-'0';
            int b = s[i-1]-'0';
            int c=b*10+a;
            if(c>=10&&c<=26){
                paired=tmp;
            }else paired=0;
        }
        return (paired+unpaired);
    }
    // void countupdate(string &s, int index, int &count){
    //     if(index>=s.size()){
    //         count++;
    //         return;
    //         }
    //     if(s[index]!='0')countupdate(s,index+1,count);
    //     if(index+1<s.size()){
    //         int a = s[index]-'0';
    //         int b = s[index+1]-'0';
    //         int c=a*10+b;
    //         if(c>=10&&c<=26)countupdate(s,index+2,count);
    //     }
    // }
};