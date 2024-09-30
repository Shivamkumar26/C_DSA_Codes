/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeNodes(struct ListNode* head) {
    if(!head || !head->next) return NULL;

    struct ListNode* res = head->next;
    struct ListNode* restemp = res;
    struct ListNode* temp = res;

    int val = 0;
    while(temp) {
        if(temp->val != 0) val += temp->val;
        else {
            restemp->val = val;
            val = 0;
            if(temp->next) restemp = restemp->next;
        }
        temp = temp->next;
    }
    restemp->next = NULL;
    return res;
}