class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int>prereqcount(numCourses,0);

    // making the adjoint

    for(vector<int> &pear : prerequisites){
        adj[pear[1]].push_back(pear[0]);
        prereqcount[pear[0]]++;
    }

    queue<int> que;
    int count=0;
    for(int i=0; i<numCourses; i++){
        if(prereqcount[i]==0)que.push(i);
    }

    while(!que.empty()){
        int p = que.front();
        que.pop();
        count++;
        for(int j=0; j<adj[p].size(); j++){
            prereqcount[adj[p][j]]--;
            if(prereqcount[adj[p][j]]==0)que.push(adj[p][j]);
        }
    }
    return numCourses==count;
}
};
