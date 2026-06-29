class Solution {
public:
    string simplifyPath(string path) {
        // -> reduce immediately
        // jus /. remove .
        // /.. prev directory
        // /.... valid 

        // / count?

        string ans;
        for(char c : path){
            if(ans.size()>0&&c=='/'&&ans[ans.size()-1]=='/')continue;
            ans.push_back(c);
            if(c=='.'){
                continue;
            }
            if(ans.size()>2){
                if(ans[ans.size()-1]=='/'&&ans[ans.size()-2]=='.'&&ans[ans.size()-3]=='/'){
                    ans.pop_back();
                    ans.pop_back();
                    if(c!='/')ans.push_back(c);
                }
            }
            if(ans.size()>3){
                if(ans[ans.size()-1]=='/'&&ans[ans.size()-2]=='.'&&ans[ans.size()-3]=='.'&&ans[ans.size()-4]=='/'){
                    ans.pop_back();
                    ans.pop_back();
                    ans.pop_back();
                    ans.pop_back();
                    while(ans.size()>0&&ans[ans.size()-1]!='/')ans.pop_back();
                    if(ans.size()==0){
                        ans.push_back('/');
                        if(c!='/')ans.push_back(c);
                        continue;
                    }
                    if(c!='/')ans.push_back(c);
                }
            }
        }

            if(ans.size()>=2){
                if(ans[ans.size()-1]=='.'&&ans[ans.size()-2]=='/'){
                    ans.pop_back();
                }
            }
            if(ans.size()>=3){
                if(ans[ans.size()-1]=='.'&&ans[ans.size()-2]=='.'&&ans[ans.size()-3]=='/'){
                    ans.pop_back();
                    ans.pop_back();
                    ans.pop_back();
                    while(ans.size()>0&&ans[ans.size()-1]!='/')ans.pop_back();
                }
            }
        if(ans.size()==0)ans.push_back('/');
        while(ans.size()>1&&ans[ans.size()-1]=='/')ans.pop_back();
        return ans;
    }

};