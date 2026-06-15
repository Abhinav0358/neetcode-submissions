class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0;
        for(int i=0; i<gas.size(); i++){
            gas[i]-=cost[i];
            total+=gas[i];
        }
        if(total<0)return -1;

        for(int i=0; i<gas.size(); i+=0){
            int a= loopthrough(gas,i);
            if(i==a%gas.size())return i;
            i=a;
        }
        return -1;
    }
    int loopthrough(vector<int>& gas, int index){
        int sum=0;
        for(int i=index; i<gas.size()+index; i++){
            sum+=gas[i%gas.size()];
            // cout<<sum<<" "<<index<<endl;
            if(sum<0)return (i+1);
        }
        return (gas.size()+index);
    }
};
