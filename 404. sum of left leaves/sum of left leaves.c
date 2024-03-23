// https://leetcode.com/problems/sum-of-left-leaves

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfs(struct TreeNode *node, int *sum, int isLeft){
    if(node==NULL)
        return;
    if(isLeft && node->left==NULL && node->right==NULL)
        (*sum)+=node->val;
    dfs(node->left, sum, 1);
    dfs(node->right, sum, 0);
}

int sumOfLeftLeaves(struct TreeNode* root) {
    int sum=0;
    dfs(root, &sum, 0);
    return sum;
}