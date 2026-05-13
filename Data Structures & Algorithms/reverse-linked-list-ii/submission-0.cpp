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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev=nullptr;
        ListNode* prevlft=nullptr;
        ListNode* lft=nullptr;
        ListNode* rt=nullptr;
        ListNode* prevrt=nullptr;
        ListNode*ans=head;
        int count =1;
        while(head){
            ListNode *tmp=head->next;
            if(count==left-1)prevlft=head;
            if(count==left)lft=head;
            if(count==right){
                rt=head;
                prevrt=head->next;
            }
            if(count>left&&count<=right)head->next=prev;
            prev=head;
            head=tmp;
            count++;
        }
        if(prevlft)prevlft->next=rt;
        if(lft)lft->next=prevrt;
        if(left>1)return ans;
        else return rt;
    }
};