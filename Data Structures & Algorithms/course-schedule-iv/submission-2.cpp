class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> children(numCourses);
        vector<vector<bool>> ansgrid(numCourses, vector<bool>(numCourses, false));
        vector<bool> answer;
        vector<bool> visited(numCourses,false);
        for(auto& prereq : prerequisites){
            children[prereq[0]].push_back(prereq[1]);
        }

        for(int i=0; i<numCourses; i++){
            dfs(i,i,children,ansgrid,visited);
            visited[i]=true;
        }

        for(auto & query: queries){
            answer.push_back(ansgrid[query[0]][query[1]]);
        }
        return answer;
    }
    void dfs(int originalindex, int index, vector<vector<int>> &children , vector<vector<bool>> &ansgrid, vector<bool> &visited){
        if(visited[index]){
            for(int i=0; i<ansgrid[originalindex].size(); i++){
                if(ansgrid[index][i])ansgrid[originalindex][i]=true;
            }
            return;
        }
        for(int i=0; i<children[index].size(); i++){
             ansgrid[originalindex][children[index][i]]=true;
             dfs(originalindex,children[index][i],children, ansgrid,visited);
        }

    }
};