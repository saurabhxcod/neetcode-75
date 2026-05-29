class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        int count = 0;
        ListNode* temp = head;

        while(temp != NULL){
            count++;
            temp = temp->next;
        }

        int s = count - n;

        temp = dummy;

        while(s--){
            temp = temp->next;
        }

        ListNode* toDelete = temp->next;
        temp->next = temp->next->next;

        delete toDelete;

        return dummy->next;
    }
};