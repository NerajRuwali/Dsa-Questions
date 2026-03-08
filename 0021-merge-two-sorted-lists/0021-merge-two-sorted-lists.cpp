class Solution { // solve using recursion
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
          // base case
        if(head1 == NULL || head2 == NULL){
            return head1 == NULL ? head2 : head1;
        }
          // case 1
        if(head1->val <= head2->val){
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        }
        else{ // case 2
            head2->next = mergeTwoLists(head2->next, head1);
            return head2;
        }
    }
};