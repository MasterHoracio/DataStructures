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
}tNode, *TreeNodePtr;

typedef struct{
	TreeNodePtr root;
}BinaryTree;

TreeNodePtr newTreeNode(NodeData d){
	TreeNodePtr node = (TreeNodePtr) malloc(sizeof(tNode));
	node -> data = d;
	node -> left = node -> right = NULL;
	return node;
}

void findOrInsert(BinaryTree btree, NodeData d){
	TreeNodePtr curr = btree.root;
	int cmp;

	while((cmp = strcmp(d.word, curr->data.word)) != 0){
		if(cmp < 0){//esta a la izquierda
			if(curr -> left == NULL){
				curr -> left = newTreeNode(d);
				break;
			}
			curr = curr -> left;
		}else{//esta a la derecha
			if(curr -> right == NULL){
				curr -> right = newTreeNode(d);
				break;
			}
			curr = curr -> right;
		}
	}
}

void visit(TreeNodePtr node){
	printf("%s ",node->data.word);
}

void preOrder(TreeNodePtr node){
	if(node != NULL){
		visit(node);
		preOrder(node -> left);
		preOrder(node -> right);
	}
}

int main(){
	BinaryTree btree;
	char str[maxn];
	NodeData temp;

	btree.root = NULL;

	while(scanf("%s",str) && (strcmp(str,"fin") != 0)){
		if(btree.root == NULL){
			strcpy(temp.word, str);
			btree.root = newTreeNode(temp);
		}else{
			strcpy(temp.word, str);
			findOrInsert(btree, temp);
		}
	}

	printf("Pre-order: ");
	preOrder(btree.root);
	printf("\n");

	/*
		input: hola mi nombre es horacio fin
		output: hola es mi horacio nombre
	*/

	return 0;
}