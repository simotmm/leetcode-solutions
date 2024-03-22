// https://leetcode.com/problems/maximum-depth-of-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//ricorsivo in due righe
int max(a, b){return a>b?a:b;}

int maxDepth(struct TreeNode* root){return root!=NULL? 1+max(maxDepth(root->left), maxDepth(root->right)) : 0;}

/*
//ricorsivo
void calculateDepth(struct TreeNode* node, int current, int *depth){
    if(node==NULL) return;
    if(current>*depth) (*depth)=current;
    calculateDepth(node->left, current+1, depth);
    calculateDepth(node->right, current+1, depth);
}

int maxDepth(struct TreeNode* root) {
    int d=0;
    calculateDepth(root, 1, &d);
    return d;
}
*/

