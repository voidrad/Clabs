//
// Created by YaTeb on 4/8/2021.
//
#include <stdio.h>
#include <stdlib.h>
struct complex {
    double re, im;
} ;
struct complex *makeComplex(double re, double im) {
    struct complex *c =(struct complex* )malloc(sizeof(struct complex));
    c->re = re;
    c->im = im;
    return c;
}
typedef struct {
    int data[100];
    int sz;
} vector;
typedef struct {
    struct complex *data[100];
    int sz;
} vect;
void vectorInit(vector *v) {
    v->sz = 0;
}
void vectInit(vect *v) {
    v->sz = 0;
}
void push1(vector *v, int value) {
    v->data[v->sz++] = value;
}
void push2(vect *v, double valuere, double valueim) {
    v->data[v->sz++] = makeComplex(valuere, valueim);
}
void printmatrix(vect *v, vector *idx,int m, int n) {
    if (v->sz >0){
        int k =0;
        for(int i =0; i < m*n; i++){
            if (i == idx->data[k]){
                printf("%4.2lf+%4.2lf*i ",v->data[k]->re ,v->data[k]->im);
                k++;

            }
            else
            {
                printf("%-4d+%-4d*i ",0,0);

            }
            if ((i+1) % m ==0)
                printf("\n");

        }

    }
    else
        printf("the matrix is empty"); }
void freematrix(vect *v) {
    for
    (int i =0; i < v->sz; i++){
        free(v->data[i]);
    }
}
int main() {
    int n, m;
    int res = 0;
    printf("enter the size of the matrix\n");
    scanf("%d %d", &n, &m);
    vector idx;
    vectorInit(&idx);
    vect v;
    vectInit(&v);
    vect task;
    vectInit(&task);
    vect end;
    vectInit(&end);

    printf("enter the matrix\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            double valuere, valueim;
            scanf("%lf", &valuere);
            scanf("%lf", &valueim);
            if (valuere == 0 && valueim == 0) continue;
            push1(&idx, i * m + j);
            push2(&v, valuere, valueim);
        }
    }
    printf("enter the vector\n");
    for (int i = 0; i < m; ++i){
        double valuere, valueim;
        scanf("%lf", &valuere);
        scanf("%lf", &valueim);
        task.sz++;
        task.data[i] = makeComplex(valuere,valueim);


    }
    for (int i = 0; i < m; ++i){
        push2(&end, 0.0, 0.0);
    }

    printmatrix(&v,&idx,m,n);
    int k =0;
    for(int i =0; i < m*n; i++){
        if (i == idx.data[k]){
           printf(" Zahel na   %d \n", idx.data[k]);
           end.data[i%m]->re = end.data[i%m]->re + (v.data[k]->re * task.data[i%m]->re - v.data[k]->im * task.data[i%m]->im);
           end.data[i%m]->im = end.data[i%m]->im + (v.data[k]->re * task.data[i%m]->im + v.data[k]->im * task.data[i%m]->re);
            k++;
        }
    }
    for(int i =0; i < m; i++){
        if ((end.data[i]->re !=0)||(end.data[i]->im !=0)){
            res++;
        }
    }
    printf("%d", res);

    freematrix(&v);
    freematrix(&task);

}