// https://leetcode.com/problems/same-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void check(struct TreeNode *n1, struct TreeNode *n2, int *same){
    if(n1==NULL && n2==NULL)
        return;

    if( (n1==NULL && n2!=NULL) || 
        (n1!=NULL && n2==NULL) ||
        (n1->val!=n2->val) ){
        (*same)=0;
        return;
    }
    
    check(n1->left, n2->left, same);
    check(n1->right, n2->right, same);
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    int s=1;
    check(p, q, &s);
    return s;
}