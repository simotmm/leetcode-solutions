// https://leetcode.com/problems/binary-tree-paths/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define PRINT 0
#define PRESTAZIONI 1
#define MEMORIA !PRESTAZIONI

void countLeaves(struct TreeNode *node, int *count, int *depth, int currentDepth){
    /*
    printf("depth: %d, node: ", currentDepth);
    if(node==NULL) printf("NULL ");
    else printf("%4d ", node->val);
    printf("(maxDepth: %d) ", (*depth));
    */
    
    if(node==NULL){
        //printf("\n");
        return;
    }
        
    if(node->left==NULL && node->right==NULL){
        (*count)++;
        //printf("this is a leaf");
    }
    //printf("\n");
        

    (*depth)=currentDepth>(*depth)?currentDepth:(*depth);

    countLeaves(node->left, count, depth, currentDepth+1);
    countLeaves(node->right, count, depth, currentDepth+1);
} 

void dfs(struct TreeNode *node, char *path, char **paths, int *size){
    if(node==NULL)
        return;

    int len=strlen(path);
    sprintf(path, "%s%s%d", path, len==0?"":"->", node->val);

    if(node->left==NULL && node->right==NULL)
        paths[(*size)++]=strdup(path);
    else{
        dfs(node->left, path, paths, size);
        dfs(node->right, path, paths, size);
    }
    path[len]='\0';
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    int leaves=0, depth=0, i, size=0;
    char **res;

    #if MEMORIA
    printf("%s", PRINT?"modalita di ottimizzazione della memoria\n":"");
    //per ottimizzare la memoria: si contano prima le foglie e si alloca lo spazio esatto
    //(richiede due una dfs in più)
    countLeaves(root, &leaves, &depth, 1);
    //printf("the tree has %d lea%s\n", leaves, leaves>1?"ves":"f");
    res=calloc(leaves, sizeof(char*));
    char *s=calloc(depth*4+depth*3+1, sizeof(char));

    #else
    printf("%s", PRINT?"modalità di ottimizzazione delle prestazioni\n":"");
    //per ottimizzare le prestazioni: si alloca lo spazio nel caso peggiore 
    //(100 nodi -> 37 foglie -> 37 paths -> 37 stringhe)
    //(-100 <= node->val >= 100 -> len max di ogni stringa: 37*4("-100")+37*3("->")+1('\n'))
    res=calloc(37, sizeof(char*));
    char *s=calloc(37*4+37*3+1, sizeof(char));
    #endif

    dfs(root, s, res, &size);
    *returnSize=size;

    return res;
}