#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef TD7_FONCTIONS_H
#define TD7_FONCTIONS_H

struct NodeTree{
    int value;
    int h;
    struct NodeTree *left;
    struct NodeTree *right;
};

#define MAX_SIZE 20

struct NodeTree* createEmptyTree();
struct NodeTree* bin(struct NodeTree* l, int value, struct NodeTree* r);
bool isTreeEmpty(struct NodeTree* tree);
struct NodeTree* left(struct NodeTree* tree);
struct NodeTree* right(struct NodeTree* tree);
int root(struct NodeTree* tree);
void deleteLeaf(struct NodeTree* tree);
void deleteTree(struct NodeTree* tree);
bool isLeaf(struct NodeTree* tree);
int numberNodes(struct NodeTree* tree);
int numberLeaves(struct NodeTree* tree);
int numberInternalNodes(struct NodeTree* tree);
int sumValues(struct NodeTree* tree);
int height(struct NodeTree* tree);
bool belongs(struct NodeTree* tree, int x);
int lastFullLevel(struct NodeTree* tree);
void descendants(struct NodeTree* tree, int x);
struct NodeTree* mirror(struct NodeTree* tree);
bool equals(struct NodeTree* tree1,struct NodeTree* tree2);
int numberRepetitions(struct NodeTree* tree, int x);
void pathTo(struct NodeTree* tree, int x);
void preorder(struct NodeTree* tree);
void postorder(struct NodeTree* tree);
void inorder(struct NodeTree* tree);
void BFS(struct NodeTree* tree);
struct NodeTree* buildTreeFromPreIn(int pre[],int in[],int sp,int ep,int si,int ei);
struct NodeTree* buildTreeFromPostIn(int post[],int in[],int sp,int ep,int si,int ei);
struct NodeTree* buildTreeFromBFSIn(int bfs[],int in[],int sb,int eb,int si,int ei);
void printByLevel(struct NodeTree* tree);
int sumlevel(struct NodeTree* tree,int level);
void createpre(struct NodeTree* tree,int *pre[MAX_SIZE],int* n);
bool isBST(struct NodeTree* tree);
struct NodeTree* find(struct NodeTree* tree, int value);
struct NodeTree* findMin(struct NodeTree* tree);
struct NodeTree* findMax(struct NodeTree* tree);
void insert(struct NodeTree* tree, int value);
void delete(struct NodeTree* tree, int value);
bool equivalentsBST(struct NodeTree* tree1, struct NodeTree* tree2);
void getInorderArray(struct NodeTree* tree,int* tab,int* index);
void getPreorderArray(struct NodeTree* tree,int* tab,int* index);


#endif //TD7_FONCTIONS_H
