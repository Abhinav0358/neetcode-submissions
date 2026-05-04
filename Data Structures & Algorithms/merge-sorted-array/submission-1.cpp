class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // merge the arrays

        // place the nums2 numbers in nums1
        // keep shuffling the nums2 numbers till it fits in the right place 

        for(int i=0; i<n; i++){
            nums1[m+i]=nums2[i];
            int k=i;
            while(nums1[m+k-1]>nums1[m+k]&&(m+k-1)>=0){
                swap(nums1[m+k-1],nums1[m+k]);
                k--;
                if(m+k<=0)break;
            }
        }


    }
};