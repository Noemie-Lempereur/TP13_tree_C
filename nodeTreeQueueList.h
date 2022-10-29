#ifndef _NODETREEQUEUELIST_H
#define _NODETREEQUEUELIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "nodeTreeList.h"


struct Queue {
    struct List* l;
};

struct Queue* createEmptyQueue();

void enqueue(struct Queue* q,struct NodeTree* item, bool* valid);

struct NodeTree* head(struct Queue* q, bool* valid);

struct NodeTree* dequeue(struct Queue* q,bool* valid);

int queueSize(struct Queue* q);

bool isQueueEmpty(struct Queue* q);

void printQueue(struct Queue* q);

void deleteQueue(struct Queue* q);

#endif //_NODETREEQUEUELIST_H