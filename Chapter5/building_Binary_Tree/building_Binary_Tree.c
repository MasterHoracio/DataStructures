#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxn 20

typedef struct{
	char word[maxn];
}NodeData;

typedef struct treeNode{
	NodeData data;
	struct treeNode *left;
	struct treeNode *right;
}tNode, *ptrNodeTree;

typedef struct{
	ptrNodeTree root;
}BinaryTree;

ptrNodeTree buildTree(FILE *in){
	char str[maxn];
	fscanf(in, "%s", str);
	if(strcmp(str, "@") == 0)
		return NULL;
	ptrNodeTree node = (ptrNodeTree) malloc(sizeof(tNode));
	strcpy(node -> data.word, str);
	node -> left = buildTree(in);
	node -> right = buildTree(in);
	return node;
}

void visit(ptrNodeTree node){
	printf("%s ",node -> data.word);
}

void preOrder(ptrNodeTree node){
	if(node != NULL){
		visit(node);
		preOrder(node -> left);
		preOrder(node -> right);
	}
}

void inOrder(ptrNodeTree node){
	if(node != NULL){
		inOrder(node -> left);
		visit(node);
		inOrder(node -> right);
	}
}

void postOrder(ptrNodeTree node){
	if(node != NULL){
		postOrder(node -> left);
		postOrder(node -> right);
		visit(node);
	}
}

int main(){
	FILE *in = fopen("input.in", "r");
	BinaryTree bTree;

	bTree.root = buildTree(in);

	printf("pre-order: ");
	preOrder(bTree.root);
	printf("\n");

	printf("in-order: ");
	inOrder(bTree.root);
	printf("\n");

	printf("post-order: ");
	postOrder(bTree.root);
	printf("\n");

	return 0;
}