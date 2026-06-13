class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = k-1;

        for(int i=right+1; i<arr.size(); i++){
            if(abs(arr[i]-x)<abs(arr[left]-x)){
                left++;
                right++;
            }else if(abs(arr[i]-x)>abs(arr[left]-x))break;
            else continue;
        }

        vector<int> ans;
        for(int i=left; i<=right; i++)ans.push_back(arr[i]);

        return ans;

    }
};