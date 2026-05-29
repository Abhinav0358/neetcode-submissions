class Solution {
public:
    int climbStairs(int n){
        vector<int> memory(n);
        if(n==1)return 1;
        if(n==2)return 2;
        memory[n-1]=1;
        memory[n-2]=2;
        for(int i=n-3; i>=0; i--){
            memory[i]=memory[i+1]+memory[i+2];
        }
        return memory[0];
        // if(n==1)return 1;
        // if(n==2)return 2;
        // return climbStairs(n-1)+climbStairs(n-2);
    }
};
