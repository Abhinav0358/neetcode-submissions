class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        int maxfreq=0;
        int charswithmaxfreq=0;
        for(char c : tasks){
            mp[c]++;
            if(mp[c]>maxfreq){
                maxfreq=mp[c];
                charswithmaxfreq=0;
            }
            if(mp[c]==maxfreq)charswithmaxfreq++;
        }
        int ans = (maxfreq-1)*(n+1)+charswithmaxfreq;
        if(tasks.size()>ans)ans=tasks.size();
        return ans;
    }
};
