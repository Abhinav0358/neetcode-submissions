class Solution {
public:
    int mySqrt(int x) {
        long long int left = 1;
        long long int right = x;
        if(left*left==x)return left;   
        while(left<right){
            long long int mid = (left + right)/2;
            if(mid*mid==x)return mid;
            else if(mid*mid<x)left = mid;
            else right = mid;

            if(right-left==1)return left;
        }
    }
};