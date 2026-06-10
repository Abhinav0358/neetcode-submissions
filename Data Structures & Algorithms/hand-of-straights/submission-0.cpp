class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());
        vector<int> freq(hand[hand.size()-1]-hand[0]+1,0);
        for(int a: hand){
            freq[a-hand[0]]++;
        }
        int last0=0;
        while(last0<freq.size()){
            int tmp = freq[last0];
            if(tmp==0){
                last0++;
                continue;
            }
            for(int i=0; i<groupSize; i++){
                if(last0+i>=freq.size())return false;
                freq[last0+i]-=tmp;
                if(freq[last0+i]<0)return false;
            }
            last0++;
        }
        return true;
    }
};
