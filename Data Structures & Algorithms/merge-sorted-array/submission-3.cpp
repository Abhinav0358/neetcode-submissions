class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // merge the arrays

        // place the nums2 numbers in nums1
        // keep shuffling the nums2 numbers till it fits in the right place 

        // for(int i=0; i<n; i++){
        //     nums1[m+i]=nums2[i];
        //     int k=i;
        //     while(nums1[m+k-1]>nums1[m+k]&&(m+k-1)>=0){
        //         swap(nums1[m+k-1],nums1[m+k]);
        //         k--;
        //         if(m+k<=0)break;
        //     }
        // }

        // take the largest element place it at the end

        //  don't be afraid to overwrite 

        int* nl1 = &nums1[m-1];
        int* nl2 = &nums2[n-1];
        int* rp  = &nums1[m+n-1];
        int rppos=m+n-1;
        int nl1pos=m-1;
        int nl2pos=n-1;

        for(int i=0; i<m+n; i++){
            if(nl1pos<0){
                *rp=*nl2;
                nl2--;
                nl2pos--;
            }
            else if(nl2pos<0){
                *rp=*nl1;
                nl1--;
                nl1pos--;
            }
            else if(*nl1>*nl2&&nl1pos>=0){
                *rp=*nl1;
                nl1--;
                nl1pos--;
            }
            else if(*nl2>*nl1&&nl2pos>=0){
                *rp=*nl2;
                nl2--;
                nl2pos--;
            }else if(*nl2==*nl1&&nl2pos>=0){
                *rp=*nl2;
                rp--;
                *rp=*nl2;
                nl2--;
                nl1--;
                nl1pos--;
                nl2pos--;
            }

            rp--;
            rppos--;
        }


    }
};