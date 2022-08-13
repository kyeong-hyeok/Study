#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct treeNode {
	int id;
	treeNode* left;
	treeNode* right;
}treeNode;

treeNode* leftChild(treeNode* v) {
	return v->left;
}

treeNode* rightChild(treeNode* v) {
	return v->right;
}

void insertNode(treeNode* v, char type, int id) {
	treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
	newNode->id = id;
	newNode->left = NULL;
	newNode->right = NULL;
	if (type == 'L')
		v->left = newNode;
	else if (type == 'R')
		v->right = newNode;
	else {
		printf("check id\n");
		exit(-1);
	}
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

void visit(treeNode* v) {
	printf(" %d", v->id);
}

void binaryPreOrder(treeNode* v) {
	if (v != NULL) {
		visit(v);
		binaryPreOrder(leftChild(v));
		binaryPreOrder(rightChild(v));
	}
}

treeNode* treeBuild() {
	int n, flag = 1, left, right, id;
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d %d", &id, &left, &right);
		if (flag) {
			root->id = id;
			if (left != 0) insertNode(root, 'L', left);
			if (right != 0) insertNode(root, 'R', right);
			flag = 0;
		}
		else {
			treeNode* v = findID(root, id);
			if (left != 0) insertNode(v, 'L', left);
			if (right != 0) insertNode(v, 'R', right);
		}
	}
	return root;
}

void treeSearch(treeNode* root) {
	int n;
	scanf("%d", &n);
	while (n--) {
		char str[100] = "";
		scanf("%s", str);
		treeNode* v = root;
		printf(" %d", v->id);
		for (int i = 0; i < strlen(str); i++) {
			if (str[i] == 'L') v = leftChild(v);
			else if (str[i] == 'R') v = rightChild(v);
			printf(" %d", v->id);
		}
		printf("\n");
	}
}

int main() {
	treeNode* root = treeBuild();
	treeSearch(root);
	return 0;
}
