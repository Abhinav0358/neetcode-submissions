class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //  obv way might be using n2, idts it'll give runtime 
        // long long int sum=0;
        // int count=0;
        // for(int i=0; i<nums.size(); i++){
        //     for(int j=i; j< nums.size(); j++){
        //         sum+=nums[j];
        //         if(sum==k)count++;
        //     }
        //     sum=0;
        // }
        // return count;

        // it doesnt 

        //  but how O(n)

        //  ok interesting 
        //  currsum - [ seensum in seensums] = k ? count++; O(n) (upto wherever you are in array)
        //  currsum - k = [seensum in seensums] O(1) hash lookup

        unordered_map<int,int> dayum;
        int sum=0;
        int count=0;
        dayum[sum]++; 
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(dayum.contains(sum-k))count+=dayum[sum-k];
            dayum[sum]++;
        }
        return count;

    }
};