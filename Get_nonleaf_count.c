#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode n1={22, NULL, NULL};
TreeNode n2 = {5, NULL, NULL};
TreeNode n3 = {35, &n1, NULL};
TreeNode n4 = {95, NULL, NULL};
TreeNode n5 = {15, &n2, NULL};
TreeNode n6 = {93, &n3, &n4};
TreeNode n7 = {17, &n5, &n6};

int get_nonleaf_count(TreeNode *t);

int main()
{
    printf("%d", get_nonleaf_count(&n7));
    return 0;
}

int get_nonleaf_count(TreeNode *t)
{
    int count = 0;
    if(t!=NULL){
        if(t->left != NULL || t->right != NULL){
            count = 1 + get_nonleaf_count(t->left) +
                    get_nonleaf_count(t->right);
        } else{ return 0;}
    }
    return count;
}
