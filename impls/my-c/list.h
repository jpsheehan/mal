#ifndef __LIST_H__
#define __LIST_H__

typedef struct List {
    struct List* next;
    void* value;
} List;

List* List_New(void*);
void List_Free(List*);
void* List_Get(List*, int);
void List_Push(List*, void*);

#endif
