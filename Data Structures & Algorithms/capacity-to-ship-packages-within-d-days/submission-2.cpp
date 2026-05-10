class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int max_val = 0; 
        
        for(int num : weights){
            sum += num;
            if(num > max_val) max_val = num;
        }
        
        int left = max_val;
        int right = sum;

        while(left < right){
            int mid = left + (right - left) / 2; 
            
            int current_days = countDays(weights, mid);
            
            if(current_days <= days) {
                right = mid; 
            } else {
                left = mid + 1; 
            }
        }
        
        return left; 
    }

    int countDays(vector<int>& weights, int maxweight){
        int sum = 0;
        int days = 1; 
        
        for(int weight : weights){
            if(sum + weight > maxweight){ 
                days++;       
                sum = weight; 
            } else {
                sum += weight; 
            }
        }
        return days;
    }
};