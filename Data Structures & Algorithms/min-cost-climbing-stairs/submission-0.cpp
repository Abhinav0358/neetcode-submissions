class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // if(cost.size()==0)return 0;
        // if(cost.size()==1)return cost[0];
        // if(cost.size()==2)return min(cost[0],cost[1]);
        // if(cost.size()==3)return cost[0];
        int costpp=cost[0];
        int costp=cost[1];
        
        for(int i=2; i<cost.size(); i++){
            int tmp = costp;
            costp=min(cost[i]+costpp,cost[i]+costp);
            costpp=tmp;
        }
        return min(costp,costpp);
    }
};
