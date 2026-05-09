class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> pairvec(position.size());
        stack<double> times;
        for(int i=0; i<position.size(); i++){
            pairvec[i].first=position[i];
            pairvec[i].second=speed[i];
        }
        sort(pairvec.begin(),pairvec.end());
        for(auto &pr : pairvec){
            double time = (double)(target - pr.first)/pr.second;
            while(!times.empty()&&times.top()<=time){
                times.pop();
            }
            times.push(time);
            cout<<time<<endl;
        }

        int count=0;
        while(!times.empty()){
            times.pop();
            count++;
        }
        return count;

    }
};
