struct compare{
    bool operator()(const vector<int> &a, const vector<int> &b){
        return a[1]>b[1];
    }
};
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        //wrong solution 

        // priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, greater<pair<pair<int,int>,int>>> pq;
        // for(int i=0; i<tasks.size(); i++){
        //     pair<int,int> pr={tasks[i][0],tasks[i][1]};
        //     pq.push({pr,i});
        // }
        // vector<int> ans;
        // while(!pq.empty()){
        //     ans.push_back(pq.top().second);
        //     pq.pop();
        // }
        // return ans;


        // umm 
        // lets try to sort 
        int index=0;
        for(vector<int> &task: tasks){
            task.push_back(index);
            cout<<index<<endl;
            index++;
        }
        sort(tasks.begin(), tasks.end(), [](const vector<int> &a, const vector<int> &b){
            if (a[0] == b[0]){
                return a[1] < b[1]; 
            }   
            return a[0]<b[0];
        });

        vector<int> ans;
        priority_queue<vector<int>, vector<vector<int>> , compare > pq;

        pq.push(tasks[0]);
        int time_elapsed=pq.top()[0];
        int count=1;
        while(!pq.empty()){
            time_elapsed+=pq.top()[1];
            ans.push_back(pq.top()[2]);
            pq.pop();
            if(count<tasks.size()&&time_elapsed<tasks[count][0])time_elapsed=tasks[count][0];
            while(count<tasks.size()&&tasks[count][0]<=time_elapsed){
                pq.push(tasks[count]);
                count++;
            }  
        }

        return ans;
    }
};