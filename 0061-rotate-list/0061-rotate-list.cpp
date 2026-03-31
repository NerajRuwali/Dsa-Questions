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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL || head->next == NULL || k == 0)
            return head;

        ListNode* temp = head;
        int len = 1;

        // find length
        while(temp->next != NULL){
            temp = temp->next;
            len++;
        }

        // isse hm circular bana de rahe ha 
        temp->next = head;

    
        k = k % len;

        int steps = len - k;

        ListNode* newTail = head;

        for(int i = 1; i < steps; i++){
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};