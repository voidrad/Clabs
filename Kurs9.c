//
// Created by YaTeb on 4/9/2021.
//
#include <windows.h>
#include "table.h"


Table *Create(int * err_code)
{
    Table *t = (Table*)malloc(sizeof(Table));
    if (t == NULL)
    {
        *err_code = NO_MEMORY;
        return NULL;
    }

    t->size = 10;
    t->count = 0;
    t->records = (Record *)malloc(sizeof(Record) * t->size);
    return t;
}

void Destroy(Table *t)
{
    for(int i = 0; i < t->size; i++)
    {
        free(t->records[i].value);
    }
    free(t->records);
    free(t);
}

int Insert(Table *t, KeyType key, char * value) //err_code
{
    if(t->size == t->count)
    {
        t->size += 10;
        t->records = (Record *) realloc(t->records, sizeof(Record) * t->size);
    }

    t->records[t->count].key = key;
    t->records[t->count].value = value;
    t->count++;
    return NO_ERROR;
}

void Print(Table *t)
{
    for(int i = 0; i < t->count; i++)
    {
        Record record = t->records[i];
        printf("%lld|%s\n", record.key.number, record.value);
    }
    printf("\n");
}

void search(Table *t, long long k) {
    for(int i = 0; i < t->count; i++) {
        if (t->records[i].key.number == k)
            printf("For key %lld element is:\n%s\n", k, t->records[i].value);
    }

}

void search2(Table *t, long long k) {

    int left = 0;
    int right = t->size - 1;
    long long a=(t->size)/2;

    while  (a!=k) {
        if  (a<k)	{
            left = a;
            a = (left+right)/2;
        }
        if  (a>k) {
            right = a;
            a = (left+right)/2;
        }
    }
    printf("For key %lld element is:\n%s\n", k, t->records[a].value);

}




void Sort(Table *t, int size) {
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    //Центральный элемент массива
    KeyType mid = t->records[size / 2].key;


    do {

        while(t->records[i].key.number < mid.number) {
            i++;
        }

        while(t->records[j].key.number > mid.number) {
            j--;
        }

        //Меняем элементы местами
        if (i <= j) {
            KeyType tmp = t->records[i].key;
            t->records[i].key = t->records[j].key;
            t->records[j].key = tmp;
            char * valuel = t->records[i].value;
            t->records[i].value = t->records[j].value;
            t->records[j].value = valuel;


            i++;
            j--;
        }
    } while (i <= j);

    if(j > 0) {
        Sort(t, j + 1);
    }
    if (i <= size-1) {
        Sort(t, size - i);
    }
    TSort(t);
}

void SwapRecord(Record *r1, Record *r2)
{
    Record tmp;
    tmp = *r1;
    *r1 = *r2;
    *r2 = tmp;
}


void CompareAndSwap(Record *records, int i1, int i2)
{
    KeyType k1 = records[i1].key;
    KeyType k2 = records[i2].key;
    if(k1.number > k2.number)
    {
        SwapRecord(&(records[i1]), &(records[i2]));
    }

}

void TSort(Table *t)
{
    for(int i = 0, k = t->count-1; i < k; i++)
    {
        for(int j = i; j < k; j++)
        {
            CompareAndSwap(t->records, j, j+1);
        }
        k--;
        for(int j = k; j >= i; j--)
        {
            CompareAndSwap(t->records, j, j+1);
        }
    }
}
Table *ReadFromFile(const char * const file_name, int *err_code)
{
    Table * t = Create(err_code);
    if(t == NULL) return t;
    FILE * f = fopen(file_name, "r"); //проверки

    while(!feof(f))
    {
        KeyType key;
        char * str = (char *)malloc(sizeof(char)* 120);
        if(fscanf(f, "%lld", &(key.number)) <= 0)
            break;

        int c;
        int i = 0;
        while(!feof(f) && (c = getc(f)) != '\n')
        {
            str[i] = c;
            i++;
        }
        str[i] = '\0';

        Insert(t, key, str);
    }
    fclose(f);
    *err_code = NO_ERROR;
    return t;
}

int main(void)
{	SetConsoleOutputCP(CP_UTF8);
    long long k;
    int err_code;
    Table *t = ReadFromFile("File.txt", &err_code);
    Print(t);
    Sort(t, t->size);
    Print(t);
    printf("Enter the key to print element: \n");
    scanf("%lld", &k);
    search2(t, k);
    Destroy(t);
    return 0;
}
