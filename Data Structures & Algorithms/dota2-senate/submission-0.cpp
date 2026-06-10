class Solution {
public:
    string predictPartyVictory(string senate) {
        int rcount=0;
        int dcount=0;
        int rkilled=0;
        int dkilled=0;

        for(char c : senate){
            c=='R'? rcount++ : dcount++;
        }

        while(rcount>0&&dcount>0){
            for(char &c: senate){
                if(rcount==0||dcount==0)break;
                if(c=='X')continue;
                else if(c=='R'){
                    if(rkilled>0){
                        c='X';
                        rkilled--;
                        continue;
                    }
                    dcount--;
                    dkilled++;
                }
                else if(c=='D'){
                    if(dkilled>0){
                        c='X';
                        dkilled--;
                        continue;
                    }
                    rcount--;
                    rkilled++;
                }
            }
        } 
        return (dcount==0)?  "Radiant": "Dire";
    }
};