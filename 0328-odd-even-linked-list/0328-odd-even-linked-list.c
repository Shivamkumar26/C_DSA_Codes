/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if(!head) return head;

    struct ListNode* odd = (struct ListNode*)malloc(sizeof(struct ListNode));
    odd->val = -1;
    odd->next = NULL;
    struct ListNode* oddHead = odd;

    struct ListNode* even = (struct ListNode*)malloc(sizeof(struct ListNode));
    even->val = -1;
    even->next = NULL;
    struct ListNode* evenHead = even;

    struct ListNode* temp = head;


    int i = 1;
    while(temp) {
        if(i%2 == 1) { //odd
            odd->next = temp;
            odd = odd->next;
        }
        else {
            even->next = temp;
            even = even->next;
        }
        i++;
        temp = temp->next;
    }
    
    odd->next = evenHead->next;
    even->next = NULL;
    return oddHead->next;
}