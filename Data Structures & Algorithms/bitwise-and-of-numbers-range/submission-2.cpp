class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // int a = left;
        // for(int i=left+1; i<=right; i++){
        //     a=a&i;
        // }
        int count=0;
        while(left<right){
            left>>=1;
            right>>=1;
            count++;
        }
        return left<<count;

    }
};