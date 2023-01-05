#include <stdlib.h>

#include "list.h"

List* List_New(void* value)
{
    List* l = calloc(1, sizeof(List));
    if (l == NULL) return NULL;

    l->value = value;
    l->next = NULL;

    return l;
}

void List_Free(List* l)
{
    while (l) {
        List* next = l->next;
        free(l);
        l = next;
    }
}

void* List_Get(List* l, int n)
{
    for (int i = 0; (i < n) && l; i++, l = l->next)
        continue;
    return l ? l->value : NULL;
}

void List_Push(List* l, void* value)
{
    while (l->next) {
        l = l->next;
    }
    l->next = List_New(value);
}