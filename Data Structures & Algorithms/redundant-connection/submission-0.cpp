class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parents(edges.size()+1);
        for(int i=0; i<parents.size();i++){
            parents[i]=i;
        }
        vector<int>ans;
        for(auto & edge: edges){
            if(!unioon(edge[0],edge[1],parents))ans=edge;
        }
        return ans;
    }
    int find(int a, vector<int> & parents ){
        if(parents[a]==a)return a;
        return find(parents[a],parents);
    }
    bool unioon(int a, int b, vector<int> & parents){
        if(find(a,parents)==find(b,parents))return false;
        parents[find(a,parents)]=find(b,parents);
        return true;
    }
};
