class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //  obv way might be using n2, idts it'll give runtime 
        long long int sum=0;
        int count=0;
        for(int i=0; i<nums.size(); i++){
            for(int j=i; j< nums.size(); j++){
                sum+=nums[j];
                if(sum==k)count++;
            }
            sum=0;
        }
        return count;
    }
};