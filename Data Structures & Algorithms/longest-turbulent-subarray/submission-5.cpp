class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int start=0;
        int globalmax=0;
        if(arr.size()==1)return 1;
        if(arr.size()==2){
            if(arr[0]==arr[1])return 1;
            return 2;
        }
        int globalind;
        for(int i=1; i<arr.size()-1; i++){
            if(arr[i-1]<=arr[i]&&arr[i]<=arr[i+1]||arr[i-1]>=arr[i]&&arr[i]>=arr[i+1]){
                start=i;
                cout<<arr[start];
            }
            if(i+2-start>=globalmax)globalind=i;
            globalmax=max(globalmax,i+2-start);
        }
        if(globalmax==2){
            if(arr[globalind-1]==arr[globalind]&&arr[globalind]==arr[globalind+1]){
                globalmax=1;
            }
        }
        
        return globalmax;
    }
};