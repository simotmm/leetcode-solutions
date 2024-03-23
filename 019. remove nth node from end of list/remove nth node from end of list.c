// https://leetcode.com/problems/remove-nth-node-from-end-of-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int countNodes(struct ListNode *node, int cont){
    return node==NULL? cont : countNodes(node->next, cont+1);
}

void removeR(struct ListNode *node, int n, int current){
    if(current==n-1){
        node->next=node->next->next;
        return;
    }   
    if(node->next!=NULL)
        removeR(node->next, n, current+1);
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int size=countNodes(head, 0), i;
    struct ListNode *currentNode=head;
   
    if(size==n) return head->next;

    removeR(head, size-n, 0);

    return head;
}

/*
// con print per debug
void removeR(struct ListNode *node, int n, int current){
    printf("nodo corrente: ");
    if(node==NULL) printf("NULL");
    else printf("%d ", node->val);
    printf(" (n: %d, current: %d)\n", n, current);
    if(n==0){
        node=NULL;
        return;
    }
    if(current==n-1){
        node->next=node->next->next;
        return;
    }   
    if(node->next!=NULL)
        removeR(node->next, n, current+1);
    return;
}

void printList(struct ListNode *node){
    if(node==NULL){
        printf("\n");
        return;
    }
    printf("%d", node->val);
    if(node->next!=NULL)
        printf("->");
    printList(node->next);
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int size=countNodes(head, 0), i;
    struct ListNode *currentNode=head;
    
    printList(head);
    printf("size-n=%d-%d=%d\n", size, n, size-n);

    if(size==n)
        return head->next;

    removeR(head, size-n, 0);
    printList(head);
    
    return head;
}
*/