class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int a = left;
        for(int i=left+1; i<=right; i++){
            a=a&i;
        }
        return a;
    }
};