class Solution {
public:
    int trap(vector<int>& height) {
        // Find the highest peak
        int maxheight=height[0];
        int maxindex=0;
        int water=0;
        for(int i=0; i<height.size(); i++){
            if(height[i]>=maxheight){
                maxheight=height[i];
                maxindex=i;
            }
        }

        // go from the left, get a higher peak, calculate backwards
        int start=0;
        // cout<<"calculating from start"<<endl;
        for(int i=0; i<=maxindex; i++){
            // cout<<"got "<<height[i]<<endl;
            if(height[i]>=height[start]){
            // cout<<"calculating water bw "<<start<<" & "<<i<<endl;
            calculatewater(height,start,i,water);
            // while(vec.size()>0&&height[i]>vec[vec.size()-1])vec.pop_back();
            start=i;
            // cout<<"start = "<<start<<endl;
            }
        }
        // go from the right, get a higher peak, calculate backwards
        int end=height.size()-1;
        // cout<<"calculating from end"<<endl;
        for(int i=height.size()-1; i>=maxindex; i--){
            // cout<<"got "<<height[i]<<endl;
            if(height[i]>=height[end]){
            // cout<<"calculating water bw "<<i<<" & "<<end<<endl;
            calculatewater(height,i,end,water);
            // while(vec.size()>0&&height[i]>vec[vec.size()-1])vec.pop_back();
            end=i;
            // cout<<"end = "<<end<<endl;
            }
        }
        return water;
    }
    void calculatewater(vector<int> &height, int start, int end, int &water){
        int a = min(height[start],height[end]);
        for(int i=start+1; i<end; i++){
            water+=max(0,a-height[i]); // dont know random max - to be careful
            // cout<<"water += "<<max(0,a-height[i])<<endl;
        }
    }
};
