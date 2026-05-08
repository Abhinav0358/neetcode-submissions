class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids){
        vector<int> stck;
        for(int i=0; i<asteroids.size(); i++){
            bool brk=false;
            if(stck.empty()){
                stck.push_back(asteroids[i]);
                continue;                
            }
            // if(stck[stck.size()-1]*asteroids[i]>0){

            // }
            while(stck[stck.size()-1]>0&&asteroids[i]<0){
                if(abs(asteroids[i])>abs(stck[stck.size()-1])){
                    stck.pop_back();
                }else if(abs(asteroids[i])<abs(stck[stck.size()-1])){
                    brk=true;
                    break;
                }else if(abs(asteroids[i])==abs(stck[stck.size()-1])){
                    stck.pop_back();
                    brk=true;
                    break;
                }
            }
            if(brk) continue;
            stck.push_back(asteroids[i]);

        }
        return stck;
    }
};