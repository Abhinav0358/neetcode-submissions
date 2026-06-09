class Solution {
public:
    double myPow(double x, int n) {
        double num=1;
        if(n<0)x=1/x;
        for(int i=0; i<abs(n); i++){
            num*=x;
        }
        return num;
    }
};
