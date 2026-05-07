class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> calc;
        for(string str : operations){
            if(str=="+"){
                int a = calc[calc.size()-1];
                int b = calc[calc.size()-2];
                calc.push_back(a+b);
            }else if(str=="D"){
                int a = calc[calc.size()-1];
                calc.push_back(a*2);
            }else if(str=="C"){
                calc.pop_back();
            }else calc.push_back(stoi(str));
        }
    int sum=0;
    for(int num: calc){
        sum+=num;
    }
    return sum;
    }
};