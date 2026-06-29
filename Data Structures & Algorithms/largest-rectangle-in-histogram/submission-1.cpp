class Solution {
public:
    int largestRectangleArea(vector<int>& heights){
        // vector<int> width(heights.size(),0);
        // width[0]=1;
        // for(int i=1; i<heights.size(); i++){
        //     if(heights[i-1]<heights[i])width[i]=1;
        //     else width[i]=width[i-1]+1;   
        // }
        // vector<int> rightwidth(heights.size(),0);
        // rightwidth[rightwidth.size()-1]=1;
        // for(int i=rightwidth.size()-2; i>=0;  i--){
        //     if(heights[i]>heights[i+1])rightwidth[i]=1;
        //     else rightwidth[i]=rightwidth[i+1]+1;   
        // }
        // for(int i=0; i<heights.size(); i++){
        //     width[i]+=rightwidth[i]-1;
        // }
        // for(int i=0; i<heights.size(); i++){
        //     cout<<width[i]<<" ";
        // }
        // cout<<endl;
        // int maxi=0;
        // for(int i=0; i<heights.size(); i++){
        //     maxi=max(maxi,heights[i]*width[i]);
        // }
        // return maxi;

        stack<int> st;
        int max_area = 0;
        int n = heights.size();
        
        for (int i = 0; i <= n; i++) {
            // Treat the index past the end of the array as having a height of 0
            int current_height = (i == n) ? 0 : heights[i];
            
            // While the current bar is shorter than the bar at the top of the stack,
            // the top bar has found its right boundary.
            while (!st.empty() && current_height < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                
                // If the stack is empty, this bar can extend all the way to index 0
                // Otherwise, its left boundary is limited by the new top of the stack
                int width = st.empty() ? i : (i - st.top() - 1);
                
                max_area = max(max_area, height * width);
            }
            
            st.push(i);
        }
        
        return max_area;

    }
};
