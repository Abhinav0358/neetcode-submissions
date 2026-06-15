class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        ans.resize(a.size()+1);
        if(a.size()>b.size()){
            b = string(a.size()-b.size(),'0')+=b;
            cout<<b<<endl;
            ans.resize(a.size()+1);
            cout<<ans.size()<<endl;
        }else if(a.size()<b.size()){
            a = string(b.size()-a.size(),'0')+=a;
            ans.resize(b.size()+1);
        }
            int carry=0;
            for(int i=a.size()-1; i>=0; i--){
                if(a[i]==b[i]){
                    if(carry==0){
                        if(a[i]=='1')carry=1;
                        ans[i+1]='0';
                        cout<<ans<<endl;
                        continue;
                    }   
                        carry=0;
                        if(a[i]=='1')carry=1;
                        ans[i+1]='1';
                        cout<<ans<<endl;
                        continue;             
                }
                if(carry==0)ans[i+1]='1';
                if(carry==1)ans[i+1]='0';
                cout<<ans<<endl;
            }
            if(carry==0){
                return ans.substr(1);
            }
            if(carry==1)ans[0]='1';
            return ans;
    }
};