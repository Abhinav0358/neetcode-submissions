class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0;
        int right=heights.size()-1;
        int maxvol=0;

        while(right>left){
            int vol = min(heights[right],heights[left])*(right-left);
            if(vol>maxvol)maxvol=vol;
            
            if(heights[left]<=heights[right])left++;
            else if(heights[left]>heights[right])right--;
        }
        return maxvol;
    }
};
