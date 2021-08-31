
#ifndef _TABLE_H
#define _TABLE_H

#include <stdlib.h>
#include <stdio.h>

#define NO_ERROR 0
#define NO_MEMORY 2

typedef struct
{
    long long number;
} KeyType;

typedef struct
{
    KeyType key;
    char * value;
} Record;

typedef struct
{
    Record * records;
    int count;
    int size;
} Table;

Table *Create(int * err_code);
void Destroy(Table *t);
int Insert(Table *t, KeyType key, char * value);
void Print(Table *t);
void TSort(Table *t);
Table *ReadFromFile(const char * const file_name, int *err_code);
#endif
