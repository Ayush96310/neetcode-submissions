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
    ListNode* reserveLL(ListNode* head){
        if(head==nullptr) return head;
        ListNode* pointer1 = nullptr;
        ListNode* pointer2 = head;
        while(pointer2!=nullptr){
            ListNode* temp = pointer2;
            pointer2 = temp->next;
            temp->next = pointer1;
            pointer1 = temp;
        }
        return pointer1;
    }
    void mergeAltLL(ListNode* list1, ListNode* list2){
        ListNode* pointer1 = list1;
        ListNode* pointer2 = list2;
        while(pointer1!=nullptr && pointer2!=nullptr){
            ListNode* temp = pointer1;
            pointer1 = pointer1->next;
            temp->next = pointer2;
            temp = pointer2;
            pointer2 = pointer2->next;
            temp->next = pointer1;
        }
    }
    void reorderList(ListNode* head) {
        if(head->next == nullptr) return;
        ListNode* slow  = head;
        ListNode* fast  = head->next;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = reserveLL(slow->next);
        slow->next = nullptr;
        mergeAltLL(head,head2);
    }
};
