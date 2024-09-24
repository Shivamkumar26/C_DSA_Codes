/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b % a, a);
} 
struct ListNode* insertGreatestCommonDivisors(struct ListNode* head){
    struct ListNode* temp = head;

    while(temp -> next) {
        struct ListNode* temp2 = temp->next;
        
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode -> val = gcd(temp->val, temp2->val);
        newNode -> next = temp2;

        temp->next = newNode;
        temp = temp->next->next;
    }

    return head;
}