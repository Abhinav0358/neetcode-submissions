class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minptr=0;
        int maxptr=0;
        int trptr=0;
        int maxcount=0;
        while(trptr<prices.size()){
            if(prices[trptr]<prices[minptr]){
                minptr=trptr;
                maxptr=trptr;
            }
            if(prices[trptr]>prices[maxptr])maxptr=trptr;
            if(prices[maxptr]-prices[minptr]>maxcount)maxcount=prices[maxptr]-prices[minptr];
            trptr++; 
        }
        return maxcount;
    }
};
