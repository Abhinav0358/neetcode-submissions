class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;
        
        while (low <= high) {
            int i = low + (high - low) / 2;
            int j = (m + n + 1) / 2 - i;
            
            // Edge cases: handling empty partitions with INT_MIN / INT_MAX
            int maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int minRight1 = (i == m) ? INT_MAX : nums1[i];
            
            int maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int minRight2 = (j == n) ? INT_MAX : nums2[j];
            
            // Correct partition found
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // If total number of elements is odd
                if ((m + n) % 2 != 0) {
                    return std::max(maxLeft1, maxLeft2);
                }
                // If total number of elements is even
                return (std::max(maxLeft1, maxLeft2) + std::min(minRight1, minRight2)) / 2.0;
            }
            // Too far right in nums1, move left
            else if (maxLeft1 > minRight2) {
                high = i - 1;
            }
            // Too far left in nums1, move right
            else {
                low = i + 1;
            }
        }
        
        return 0.0; // Fallback
    }
};