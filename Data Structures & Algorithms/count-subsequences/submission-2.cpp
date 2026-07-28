class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> vec(t.size(),vector<int>(s.size(),0));
        if(s[0]==t[0])vec[0][0]=1;
        for(int i=1; i<vec[0].size(); i++){
            if(s[i]==t[0])vec[0][i]=vec[0][i-1]+1;
            else vec[0][i]=vec[0][i-1];
        }
        for(int i=1; i<vec.size(); i++){
            for(int j=1; j<vec[0].size(); j++){
                if(s[j]==t[i])vec[i][j]=vec[i-1][j-1]+vec[i][j-1];
                else vec[i][j]=vec[i][j-1];
            }
        }
        for(int i=0; i<vec.size(); i++){
            for(int j=0; j<vec[0].size(); j++){
                cout<<vec[i][j]<<" ";
            }
            cout<<endl;
        }
        return vec[vec.size()-1][vec[0].size()-1];
    }
};
