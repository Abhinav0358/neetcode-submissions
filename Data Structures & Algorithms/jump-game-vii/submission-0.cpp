class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        vector<bool> reachable(s.size(),false);
        reachable[0]=true;

        for(int i=1; i<s.size(); i++){
            if(s[i]=='1')continue;
            for(int j=i-1; j>=0; j--){
                if(reachable[j]){
                    if(i-j>=minJump&&i-j<=maxJump){
                        reachable[i]=true;
                        break;
                    }
                }
            }
        }
        return reachable[reachable.size()-1];
    }
};