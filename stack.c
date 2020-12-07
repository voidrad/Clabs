//
// Created by YaTeb on 12/7/2020.
//

#include "stack.h"
void stackCreate(Stack *s)
{
    s->_size = 0;
    s->_top = NULL;
}

int stackEmpty(const Stack *s)// проверяет пустой ли стек
{
    return s->_top == NULL;
}

int stackSize(const Stack *s)
{
    return s->_size;
}

int stackPush(Stack *s, const STACK_TYPE value)// добавление элемента в стек
{
    ItemStack *item = (ItemStack *)malloc(sizeof(ItemStack));

    if (!item)// if (!a)можно переписать как if (a==0)
        return 0;
    item->_data = value;
    item->_prev = s->_top;
    s->_top = item;
    s->_size++;

    return 1;
}

int stackDelTop(Stack *s) // удаление верзнего элемента
{
    ItemStack *item = NULL;

    if (!s->_size)
        return 0;

    item = s->_top; // присваиваем топовому элементу имя item
    s->_top = s->_top->_prev;// меняем ссылку с топового элемента ведь у нас удаление идет
    s->_size--;

    free(item);

    return 1;
}

STACK_TYPE stackTop(const Stack *s)
{
    return s->_top->_data;
}

void stackDestroy(Stack *s)
{
    ItemStack *item = NULL;

    while (s->_top)
    {
        item = s->_top;
        s->_top = s->_top->_prev;

        free(item);
    }

    s->_size = 0;
    s->_top = NULL;
}
