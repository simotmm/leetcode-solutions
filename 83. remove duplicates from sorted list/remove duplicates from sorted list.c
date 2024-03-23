// https://leetcode.com/problems/remove-duplicates-from-sorted-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteR(struct ListNode *node){
    if(node==NULL || node->next==NULL) return;
    if(node->next->val==node->val){
        struct ListNode *tmp=node->next;
        node->next=node->next->next;
        free(tmp);
    }
    if(node->next!=NULL && node->next->val==node->val)
        deleteR(node);
    deleteR(node->next);
}

struct ListNode* deleteDuplicates(struct ListNode* head) {
    deleteR(head);
    return head;
}