class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> inDegree(numCourses, 0);
    vector<vector<int>> adj(numCourses);
    
    for (auto& p : prerequisites) {
        adj[p[1]].push_back(p[0]); 
        inDegree[p[0]]++;          
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) q.push(i);
    }

    int count = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        count++; 
        for (int neighbor : adj[curr]) {
            inDegree[neighbor]--; 
            if (inDegree[neighbor] == 0) {
                q.push(neighbor); 
            }
        }
    }

    return count == numCourses;
}
};
