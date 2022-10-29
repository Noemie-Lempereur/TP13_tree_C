#include "tree.h"
#include "nodeTreeList.h"
#include "nodeTreeQueueList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isBST(struct NodeTree* tree) {
    //Ma version:
    /*int l=0;
    int r=0;
    if (!isTreeEmpty(tree)){
        if(!isTreeEmpty(left(tree))) {
            l=1;
        }
        if(!isTreeEmpty(right(tree))) {
            r = 1;
        }
        if(r==1&&root(tree)<root(right(tree))&&l==1&&root(tree)>root(left(tree))){
            return isBST(right(tree))&&isBST(left(tree));
        }
        if(r==1&&root(tree)<root(right(tree))){
            return isBST(right(tree));
        }
        if(l==1&&root(tree)>root(left(tree))){
            return isBST(left(tree));
        }
        return false;
    }
    return true;*/

    //Version corrigée avec inorder:
    int n = numberNodes(tree);
    int *tab = malloc(n * sizeof(int));
    int index = 0;
    getInorderArray(tree, tab, &index);
    for (int i = 0; i < n - 1; i++) {
        if (tab[i] >= tab[i + 1]) {
            free(tab);
            return false;
        }
    }
    free(tab);
    return true;
}

    //Version corrigée sans inorder:
    /*if(isTreeEmpty(tree)){
        return true;
    }
    if(!isTreeEmpty(left(tree))){
        int max=chercherMax(left(tree));
        if(max>=root(tree)){
            return false;
        }
    }
    if(!isTreeEmpty(right(tree))){
        int min=chercherMin(right(tree));
        if(min>=root(tree)){
            return false;
        }
    }
    return isBST(left(tree))&&isBST(right(tree));
}*/

void getInorderArray(struct NodeTree* tree,int* tab,int* index){
    if(!isTreeEmpty(tree)){
        getInorderArray(left(tree),tab,index);
        tab[*index]=root(tree);
        *index=*index+1;
        getInorderArray(right(tree),tab,index);
    }
}

void getPreorderArray(struct NodeTree* tree,int* tab,int* index){
    if(!isTreeEmpty(tree)){
        tab[*index]=root(tree);
        *index=*index+1;
        getPreorderArray(left(tree),tab,index);
        getPreorderArray(right(tree),tab,index);
    }
}

struct NodeTree* find(struct NodeTree* tree, int value){
    if (isTreeEmpty(tree)){
        return NULL;
    }
    if (value==root(tree)){
        return tree;
    }
    if(value<root(tree)&&!isTreeEmpty(left(tree))){
        return find(left(tree),value);
    }
    if(value>root(tree)&&!isTreeEmpty(right(tree))){
        return find(right(tree),value);
    }
    return NULL;
}

struct NodeTree* findMin(struct NodeTree* tree){
    if (isTreeEmpty(tree)){
        return NULL;
    }
    if(!isTreeEmpty(left(tree))){
        return findMin(left(tree));
    }else{
        return left(tree);
    }
}

struct NodeTree* findMax(struct NodeTree* tree){
    if (isTreeEmpty(tree)){
        return NULL;
    }
    if(!isTreeEmpty(right(tree))){
        return findMin(right(tree));
    }else{
        return right(tree);
    }
}
/*
void insert(struct NodeTree* tree, int value){
    if (!isTreeEmpty(tree)){
        struct NodeTree *tree2=tree;
        int fini=0;
        while(fini==0){
            if(value<root(tree2)){
                if(left(tree2)==NULL) {
                    tree2->left=bin(createEmptyTree(),value,createEmptyTree());
                    fini=1;
                } else {
                    tree2 = left(tree2);
                }
            }
            if(value>root(tree2)&&fini==0){
                if(right(tree2)==NULL) {
                    tree2->right=bin(createEmptyTree(),value,createEmptyTree());
                    fini=1;
                } else {
                    tree2 = right(tree2);
                }
            }
        }
    }
}*/

void insertBST(struct NodeTree* tree, int value){
    if(root(tree)==value){
        return;
    }
    if(root(tree)<value){
        if(isTreeEmpty(right(tree))){
            tree->right=bin(NULL,value,NULL);
            return;
        }
        else{
            insertBST(right(tree),value);
            return;
        }
    }
    else{
        if(isTreeEmpty(left(tree))){
            tree->left=bin(NULL,value,NULL);
            return;
        }
        else{
            insertBST(left(tree),value);
            return;
        }
    }
}

void delete(struct NodeTree* tree, int value){
    struct NodeTree* tree1=find(tree,value);
    if(isLeaf(tree1)){
        deleteLeaf(tree1);
        return;
    }
    if(!isTreeEmpty(right(tree1))&&!isTreeEmpty(left(tree1))){
        tree1->value=root(findMax(left(tree1)));
        delete(left(tree1),root(findMax(left(tree1))));
        return;
    }
    if(!isTreeEmpty(right(tree1))) {
        tree1->right = right(right(tree1));
        tree1->left = right(left(tree1));
        tree1->value = root(right(tree1));
    }
    if(!isTreeEmpty(left(tree1))){
        tree1->right = left(right(tree1));
        tree1->left = left(left(tree1));
        tree1->value = root(left(tree1));
    }
}
    /*void delete(struct NodeTree* tree, int value){
    if(!isTreeEmpty(tree)){
        if(root(tree) == value){
            if(isTreeEmpty(left(tree)) && isTreeEmpty(right(tree))){
                free(tree);
            }else if(isTreeEmpty(left(tree))){
                struct NodeTree* toDelete = tree;
                tree = right(tree);
                free(toDelete);
            }else if(isTreeEmpty(right(tree))){
                struct NodeTree* toDelete = tree;
                tree = left(tree);
                free(toDelete);
            }else{
                tree->value = root(findMax(left(tree)));
                delete(left(tree), root(findMax(left(tree))));

            }
        }else if(root(tree) > value){
            if(!isTreeEmpty(left(tree))){
                if(root(left(tree)) == value){
                    if(isTreeEmpty(left(left(tree))) && isTreeEmpty(right(left(tree)))){
                        free(left(tree));
                        tree->left = NULL;
                    }else if(isTreeEmpty(left(left(tree)))){
                        struct NodeTree* toDelete = left(tree);
                        tree->left = right(left(tree));
                        free(toDelete);
                    }else if(isTreeEmpty(right(left(tree)))){
                        struct NodeTree* toDelete = left(tree);
                        tree->left = left(left(tree));
                        free(toDelete);
                    }else{
                        tree->left->value = root(findMax(left(left(tree))));
                        delete(left(left(tree)), root(findMax(left(left(tree)))));
                    }
                }else{
                    delete(left(tree), value);
                }
            }
        }else{
            if(!isTreeEmpty(right(tree))){
                if(root(right(tree)) == value){
                    if(isTreeEmpty(left(right(tree))) && isTreeEmpty(right(right(tree)))){
                        free(right(tree));
                        tree->right = NULL;
                    }else if(isTreeEmpty(left(right(tree)))){
                        struct NodeTree* toDelete = right(tree);
                        tree->right = right(right(tree));
                        free(toDelete);
                    }else if(isTreeEmpty(right(right(tree)))){
                        struct NodeTree* toDelete = right(tree);
                        tree->right = left(right(tree));
                        free(toDelete);
                    }else{
                        tree->right->value = root(findMax(left(right(tree))));
                        delete(left(right(tree)), root(findMax(left(right(tree)))));
                    }
                }else{
                    delete(right(tree), value);
                }
            }
        }
    }
}*/



bool equivalentsBST(struct NodeTree* tree1, struct NodeTree* tree2){
    if(numberNodes(tree1)!=numberNodes(tree2)){
        return false;
    }
    int n=numberNodes(tree1);
    int* tab1=malloc(n*sizeof(int));
    int index1=0;
    getInorderArray(tree1,tab1,&index1);
    int* tab2=malloc(n*sizeof(int));
    int index2=0;
    getInorderArray(tree2,tab2,&index2);
    for(int i=0;i<n;i++){
        if (tab1[i]!=tab2[i]){
            return false;
        }
    }
    return true;
}

struct NodeTree* createEmptyTree(){
    return NULL;
}

struct NodeTree* bin(struct NodeTree* l, int val, struct NodeTree* r){
    struct NodeTree *tree=malloc(sizeof(struct NodeTree));
    if(tree!=NULL) {
        tree->value = val;
        tree->left = l;
        tree->right = r;
    }
    return tree;
}

bool isTreeEmpty(struct NodeTree* tree){
    if(tree==NULL){
        return true;
    }
    return false;
}

struct NodeTree* left(struct NodeTree* tree){
    return tree->left;
}

struct NodeTree* right(struct NodeTree* tree){
    return tree->right;
}

int root(struct NodeTree* tree){
    return tree->value;
}

bool isLeaf(struct NodeTree* tree){
    if(isTreeEmpty(tree)==false){
        if (isTreeEmpty(left(tree))&&isTreeEmpty(right(tree))){
            return true;
        }
    }
    return false;
}


void deleteLeaf(struct NodeTree* tree){
    if(!isTreeEmpty(tree)) {
        if(isLeaf(tree)){
            free(tree);
            return;
        }
        else {
            if (isTreeEmpty(tree->left)) {
                if (isLeaf(tree->left)) {
                    free(tree->left);
                    tree->left = NULL;
                } else {
                    deleteLeaf(tree->left);
                }
            } else {
                if (isLeaf(tree->right)) {
                    free(tree->right);
                    tree->right = NULL;
                } else {
                    deleteLeaf(tree->right);
                }
            }
        }
    }
}

void deleteTree(struct NodeTree* tree){
    while(!isTreeEmpty(tree)){
        deleteLeaf(tree);
    }
    free(tree);
}

int numberNodes(struct NodeTree* tree){
    if(isTreeEmpty(tree)){
        return 0;
    } else{
        return 1+numberNodes(left(tree))+numberNodes(right(tree));
    }
}

int numberLeaves(struct NodeTree* tree){
    if(isTreeEmpty(tree)){
        return 0;
    }else{
        if(isLeaf(tree)){
            return 1;
        }else{
            return numberLeaves(left(tree))+numberLeaves(right(tree));
        }
    }
}

int numberInternalNodes(struct NodeTree* tree){
    return numberNodes(tree)-numberLeaves(tree);
}

int sumValues(struct NodeTree* tree){
    if(isTreeEmpty(tree)){
        return 0;
    }else{
        return root(tree)+sumValues(left(tree))+sumValues(right(tree));
    }
}

int height(struct NodeTree* tree){
    if(isTreeEmpty(tree)){
        return 0;
    }else{
        if(height(left(tree))<height(right(tree))){
            return 1+height(right(tree));
        } else{
            return 1+height(left(tree));
        }
    }
}

bool belongs(struct NodeTree* tree, int x){
    if(numberRepetitions(tree,x)!=0){
        return true;
    }
    return false;
}

int lastFullLevel(struct NodeTree* tree){
    if(isTreeEmpty(tree)){
        return 0;
    }
    else{
        if(lastFullLevel(right(tree))<lastFullLevel(left(tree))){
            return 1+lastFullLevel(right(tree));
        }else{
            return 1+lastFullLevel(left(tree));
        }
    }
}

void descendants(struct NodeTree* tree, int x){
    if(isTreeEmpty(tree)==false){
        if(root(tree)==x){
            printf("%d  ",root(tree));
            if(!isTreeEmpty(left(tree))){
                descendants(left(tree), root(left(tree)));
            }
            if(!isTreeEmpty(right(tree))){
                descendants(right(tree), root(right(tree)));
            }

        }else{
            descendants(left(tree),x);
            descendants(right(tree),x);
        }
    }
}

struct NodeTree* mirror(struct NodeTree* tree){
    if(isTreeEmpty(tree)==false){
        return bin(mirror(right(tree)),root(tree),mirror(left(tree)));
    }else{
        return createEmptyTree();
    }
}

bool equals(struct NodeTree* tree1,struct NodeTree* tree2){
    if(isTreeEmpty(tree1)==false&&isTreeEmpty(tree2)==false){
        if(root(tree1)!=root(tree2)){
            return false;
        } else{
            return equals(left(tree1),left(tree2))&&equals(right(tree1),right(tree2));
        }
    } else{
        return true;
    }
}

int numberRepetitions(struct NodeTree* tree, int x){
    if(isTreeEmpty(tree)){
        return 0;
    }else{
        if(root(tree)==x){
            return 1+numberRepetitions(left(tree),x)+numberRepetitions(right(tree),x);
        }
        else{
            return numberRepetitions(left(tree),x)+numberRepetitions(right(tree),x);
        }
    }
}

void pathTo(struct NodeTree* tree, int x){
    if(belongs(tree,x)){
        printf("%d  ",root(tree));
    }
    if(belongs(left(tree),x)){
        pathTo(left(tree),x);
    }else {
        if(belongs(right(tree),x)){
            pathTo(right(tree),x);
        }
    }
}

void preorder(struct NodeTree* tree){
    if(isTreeEmpty(tree)==false){
        printf("%d  ",root(tree));
        preorder(left(tree));
        preorder(right(tree));
    }
}

void postorder(struct NodeTree* tree){
    if(isTreeEmpty(tree)==false){
        postorder(left(tree));
        postorder(right(tree));
        printf("%d  ",root(tree));
    }
}

void inorder(struct NodeTree* tree){
    if(isTreeEmpty(tree)==false) {
        inorder(left(tree));
        printf("%d  ", root(tree));
        inorder(right(tree));
    }
}
/*
void BFS(struct NodeTree* tree){
    bool val;
    struct Queue *Q=createEmptyQueue();
    enqueue(Q,root(tree),&val);
    struct NodeTree *B = createEmptyTree();
    while(isQueueEmpty(Q)==false){
        B->value=dequeue(Q,&val);
        if(isTreeEmpty(B)==false){
            printf("%d", root(B));
            enqueue(Q,root(left(B)),&val);
            enqueue(Q,root(right(B)),&val);
        }
    }
    deleteQueue(Q);
    deleteTree(B);
}*/
void BFS(struct NodeTree* tree){
    struct Queue* q = createEmptyQueue();
    bool valid = true;
    enqueue(q, tree, &valid);
    while(!isQueueEmpty(q)){
        struct NodeTree* B = dequeue(q, &valid);
        if(!isTreeEmpty(B)){
            printf("%d  ", root(B));
            enqueue(q,left(B), &valid);
            enqueue(q, right(B), &valid);
        }
    }
}


struct NodeTree* buildTreeFromPreIn(int pre[],int in[],int sp,int ep,int si,int ei) {
    if (si>ei) {
        return NULL;
    }
    struct NodeTree *tree4=bin(createEmptyTree(),pre[sp],createEmptyTree());
    if (sp==ep) {
        return tree4;
    }
    int i=si;
    while (in[i]!=pre[sp]&&i<ei){
        i++;
    }
    return bin(buildTreeFromPreIn(pre,in,sp+1,i,si,i-1),pre[sp],buildTreeFromPreIn(pre,in, ep-ei+i+1, ep, i+1, ei));
}

struct NodeTree* buildTreeFromPostIn(int post[],int in[],int sp,int ep,int si,int ei){
    if (si>ei) {
        return NULL;
    }
    if (sp==ep) {
        return bin(createEmptyTree(),post[ep],createEmptyTree());
    }
    int i=si;
    while (in[i]!=post[ep]&&i<ei){
        i++;
    }
    return bin(buildTreeFromPostIn(post,in,sp,sp+i-1-si,si,i-1),post[ep],buildTreeFromPostIn(post,in,sp-si+i,ep-1,i+1,ei));
}

struct NodeTree* buildTreeFromBFSIn(int bfs[],int in[],int sb,int eb,int si,int ei){
    if (si>ei) {
        return NULL;
    }
    if (sb==eb) {
        return bin(createEmptyTree(),bfs[sb],createEmptyTree());
    }
    int i=si;
    while (in[i]!=bfs[sb]&&i<ei){
        i++;
    }
    int k=0;
    int newBFS[MAX_SIZE]={0};
    for(int j=sb;j<=eb;j++){
        for(int r=si;r<i;r++){
            if (bfs[j]==in[r]){
                newBFS[k]=in[r];
                k++;
                break;
            }
        }
    }

    int k2=0;
    int newBFS2[MAX_SIZE]={0};
    for(int j=sb;j<=eb;j++){
        for(int r=i+1;r<=ei;r++){
            if (bfs[j]==in[r]){
                newBFS2[k2]=in[r];
                k2++;
            }
        }
    }
    return bin(buildTreeFromBFSIn(newBFS,in,0,k,si,i-1),bfs[sb],buildTreeFromBFSIn(newBFS2,in,0,k2,i+1,ei));
}