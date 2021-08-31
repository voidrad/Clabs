//
// Created by YaTeb on 6/9/2020.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "stack.h"
typedef struct _Node
{
    char _varOp;
    double _num;
    struct _Node *_left;
    struct _Node *_right;
} Node;


Node *treeNodeCreate(void);
Node *treeCopy(Node **node);
Node *Zamena1(Node **node);
int CheckLeftNode(Node **node);
void treeBuild(Node **node, Stack *st);
void treeDestroy(Node **node);
void PKL(Node **node, const int level);
void LKP(Node **node);

int isLetter(const char ch);
int isNumber(const char ch);
int isOp(const char ch);
int isOpHigh(const char op1, const char op2);
void postOrder(const char *str, Stack *st);

Node *treeNodeCreate(void){
    Node *tmpNode = malloc(sizeof(Node)); // ВНИМАНИЕ

    tmpNode->_varOp = '\0';
    tmpNode->_num = 0.0;
    tmpNode->_left = NULL;
    tmpNode->_right = NULL;

    return tmpNode;
}

Node *treeCopy(Node **node){
    Node *tmpNode = NULL;

    if (*node == NULL)
        return NULL;

    tmpNode = treeNodeCreate();
    tmpNode->_varOp = (*node)->_varOp;
    tmpNode->_num = (*node)->_num;
    tmpNode->_left = treeCopy(&((*node)->_left));
    tmpNode->_right = treeCopy(&((*node)->_right));
    return tmpNode;
}

int CheckLeftNode(Node **node){
    if (*node == NULL)
        return 0;

    if ((*node)->_left == NULL || (*node)->_right == NULL)
        return 0;

    return ((*node)->_left->_varOp == '\0' && (*node)->_left->_num == 0.0);
}

void treeBuild(Node **node, Stack *st){
    Token token;

    if (stackEmpty(st))
        return;

    token = stackTop(st);

    stackDelTop(st);

    (*node) = treeNodeCreate();
    (*node)->_varOp = token._varOp;
    (*node)->_num = token._num;

    if (isOp((*node)->_varOp)){
        treeBuild(&(*node)->_right, st);
        treeBuild(&(*node)->_left, st);
    }
}

void treeDestroy(Node **node){
    if (*node == NULL)
        return;

    if ((*node)->_left != NULL)
        treeDestroy(&(*node)->_left);

    if ((*node)->_right != NULL)
        treeDestroy(&(*node)->_right);

    free(*node);
}

void PKL(Node **node, const int level){
    if (*node == NULL)
        return;

    if ((*node)->_right != NULL)
        PKL(&(*node)->_right, level + 1);

    if ((*node)->_varOp != '\0')
        printf("%*s%c\n", level * 4, "", (*node)->_varOp);
    else
        printf("%*s%f\n", level * 4, "", (*node)->_num);

    if ((*node)->_left != NULL)
        PKL(&(*node)->_left, level + 1);
}

void LKP(Node **node){
    if (*node == NULL)
        return;

    if ((*node)->_left != NULL && !CheckLeftNode(node)){

        if ((*node)->_left->_left != NULL)
            printf("(");


        LKP(&(*node)->_left);
        if ((*node)->_left->_left != NULL)
            printf(")");
    }

    if ((*node)->_varOp != '\0')
        printf("%c", (*node)->_varOp);
    else
        printf("%f", (*node)->_num);

    if ((*node)->_right != NULL){
        if ((*node)->_right->_left != NULL)
            printf("(");

        LKP(&(*node)->_right);

        if ((*node)->_right->_left != NULL)
            printf(")");
    }

}
int isLetter(const char ch){
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

int isNumber(const char ch){
    return (ch >= '0' && ch <= '9');
}

int isOp(const char ch){
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '(' || ch == ')');
}

int opPrior(const char op){
    if (op == '^')
        return 4;

    if (op == '*' || op == '/')
        return 3;

    if (op == '+' || op == '-')
        return 2;

    return 1;
}
int isOpHigh(const char op1, const char op2){
    if (op1 == '(' || op2 == '(' || op2 == ')')
        return 0;

    if (op1 == op2 && op2 == '^')
        return 0;

    return (opPrior(op1) >= opPrior(op2));
}

void postOrder(const char *str, Stack *st){

    int i = 0, isBracket = 0;

    Token tk;
    Stack stOp;

    stackCreate(&stOp);

    tk._varOp = '\0';
    tk._num = 0.0;

    while (str[i] != '\0'){
        if (isLetter(str[i])){
            tk._varOp = str[i];
            stackPush(st, tk);
        }
        else if (isNumber(str[i])){
            tk._varOp = '\0';
            tk._num = tk._num * 10.0 + str[i] - '0';

            if (!isNumber(str[i + 1])){
                stackPush(st, tk);
                tk._num = 0.0;
            }
        }
        else if (isOp(str[i])){
            tk._varOp = str[i];

            if (str[i] == ')')
                isBracket = 1;

            while (!stackEmpty(&stOp) && (isOpHigh(stackTop(&stOp)._varOp, str[i]) || isBracket)){
                if (stackTop(&stOp)._varOp == '(')
                    isBracket = 0;
                else
                    stackPush(st, stackTop(&stOp));

                stackDelTop(&stOp);
            }

            if (str[i] != ')')
                stackPush(&stOp, tk);
        }

        i++;
    }

    while (!stackEmpty(&stOp)){
        stackPush(st, stackTop(&stOp));
        stackDelTop(&stOp);
    }

    stackDestroy(&stOp);
}


Node *Zamena1(Node **node){
    if ((*node)!= NULL){

        if(((*node)->_left!=NULL)  && ((*node)->_right!=NULL)){
            if ((((*node)->_left)->_varOp == '/' ) && (((*node)->_right)->_varOp == '/' ) && ((*node)->_varOp =='*')){
                double change;
                (*node)->_varOp ='/';
                ((*node)->_left)->_varOp = '*';
                ((*node)->_right)->_varOp = '*';
                change =((*node)->_right)->_left->_num;
                ((*node)->_right)->_left->_num = ((*node)->_left)->_right->_num;
                ((*node)->_left)->_right->_num =change;

            }
            else{
                Zamena1(&(*node)->_left);
                Zamena1(&(*node)->_right);
            }}
    }
}
int main(void)
{
    int action;
    char expr[255];
    Node *root = NULL, *root2 = NULL;
    Stack stPost;

    while (1)
    {
        printf("Menu:\n");
        printf("1) enter expression\n");
        printf("2) print inserted expression\n");
        printf("3) print changed expresson\n");
        printf("4) print entered tree\n");
        printf("5) print changed tree\n");
        printf("6) exit\n");
        printf("chose: ");
        scanf("%d", &action);

        switch (action)
        {
            case 1:
            {
                printf("vvedi: ");
                scanf("%s", expr);
                treeDestroy(&root);
                treeDestroy(&root2);
                stackCreate(&stPost);
                postOrder(expr, &stPost);
                treeBuild(&root, &stPost);
                stackDestroy(&stPost);
                root2 = treeCopy(&root);
                Zamena1(&root2);
                break;
            }

            case 2:
            {
                printf("Исходное выражение: %s\n", expr);

                break;
            }

            case 3:
            {
                LKP(&root2);

                printf("\n");

                break;
            }

            case 4:
            {
                if (root != NULL)
                {
                    printf("Дерево исходного выражения\n");
                    PKL(&root, 0);
                }
                else
                    printf("Дерево исходного выражения пусто\n");

                break;
            }

            case 5:
            {
                if (root2 != NULL)
                {
                    printf("Дерево преобразованного выражения\n");
                    PKL(&root2, 0);
                }
                else
                    printf("Дерево преобразованного выражения пусто\n");

                break;
            }

            case 6: break;

            default:
            {
                printf("Ошибка. Такого пункта меню не существует\n");

                break;
            }
        }

        if (action == 6)
            break;
    }

    treeDestroy(&root);
    treeDestroy(&root2);

    return 0;
}