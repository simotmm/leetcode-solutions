// https://leetcode.com/problems/symmetric-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfs(struct TreeNode* left, struct TreeNode* right, int *flag){
    if(left==NULL && right==NULL)
        return;
    if(left!=NULL && right!=NULL){
        dfs(left->left, right->right, flag);
        if(left->val!=right->val){
            *flag=0;
            return;
        }
        dfs(left->right, right->left, flag);
    }
    else{
        *flag=0;
        return;
    }
    
}

bool isSymmetric(struct TreeNode* root) {
    int symmetric=1;
    dfs(root->left, root->right, &symmetric);
    return symmetric;
}