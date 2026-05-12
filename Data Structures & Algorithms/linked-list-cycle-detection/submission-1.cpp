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
    bool hasCycle(ListNode* head) {
        ListNode *headptr=head;

        ListNode*prev=nullptr;
        while(head){
            ListNode *tmp = head->next;
            if(tmp&&tmp==headptr)return true;
            head->next=prev;
            prev=head;
            head=tmp;
        }
        return false;
    }
};
