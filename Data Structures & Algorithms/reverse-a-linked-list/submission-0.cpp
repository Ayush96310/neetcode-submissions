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
    ListNode* reverseList(ListNode* head) {
        if (head==nullptr) return nullptr;
        ListNode* first = nullptr;
        ListNode* second = head;
        while(second!=nullptr){
            ListNode* temp = second;
            second = second->next;
            temp->next = first;
            first = temp;
        }
        return first;
    }
};
