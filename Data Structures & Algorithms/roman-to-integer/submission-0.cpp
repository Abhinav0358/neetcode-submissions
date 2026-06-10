class Solution {
public:
    int romanToInt(string s) {
    unordered_map<char,int> value;
    value['I']=1;
    value['V']=5;
    value['X']=10;
    value['L']=50;
    value['C']=100;
    value['D']=500;
    value['M']=1000;
        int sum=0;
        sum+=value[s[0]];
        for(int i=1; i<s.size(); i++){
            if(s[i-1]=='I'&&s[i]=='V'||s[i-1]=='I'&&s[i]=='X'){
                sum-=2;
            }
            if(s[i-1]=='X'&&s[i]=='L'||s[i-1]=='X'&&s[i]=='C'){
                sum-=20;
            }
            if(s[i-1]=='C'&&s[i]=='D'||s[i-1]=='C'&&s[i]=='M'){
                sum-=200;
            }
            sum+=value[s[i]];
        }
        return sum;
    }
};