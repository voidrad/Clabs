//
// Created by Semka on 11-Apr-20.
//

#include <stdlib.h>
#include <stdio.h>

typedef struct TreeNode TreeNode;

struct TreeNode
{
    double value;
    TreeNode *l, *r;
};

TreeNode* makeNode(double val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->value = val;
    node->l = node->r = NULL;
    return node;
}

void add(TreeNode* current, TreeNode* newElement) {
    if (newElement->value < current->value) {
        if (current->l == NULL) {
            current->l = newElement;
            return;
        }
        add(current->l, newElement);
    } else {
        if (current->r == NULL) {
            current->r = newElement;
            return;
        }
        add(current->r, newElement);
    }
}

TreeNode** find(TreeNode** current, double val) {
    if (*current == NULL) {
        return current;
    }
    if (val < (*current)->value) {
        return find(&((*current)->l), val);
    } else if (val > (*current)->value) {
        return find(&((*current)->r), val);
    } else {
        return current;
    }
}

void clearTree(TreeNode* current) {
    if (current->l != NULL) {
        clearTree(current->l);
        free(current->l);
    }
    if (current->r != NULL) {
        clearTree(current->r);
        free(current->r);
    }
}

// rRl
void print(TreeNode* current, int d) {
    if (current->r != NULL) {
        print(current->r, d + 1);
    }
    printf("%*s%lf\n", 4 * d, " ", current->value);
    if (current->l != NULL) {
        print(current->l, d + 1);
    }
}
int key = 0;
void step(TreeNode* current) {

        if ((current->l == NULL)&& (current->r == NULL) && (key == 0))
    {
        printf("Stepen = 0");
    }else
        if ((current->l != NULL)&&(current->r != NULL))
        {
            printf("Stepen = 2");
            key = 0;
    }else
        if ((current->l == NULL)&&(current->r == NULL) && (key != 1))
        {
            printf("Stepen = 1");
            key = 0;
    }else
        if(current->r !=NULL){
            key++;
            step(current->r);

    }else
        if (current->l !=NULL){
            key++;
            step(current->l);


        }
}



int main() {
    TreeNode* root = NULL;

    double val;
    while (scanf("%lf", &val) == 1) {
        if (root == NULL) {
            root = makeNode(val);
        } else {
            add(root, makeNode(val));
        }
    }

    print(root, 0);

step(root);

    if (root != NULL) {
        clearTree(root);

        // free(root);
    }

    return 0;
}