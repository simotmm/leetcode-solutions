// https://leetcode.com/problems/count-complete-tree-nodes/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(struct TreeNode* node, int *count){
    if(node==NULL)
        return;
    (*count)++;
    dfs(node->left, count);
    dfs(node->right, count);
}

int countNodes(struct TreeNode* root) {
    int cont=0;
    dfs(root, &cont);
    return cont;
}