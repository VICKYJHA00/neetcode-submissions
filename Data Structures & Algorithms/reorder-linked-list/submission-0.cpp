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
    ListNode* reverse(ListNode* head){
        ListNode* forward = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode dummy(0,head);
        auto slow = &dummy;
        auto fast = &dummy;
        while(fast && fast->next ){ // for find the mid
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* second = reverse(slow->next);
        slow->next = NULL;  
        ListNode* first = head;

        while(second){
            ListNode* firstnext = first->next;
            ListNode* secondnext = second->next;

            first->next = second;
            second->next = firstnext;

            first = firstnext;
            second = secondnext;
        }

    }
};
