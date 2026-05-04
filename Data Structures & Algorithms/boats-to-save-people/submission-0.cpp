class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end()); // nlogn

        int left =0;
        int right=people.size()-1;
        int btcount=0;
        while(right>left){
            if(people[right]+people[left]>limit){
                right--;
                btcount++;
            }else{
                left++;
                right--;
                btcount++;
            }

            if(right==left)btcount++;
        }
        return btcount;
    }
};