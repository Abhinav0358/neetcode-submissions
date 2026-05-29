class Solution {
public:
    int climbStairs(int n){
        // vector<int> memory(n);
        if(n==1)return 1;
        if(n==2)return 2;
        int prevprev=1;
        int prev=2;
        for(int i=n-3; i>=0; i--){
            int tmp = prev;
            prev=prev+prevprev;
            prevprev=tmp;
        }
        return prev;
        // if(n==1)return 1;
        // if(n==2)return 2;
        // return climbStairs(n-1)+climbStairs(n-2);
    }
};
