class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int>end;

        for(int i=0; i<s.size(); i++){
            char c=s[i];
            end[c]=i;
        }

        vector<int> partitions;
        int partitionend=end[s[0]];
        int lastsliced=-1;
        for(int i=0; i<s.size(); i++){
            char c=s[i];
            if(i==partitionend){
                partitions.push_back(i-lastsliced);
                partitionend=end[s[i+1]];
                lastsliced=i;
                // cout<<c<<i<<endl;
                continue;
            }
            
            
            partitionend=max(partitionend,end[c]);
        }

        return partitions;


    }
};
