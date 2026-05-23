class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustcount(n+1,0);
        vector<int> doestrust(n+1,0);

        fill(trust, trustcount, doestrust);

        for(int i=1; i<doestrust.size(); i++){
            if(doestrust[i]==0&&trustcount[i]>=n-1)return i;
        }

        return -1;
        
    }
    void fill(const vector<vector<int>>& trust, vector<int> &trustcount, vector<int> &doestrust){
        for(vector<int> pr : trust){
            trustcount[pr[1]]++;
            doestrust[pr[0]]=1;
        }
    }
}; 