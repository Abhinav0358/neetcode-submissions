class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        for(int i=digits.size()-1; i>=0; i--){
            digits[i]+=carry;
            carry=0;
            if(digits[i]>=10){
                digits[i]=0;
                carry=1;
            }else return digits;
        }
        digits[0]=1;
        digits.push_back(0);
        return digits;

    }
};
