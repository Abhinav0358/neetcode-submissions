class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(),0);
        stack<int> warmindices;
        for(int i = temperatures.size()-1; i>=0; i--){
            while(!warmindices.empty()&&temperatures[warmindices.top()]<=temperatures[i]){
                warmindices.pop();
            }
            if(!warmindices.empty()){
            result[i]=warmindices.top()-i;
            }else result[i]=0;
            warmindices.push(i);
        }
        return result;
    }
};
