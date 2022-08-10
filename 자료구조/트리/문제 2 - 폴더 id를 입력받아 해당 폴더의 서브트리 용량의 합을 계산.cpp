#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int gFolderSize = 0;

typedef struct treeNode {
	int data;
	int id;
	treeNode* left;
	treeNode* right;
}treeNode;

treeNode* insertNode(int id, int data, treeNode* left, treeNode* right) {
	treeNode* v = (treeNode*)malloc(sizeof(treeNode));
	v->id = id;
	v->data = data;
	v->left = left;
	v->right = right;
	return v;
}

void visit_sum(treeNode* v) {
	int e = v->data;
	gFolderSize += e;
}

treeNode* leftChild(treeNode* v) {
	return v->left;
}

treeNode* rightChild(treeNode* v) {
	return v->right;
}


void binaryPostOrder(treeNode* v) {
	if (v != NULL) {
		binaryPostOrder(leftChild(v));
		binaryPostOrder(rightChild(v));
		visit_sum(v);
	}
}


treeNode* treeBuild() {
	treeNode* f7 = insertNode(7, 130, NULL, NULL);
	treeNode* f8 = insertNode(8, 80, NULL, NULL);
	treeNode* f6 = insertNode(6, 120, f7, f8);
	treeNode* f4 = insertNode(4, 70, NULL, NULL);
	treeNode* f5 = insertNode(5, 90, NULL, NULL);
	treeNode* f2 = insertNode(2, 30, f4, f5);
	treeNode* f3 = insertNode(3, 50, NULL, f6);
	treeNode* f1 = insertNode(1, 20, f2, f3);
	return f1;
}

treeNode* findID(treeNode* v, int id) {
	if (v != NULL) {
		if (v->id == id) return v;
		treeNode* p = NULL;
		p = findID(leftChild(v), id);
		if (p != NULL) return p;
		p = findID(rightChild(v), id);
		if (p != NULL) return p;
	}
	return NULL;
}

int main() {
	int id;
	treeNode* root = treeBuild();
	scanf("%d", &id);
	treeNode* p = findID(root, id);
	if (p != NULL) {
		binaryPostOrder(p);
		printf("%d", gFolderSize);
	}
	else printf("-1");
	return 0;
}
