class StockSpanner {
public:
pair<int,int> stock;
stack<pair<int,int>> stck;

    StockSpanner() {
        
    }
    
    int next(int price) {
        int span=1;
        if(stck.empty()){
        stck.push({price,span});
        return span;
        }
        while(!stck.empty()&&stck.top().first<=price){
            span+=stck.top().second;
            stck.pop();
        }
        stck.push({price,span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */