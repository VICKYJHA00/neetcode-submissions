class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (head == NULL || left == right) {
            return head;
        }

        ListNode* prev = NULL;
        ListNode* temp = head;

        // Move temp to the left position
        for (int i = 1; i < left; i++) {
            prev = temp;
            temp = temp->next;
        }

        // Node before the reversed section
        ListNode* before = prev;

        // Reverse the portion
        ListNode* curr = temp;
        ListNode* reversePrev = NULL;

        for (int i = 0; i < right - left + 1; i++) {
            ListNode* forward = curr->next;

            curr->next = reversePrev;
            reversePrev = curr;
            curr = forward;
        }

        // temp is now the last node of reversed section
        temp->next = curr;

        // If reversing starts from head
        if (before == NULL) {
            return reversePrev;
        }

        // Connect previous part to reversed part
        before->next = reversePrev;

        return head;
    }
};
