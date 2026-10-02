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
        if(head->next==nullptr) return nullptr;
        if(n==1){
            ListNode* p = head;
            while(p->next->next){
                p=p->next;
            }
            p->next = nullptr;
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i=0; i<n;i++){
            fast = fast->next;
        }
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }
        slow->val = slow->next->val;
        slow->next = slow->next->next;
        return head;
    }
};
