class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1vec(26,0);
        vector<int> window(26,0);
        int left=0;
        for(int i=0; i<s1.size(); i++){
            s1vec[s1[i]-'a']++;
        }
        for(int i=0; i<s2.size(); i++){
            if(i<s1.size()){
                window[s2[i]-'a']++;
                if(window==s1vec)return true;
                continue;
            }
            window[s2[left]-'a']--;
            left++;
            window[s2[i]-'a']++;
            if(window==s1vec)return true;
        }
        return false;
    }
};
