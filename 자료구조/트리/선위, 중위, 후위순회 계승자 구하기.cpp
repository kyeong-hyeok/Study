#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct treeNode {
	int data;
	treeNode* root;
	treeNode* left;
	treeNode* right;
}treeNode;

treeNode* insertNode(int data, treeNode* left, treeNode* right) {
	treeNode* v = (treeNode*)malloc(sizeof(treeNode));
	v->data = data;
	v->left = left;
	v->right = right;
	if (left != NULL)
		left->root = v;
	if (right != NULL)
		right->root = v;
	return v;
}

void visit(treeNode* v) {
	printf("%c ", v->data);
}

treeNode* leftChild(treeNode* v) {
	return v->left;
}

treeNode* rightChild(treeNode* v) {
	return v->right;
}

void binaryPreOrder(treeNode* v) {
	if (v != NULL) {
		visit(v);
		binaryPreOrder(leftChild(v));
		binaryPreOrder(rightChild(v));
	}
}

void binaryPostOrder(treeNode* v) {
	if (v != NULL) {
		binaryPostOrder(leftChild(v));
		binaryPostOrder(rightChild(v));
		visit(v);
	}
}

void binaryinOrder(treeNode* v) {
	if (v != NULL) {
		binaryinOrder(leftChild(v));
		visit(v);
		binaryinOrder(rightChild(v));
	}
}

treeNode* parent(treeNode* v) {
	return v->root;
}
int isInternal(treeNode* v) {
	return ((v->left != NULL) && (v->right != NULL));
}
int isRoot(treeNode* v) {
	if (v->root == NULL)
		return 1;
	else
		return 0;
}

void invalidNodeException() {
	printf("invalidNodeException\n");
	exit(1);
}

treeNode* preOrderSucc(treeNode* v) {
	if (isInternal(v))
		return leftChild(v);
	treeNode* p = parent(v);
	while (leftChild(p) != v) {
		if (isRoot(p))
			invalidNodeException();
		v = p;
		p = parent(p);
	}
	return rightChild(p);
}

int isExternal(treeNode* v) {
	return ((v->left == NULL) && (v->right == NULL));
}

treeNode* postOrderSucc(treeNode* v) {
	if (isRoot(v))
		invalidNodeException();
	treeNode* p = parent(v);
	if (rightChild(p) == v)
		return p;
	v = rightChild(p);
	while (!isExternal(v))
		v = leftChild(v);
	return v;
}

treeNode* inOrderSucc(treeNode* v) {
	if (isInternal(v)) {
		v = rightChild(v);
		while (isInternal(v))
			v = leftChild(v);
		return v;
	}
	treeNode* p = parent(v);
	while (leftChild(p) != v) {
		if (isRoot(p))
			invalidNodeException();
		v = p;
		p = parent(p);
	}
	return p;
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

treeNode* findID(treeNode* v, int id) {
	if (v != NULL) {
		if (v->data == id) return v;
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
	treeNode* v1 = findID(root, 'I');
	v1 = preOrderSucc(v1);
	printf("%c\n", v1->data);
	treeNode* v2 = findID(root, 'A');
	v2 = inOrderSucc(v2);
	printf("%c\n", v2->data);
	treeNode* v3 = findID(root, 'C');
	v3 = postOrderSucc(v3);
	printf("%c\n", v3->data);
	return 0;
}
