class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(true){
            int sum=0;
            while(n>0){
                sum+=pow(n%10,2);
                n/=10;
            }
            n=sum;
            if(n==1)return true;
            if(seen.find(n)!=seen.end())return false;
            seen.insert(n);
        }
        return false;
    }
};
