/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if(!head || !head -> next) return head;

    struct ListNode* temp = head;
    struct ListNode* prev = (struct ListNode*)malloc(sizeof(struct ListNode));
    prev->val = -1;
    prev->next = head;
    struct ListNode* newHead = prev;

    while(temp && temp->next) {
        struct ListNode* a = temp; // 1
        struct ListNode* b = temp -> next; // 2

        if(newHead == head) newHead = b;

        a->next = b->next; // 2 p1 3 
        b->next = a; 
        prev->next = b;
        prev = a;

        temp = temp->next;
    }
    return newHead->next;
}