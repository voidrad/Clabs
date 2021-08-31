//
// Created by YaTeb on 1/3/2021.
//
#include <stdio.h>
#include <stdlib.h>

struct list
{
    int field;
    struct list *ptr;
};

struct list * init(int a)
{
    struct list *lst;
    lst = (struct list*)malloc(sizeof(struct list));
    lst->field = a;
    lst->ptr = NULL;
    return(lst);
}

struct list * addelem(struct list *lst, int number)
{
    struct list *temp, *p;
    temp = (struct list*)malloc(sizeof(lst));
    p = lst->ptr;
    lst->ptr = temp;
    temp->field = number;
    temp->ptr = p;
    return(temp);
}



struct list * deletelem(struct list *lst, struct list *root)
{
    struct list *temp;
    temp = root;
    while (temp->ptr != lst)
    {
        temp = temp->ptr;
    }
    temp->ptr = lst->ptr;
    free(lst);
    return(temp);
}


void listprint(struct list *lst)
{
    struct list *p;
    p = lst;
    do {
        printf("%d ", p->field);
        p = p->ptr;
    } while (p != NULL);
}

struct list * swap(struct list *lst1, struct list *lst2, struct list *head)
{

    struct list *prev1, *prev2, *next1, *next2;
    prev1 = head;
    prev2 = head;
    if (prev1 == lst1)
        prev1 = NULL;
    else
        while (prev1->ptr != lst1)
            prev1 = prev1->ptr;
    if (prev2 == lst2)
        prev2 = NULL;
    else
        while (prev2->ptr != lst2)
            prev2 = prev2->ptr;
    next1 = lst1->ptr;
    next2 = lst2->ptr;

        if (lst1 != head)
            prev1->ptr = lst2;
        lst2->ptr = next1;
        if (lst2 != head)
            prev2->ptr = lst1;
        lst1->ptr = next2;

    return(head);
}


int main()
{
    int k;
    int i = 0;
    struct list *head,*r,*p, *sw,*head2,*head3;
    int a, n;
    printf("n= ");
    scanf("%d",&n);
    head = 0;
    p = 0;
// Создание списка

    printf("VVedi Elementi:");
    for (int i = 0; i<n; i++)
    {
        scanf("%d", &a);
        if (i == 0)
        {
            p = init(a);
            head = p;
        }
        else
            p = addelem(p, a);
    }
// Вывод списка
    listprint(head);

    printf("VVedi k:");
    scanf("%d", &k);
    if (( k < 2 ) || (k >=n)){
        printf("Nevozmozno zamenit");
    }
    else{ if (k == 2){
        sw = head->ptr;
        head3 = head->ptr->ptr->ptr;
        head2 = head->ptr->ptr;
        head2->ptr = sw;
        head->ptr = head3;
        sw->ptr = head;
        head = head2;

    }else{
        sw = head;
        while ( i < k - 2){
                sw = sw->ptr;
                i++;
            }
        swap(sw,sw->ptr->ptr, head );
    }}
    listprint(head);
    printf("\n");
    return 0;
}