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
    int C = 0;
    while(tmp1 != NULL  && tmp2 != NULL)
    {
        struct ListNode *pNode;
        pNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        pNode->next = NULL;
        int val;    
        val = tmp1->val + tmp2->val + C;
        if(val >= 10)
        {
            C = 1;
            val %= 10;
            pNode->val = val;
        }
        else
        {
            C = 0;
            pNode->val = val;
        }

        if(tmp3->val == -1)
        {
            tmp3->val = pNode->val;
        }
        else
        {
            tmp3->next = pNode;
            tmp3 = pNode;
        }

        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    while(tmp2 != NULL)
    {
        struct ListNode *pNode;
        pNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        pNode->next = NULL;

        int val;    
        val = tmp2->val + C;
        if(val >= 10)
        {
            C = 1;
            val %= 10;
            pNode->val = val;
        }
        else
        {
            C = 0;
            pNode->val = val;
        }

        tmp3->next = pNode;
        tmp3 = pNode;
        tmp2 = tmp2->next;
    }
    while(tmp1 != NULL)
    {
        struct ListNode *pNode;
        pNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        pNode->next = NULL;

        int val;    
        val = tmp1->val + C;
        if(val >= 10)
        {
            C = 1;
            val %= 10;
            pNode->val = val;
        }
        else
        {
            C = 0;
            pNode->val = val;
        }

        tmp3->next = pNode;
        tmp3 = pNode;
        tmp1 = tmp1->next;
    }
    if(C == 1)
    {
        struct ListNode *pNode;
        pNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        pNode->next = NULL;
        pNode->val = C;

        tmp3->next = pNode;
        tmp3 = pNode;
    }
 
    return l3;
}