class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> neighbours(n);
        unordered_set<int> visited;
        int count=0;
        for(auto & edge: edges){
            neighbours[edge[0]].push_back(edge[1]);
            neighbours[edge[1]].push_back(edge[0]);
        }
        if(neighbours.size()==0)return 0;

        for(int i=0; i<neighbours.size(); i++){
            if(visited.find(i)!=visited.end())continue;
            dfs(i,visited, neighbours);
            count++;
        }
        return count;
    }
    void dfs(int node, unordered_set<int> & visited, vector<vector<int>> &neighbours){
        if(visited.find(node)!=visited.end())return;
        visited.insert(node);
        for(int i=0; i<neighbours[node].size(); i++){
            dfs(neighbours[node][i],visited, neighbours);
        }        
    }
};
