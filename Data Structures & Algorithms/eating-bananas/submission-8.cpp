class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int sum=0;
        long long int max=0;
        for(int num : piles){
            if(num>max)max=num;
            sum+=num;
        }
        // hk>sum

        long long int left = sum/h;
        long long int right = max;
        if(left==0)return 1;
        if(calc_h(piles,left)==h)return left;

        while(left<right){
            long long int rate = (left + right)/2;
            double hours = calc_h(piles, rate);
            // cout<<rate<<" "<<hours<<" "<< h << endl;
            if(hours==h)right=rate;
            else if(hours>h)left = rate;
            else right = rate;
            if(right-left==1)return right;
        }
        return 1;
    }

    int calc_h(vector<int>& piles, int k){
        int h =0; 
        for(int num : piles){
            int a = num / k;
            if(num%k!=0)h+= (a+1);
            else h+=a;
            if(k==23)cout<<a+1;
        }
        return h;
    }
};
