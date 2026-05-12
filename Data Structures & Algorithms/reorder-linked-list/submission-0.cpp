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
    void reorderList(ListNode* head) {
        int count=0;
        ListNode*tmp=head;
        while(tmp){
            count++;
            tmp=tmp->next;
        }
        cout<<"count "<<count<<endl;
        ListNode*right=head;
        for(int i=0; i<count/2; i++){
            right=right->next;
        }
        cout<<"right "<<right->val<<endl;
        ListNode*prev = right;
        right=right->next;
        prev->next=nullptr;
        while(right){
            ListNode* tmp=right->next;
            right->next=prev;
            prev=right;
            right=tmp;
        }
        cout<<"prev "<<prev->val<<endl;

        ListNode*left=head;
        cout<<left->val<<prev->val;
        while(prev!=left){
        ListNode*tmp1 =left->next;
        ListNode*tmp2 =prev->next;
        if(!tmp1||!tmp2)break;
        left->next=prev;
        prev->next=tmp1;
        left=tmp1;
        prev=tmp2;
        }

    }
};
