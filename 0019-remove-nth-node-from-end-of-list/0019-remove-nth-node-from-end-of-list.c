/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* temp = head, *t2 = head;
    while(n) {
        temp = temp->next;
        n--;
    }
    
    if(!temp) return head->next;

    while(temp->next) {
        t2 = t2->next;
        temp = temp->next;
    }
    t2->next = t2->next->next;
    return head;
}