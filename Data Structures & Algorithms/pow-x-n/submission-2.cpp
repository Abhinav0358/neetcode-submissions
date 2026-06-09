class Solution {
public:
    double myPow(double x, int n) {
        //  O(n)
        // double num=1;
        // for(int i=0; i<abs(n); i++){
        //     num*=x;
        // }
        // return num;

        //  i wanna leave my intern ship
        // i wanna do something else, i think i should msg them 


        // O(log(n))
        if(n<0)x=1/x;
        n=abs(n);
        if(n==0)return 1;
        return power(x,n,1,x);
    }
    double power(double x, int n, int currcount, double originalx){
        if(currcount*2>n){
            for(int i=0; i<n-currcount; i++){
                x*=originalx;
            }
            return x;
        }
        return power(x*x,n,currcount*2,originalx);
    }
};
