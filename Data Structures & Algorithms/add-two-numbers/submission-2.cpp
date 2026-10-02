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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int first = 0;
        int second = 0;
        int carry = 0;
        int ones = 0;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        while(p1 && p2){
            first = p1->val;
            second = p2->val;
            ones = (first+second+carry)%10;
            carry = (first+second+carry)/10;
            ListNode* temp = new ListNode(ones);
            p->next = temp;
            p = temp;
            p1 = p1->next;
            p2 = p2->next;
        }
        while(p1){
            ListNode* temp = new ListNode((carry+p1->val)%10);
            carry = (carry+p1->val)/10;
            p->next = temp;
            p = temp;
            p1 = p1->next;
        }
        while(p2){
            ListNode* temp = new ListNode((carry+p2->val)%10);
            carry = (carry+p2->val)/10;
            p->next = temp;
            p = temp;
            p2 = p2->next;
        }
        if(carry){
            ListNode* temp = new ListNode(carry);
            p->next = temp;
        }
        return dummy->next;
    }
};
