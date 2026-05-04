class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()==0)return true;
        char *l =&s[0];
        char *r =&s[s.size()-1];
        while(l!=r){
            *l=tolower(*l);
            *r=tolower(*r);
            bool end=false;
            while(!(*l>='0'&&*l<='9'||*l>='a'&&*l<='z')){
                    l++;
                    *l=tolower(*l);
                    if(l==r){
                        end=true;
                        break;
                    }
                    if(abs(l-r)==1&&*r==*l){
                        end=true;
                        break;
                    }
                }
            while(!(*r>='0'&&*r<='9'||*r>='a'&&*r<='z')){
                r--;
                *r=tolower(*r);
                if(l==r){
                    end=true;
                    break;
                }
                    if(abs(l-r)==1&&*r==*l){
                        end=true;
                        break;
                    }
            }
            cout<<*l<<" "<<*r<<"     ";
            if(end)break;
            if(*l!=*r){
                return false;
            }
            if(abs(l-r)==1&&*r==*l){
                end=true;
                break;
            }
            l++;
            r--;
        }

        return true;
        
    }
};
