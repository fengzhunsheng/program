/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *l3;
    l3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l3->val = -1;
    l3->next = NULL;
    
    struct ListNode *tmp3 = l3;
    struct ListNode *tmp2 = l2;
    struct ListNode *tmp1 = l1;
    int sum = 0;

    while(tmp1 != NULL  || tmp2 != NULL || sum != 0)
    {
        struct ListNode *pNode;
        pNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        pNode->next = NULL;

        sum += (tmp1 ? tmp1->val : 0) + (tmp2 ? tmp2->val : 0);
        pNode->val = sum % 10;
        sum /= 10;

        tmp3->next = pNode;
        tmp3 = pNode;
        
        tmp1 =  tmp1 ? tmp1->next : NULL;
        tmp2 =  tmp2 ? tmp2->next : NULL;
    }
 
    return l3->next;
}