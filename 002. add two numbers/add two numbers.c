// https://leetcode.com/problems/add-two-numbers/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *newListNode(int x){
    struct ListNode *node=calloc(1, sizeof(struct ListNode));
    node->val=x;
    return node;
}

//approccio con carry
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head=newListNode(0);
    struct ListNode *p=l1, *q=l2, *current=head;
    int sum=0, carry=0;

    while(p!=NULL || q!=NULL){
        sum=carry+(p==NULL?0:p->val)+(q==NULL?0:q->val);
        carry=sum/10;
        current->next=newListNode(sum%10);
        current=current->next;
        p=p==NULL?p:p->next;
        q=q==NULL?q:q->next;
    }
    current->next=carry>0?newListNode(carry):NULL;
    return head->next;
}

/*
//approccio ricorsivo con somma, non efficente, non passa la maggior parte dei test
void intToListR(struct ListNode *node, long x){
    if(x<10){
        node->val=x;
        return;
    }
    node->val=x%10;
    node->next=newListNode(-1);
    intToListR(node->next, x/10);
}

struct ListNode* intToList(long x){
    struct ListNode* head=newListNode(-1);
    intToListR(head, x);
    return head;
}

int listToInt(struct ListNode *node, int n, int mul){
    if(node==NULL) return n;
    return listToInt(node->next, n+node->val*mul, mul*10);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    return intToList(listToInt(l1, 0, 1)+listToInt(l2, 0, 1));
}
*/
