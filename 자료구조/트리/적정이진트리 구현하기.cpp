#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct treeNode {
	int elem;
	treeNode* left;
	treeNode* right;
}treeNode;

treeNode* insertNode(int elem, treeNode* left, treeNode* right) {
	treeNode* v = (treeNode*)malloc(sizeof(treeNode));
	v->elem = elem;
	v->left = left;
	v->right = right;
	return v;
}

treeNode* treeBuild() {
	treeNode* n1 = insertNode('H', NULL, NULL);
	treeNode* n2 = insertNode('I', NULL, NULL);
	treeNode* n3 = insertNode('E', n1, n2);
	treeNode* n4 = insertNode('D', NULL, NULL);
	treeNode* n5 = insertNode('B', n4, n3);
	treeNode* n6 = insertNode('F', NULL, NULL);
	treeNode* n7 = insertNode('G', NULL, NULL);
	treeNode* n8 = insertNode('C', n6, n7);
	treeNode* n9 = insertNode('A', n5, n8);
	return n9;
}

void visit(treeNode* v) {
	printf("%c ", v->elem);
}

int isInternal(treeNode* v) {
	return ((v->left != NULL) && (v->right != NULL));
}

treeNode* leftChild(treeNode* v) {
	return v->left;
}

treeNode* rightChild(treeNode* v) {
	return v->right;
}

void binaryPreOrder(treeNode* v) {
	visit(v);
	if (isInternal(v)) {
		binaryPreOrder(leftChild(v));
		binaryPreOrder(rightChild(v));
	}
}
int main() {
	treeNode* root = treeBuild();
	binaryPreOrder(root);
	// A B D E H I C F G
	return 0;
}
