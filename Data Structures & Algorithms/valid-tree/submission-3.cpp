class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> upcount(n,0);
        vector<vector<int>> downneigh(n);

        if(n!=edges.size()+1)return false;

        for(vector<int> edge : edges ){
            if(upcount[edge[1]]==0){
                upcount[edge[1]]++;
                downneigh[edge[0]].push_back(edge[1]);
            }else{
                if(upcount[edge[0]]>0){
                    // cout<<edge[0]<<edge[1]<<endl;
                    // cout<<upcount[edge[0]]<<endl;
                    return false;
                }
                upcount[edge[0]]++;
                downneigh[edge[1]].push_back(edge[0]);
            }
        }

        queue<int> que;
        for(int i=0; i<n; i++){
            if(upcount[i]==0)que.push(i);
        }
        int count=0;
        while(!que.empty()){
            int p = que.front();
            que.pop();
            cout<<p<<endl;
            count++;
            for(int i=0; i<downneigh[p].size(); i++){
                upcount[downneigh[p][i]]--;
                if(upcount[downneigh[p][i]]==0)que.push(downneigh[p][i]);
            }
        }
        return count==n;

        // return true;
    }
};
