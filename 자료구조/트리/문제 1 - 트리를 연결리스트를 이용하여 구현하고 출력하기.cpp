#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct treeNode {
	int data;
	treeNode* left;
	treeNode* right;
}treeNode;

treeNode* insertNode(int elem, treeNode* left, treeNode* right) {
	treeNode* v = (treeNode*)malloc(sizeof(treeNode));
	v->data = elem;
	v->left = left;
	v->right = right;
	return v;
}

void visit(treeNode* v) {
	printf("%d ", v->data);
}

treeNode* leftChild(treeNode* v) {
	return v->left;
}

treeNode* rightChild(treeNode* v) {
	return v->right;
}

void print(treeNode* v) {
	visit(v);
	if (leftChild(v) != NULL)
		visit(leftChild(v));
	if (rightChild(v) != NULL)
		visit(rightChild(v));
}

int main() {
	int n;
	treeNode* f7 = insertNode(130, NULL, NULL);
	treeNode* f8 = insertNode(80, NULL, NULL);
	treeNode* f6 = insertNode(120, f7, f8);
	treeNode* f4 = insertNode(70, NULL, NULL);
	treeNode* f5 = insertNode(90, NULL, NULL);
	treeNode* f2 = insertNode(30, f4, f5);
	treeNode* f3 = insertNode(50, NULL, f6);
	treeNode* f1 = insertNode(20, f2, f3);
	scanf("%d", &n);
	switch (n) {
	case 1:
		print(f1);
		break;
	case 2:
		print(f2);
		break;
	case 3:
		print(f3);
		break;
	case 4:
		print(f4);
		break;
	case 5:
		print(f5);
		break;
	case 6:
		print(f6);
		break;
	case 7:
		print(f7);
		break;
	case 8:
		print(f8);
		break;
	default:
		printf("-1");
		break;
	}
	return 0;
}
