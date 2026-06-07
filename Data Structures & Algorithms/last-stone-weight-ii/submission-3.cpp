class Solution {
public:
    // int lastStoneWeightII(vector<int>& stones) {
    //     int sum=0;
    //     int maxima=0;
    //     unordered_set<int>visited;
    //     for(int i=0; i<stones.size(); i++){
    //         sum+=stones[i];
    //         maxima=max(maxima,stones[i]);
    //     }
    //     int minima=maxima;
    //     takeornot(stones,0,0,sum,minima,visited);
    //     return minima;
    // }
    // void takeornot(vector<int>& stones, int index,int currsum, const int sum, int &minima, unordered_set<int> &visited){
    //     if(currsum>sum/2||index>=stones.size())return;
    //     if(visited.find(currsum)!=visited.end())return;
    //     // visited.insert(currsum);
    //     // visited.insert(sum-currsum);
    //     minima=min(abs(2*currsum-sum),minima);
    //     takeornot(stones,index+1,currsum+stones[index],sum,minima,visited);
    //     takeornot(stones,index+1,currsum,sum,minima,visited);
    // }

        int lastStoneWeightII(vector<int>& stones) {
            int sum=0;
            for(int stone: stones){
                sum+=stone;
            }    
            int target=sum/2;
            vector<bool> dp(target+1,false);
            dp[0]=true;
            for(int stone: stones){
                for(int i=target; i>=stone; i--){
                    if(dp[i-stone])dp[i]=true;
                }
            }
            int maxima=0;
            for(int i=dp.size()-1; i>=0; i--){
                if(dp[i]){
                    maxima=i;
                    break;
                }
            }
            return sum-2*maxima;
        }
};
