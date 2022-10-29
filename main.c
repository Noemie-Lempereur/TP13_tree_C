#include "tree.h"


int main() {

    struct NodeTree *tree=createEmptyTree();
    preorder(tree);
    struct NodeTree *tree2=bin(tree,67,tree);
    struct NodeTree *tree3=bin(tree2,7,tree);
    struct NodeTree *tree4=bin(tree2,623,tree3);
    struct NodeTree *tree5=bin(tree,89,tree4);
    preorder(tree5);
    printf("\n");
    BFS(tree5);
    printf("\n");
    postorder(tree5);
    printf("\n");
    inorder(tree5);
    printf("\n");
    bool b;
    b=isTreeEmpty(tree);
    printf("%d\n",b);
    b=isTreeEmpty(tree5);
    printf("%d\n",b);
    printf("%d,%d\n",numberNodes(tree),numberNodes(tree5));
    printf("%d,%d\n",numberLeaves(tree),numberLeaves(tree5));
    printf("%d,%d\n",numberInternalNodes(tree),numberInternalNodes(tree5));
    printf("%d,%d\n",sumValues(tree),sumValues(tree5));
    printf("%d,%d\n",height(tree),height(tree5));
    printf("%d,%d\n",belongs(tree5,3),belongs(tree5,67));
    printf("%d,%d\n",lastFullLevel(tree),lastFullLevel(tree5));
    descendants(tree5,67);
    printf("\n");
    descendants(tree5,89);
    printf("\n");
    BFS(tree5);
    BFS((mirror(tree5)));
    b=equals(tree,tree3);
    printf("%d\n",b);
    b=equals(tree2,tree2);
    printf("%d\n",b);
    b=equals(tree2,tree5);
    printf("%d\n",b);
    printf("%d,%d\n",numberRepetitions(tree,3),numberRepetitions(tree5,67));
    pathTo(tree5,67);
    int post[8] = {4,2,7,8,5,6,3,1};
    int pre[8] = {1,2,4,3,5,7,8,6};
    int in[8] = {4,2,1,7,5,8,3,6};
    int bfs[8] = {1,2,3,4,5,6,7,8};
    printf("\n\n\n");
    struct NodeTree* tree123 = buildTreeFromBFSIn(bfs,in,0,7,0,7);
    preorder(tree123);
    printf("\n\n\n");
    postorder(tree123);
    printf("\n\n\n");
    BFS(tree123);
    printf("\n\n\n");
    inorder(tree123);

    return 0;
}
