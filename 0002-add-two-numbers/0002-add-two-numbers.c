/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    int carry = 0;
    struct ListNode* l3 = (struct ListNode *)malloc(sizeof(struct ListNode));  

    l3 -> val = 0;
    l3 -> next = NULL;

    struct ListNode* res = l3;

    while(l1 && l2) {
        int sum = l1->val + l2->val + carry;
        if(sum > 9) {
            carry = sum / 10;
            sum = sum % 10;
        }
        else carry = 0;

        struct ListNode* temp = (struct ListNode *)malloc(sizeof(struct ListNode));  

        temp -> val = sum;
        temp -> next = NULL;
        l3->next = temp;
        l3 = l3 -> next;

        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1) {
        struct ListNode* temp = (struct ListNode *)malloc(sizeof(struct ListNode));  

        temp -> val = (l1->val + carry)%10;
        carry = (l1->val + carry) / 10;

        temp -> next = NULL;

        l3->next = temp;
        l3 = l3 -> next;
        l1 = l1->next;
    }
    while(l2) {
        struct ListNode* temp = (struct ListNode *)malloc(sizeof(struct ListNode));  

        temp -> val = (l2->val + carry)%10;
        carry = (l2->val + carry) / 10;

        temp -> next = NULL;
        
        l3->next = temp;
        l3 = l3 -> next;
        l2 = l2->next;
    }
    if(carry) {
        struct ListNode* temp = (struct ListNode *)malloc(sizeof(struct ListNode));  

        temp -> val = carry;
        temp ->next = NULL;
        l3 -> next = temp;
    }

    return res->next;
}