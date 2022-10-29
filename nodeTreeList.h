#ifndef _NODETREELIST_H
#define _NODETREELIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"


struct Cell{
    struct NodeTree* value;
    struct Cell* next;
};

struct List{
    int size;
    struct Cell* head;
};

struct Cell* createCell(struct NodeTree* val);

struct List* createEmptyList();

void addFirst(struct List* l, struct NodeTree* value);

bool isListEmpty(struct List* l);

struct NodeTree* getItemPos(struct List* l, int position, bool* valid);

void deleteFirst(struct List* l);

void printList(struct List* l);

int listSize(struct List* l);

void addItemPos(struct List* l, struct NodeTree* value, int position, bool* valid);

void deleteItemPos(struct List* l, int position, bool* valid);

void deleteList(struct List* l);



#endif //_NODETREELIST_H




