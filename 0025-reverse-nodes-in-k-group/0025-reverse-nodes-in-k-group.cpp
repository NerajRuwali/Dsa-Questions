class Solution {
public:

    // Reverse first k nodes
    ListNode* reverse(ListNode* head, int k) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (k--) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        if (head == NULL)
            return NULL;

        // Check if k nodes exist
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (temp == NULL)
                return head;
            temp = temp->next;
        }

        // Reverse first k nodes
        ListNode* newHead = reverse(head, k);

        // Reverse remaining list
        head->next = reverseKGroup(temp, k);

        return newHead;
    }
};