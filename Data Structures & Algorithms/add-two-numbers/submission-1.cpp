/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
// IMP STUFF:
// IF YOU MAKE A NEW LISTNODE INSIDE THE FUNCTION AND POINT SOMETHING TO IT
// AT THE END OF THE FUNCTION THE MEMORY IS GOING TO BE DELETED
// IF INSTEAD OF NEW LISTNODE, A LISTNODE WAS CREATED WITHIN THE FUNCTION
// THEN EVEN IF EVERYTHING WAS CORRECT AT THE END IT WOULD GIVE WEIRD RESULTS CAUSE
// THE MEMORY OF THE LAST NUMBER DOESN'T EXIST
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry=false;
        ListNode* ans=l1;
        while(l1||l2){

            // when l2 is not there
            if(!l2){
                cout<<"case when only l2 is not there"<<endl;
                int sum=l1->val;
                if(carry)sum+=1;
                if(sum>=10){
                    sum=sum%10;
                    carry=true;
                }else carry=false;
                l1->val=sum;
                cout<<"l1 val "<<l1->val<<endl;

                // if l1 is also ending and theres still carry
                if(!l1->next&&carry){
                    cout<<" l1 is also ending and carry"<<endl;
                    l1->next=new ListNode(1);
                    break;                    
                }

                l1=l1->next;
                continue;            
            }

            // when both are there
                cout<<"case when both are there "<<endl;
                int sum=l1->val+l2->val;
                if(carry)sum+=1;
                if(sum>=10){
                    sum=sum%10;
                    carry=true;
                }else carry=false;
                l1->val=sum;

                cout<<"sum "<<sum<<endl;
            // check if both are not going to be there and theres still carry left 
            if(!l1->next&&!l2->next){
                cout<<"entered end game"<<endl;
                if(carry){
                    l1->next=new ListNode(1);
                    break;
                }
            }
            // cout<<"shouldn't have to do anything with this"<<endl;
            // if l1 is not there then just point it to l2 and make l2 null
            if(!l1->next){
                cout<<"l2 is dead"<<endl;
                l1->next=l2->next;
                l2=nullptr;
                l1=l1->next;
                continue;
            }
            l1=l1->next;
            l2=l2->next;


        }
        return ans;
    }
};
