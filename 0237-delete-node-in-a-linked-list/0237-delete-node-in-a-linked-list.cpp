class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;   // copy next node value
        node->next = node->next->next; // skip next node
    }
};