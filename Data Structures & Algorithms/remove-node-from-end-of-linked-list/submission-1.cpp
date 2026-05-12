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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode* tmp = head;
        while(tmp){
            tmp=tmp->next;
            count++;
        }
        int index = count-n;
        cout<<"index "<<index<<endl;
        count=0;
        ListNode* tmp2 = head;
        if(index==0){
            head=head->next;
            return head;
        }
        while(tmp2){
            count++;
            cout<<"count "<<count<<"index "<<index<<endl;
            if(count==index){
                ListNode* tmp3 = (tmp2->next)->next;
                tmp2->next=tmp3;
                break;
            }
            tmp2=tmp2->next;
        }
        return head;
    }
};
