// Program for different tree traversals...

#include <stdio.h>
#include <stdlib.h>

  // Node Structure Defination...
 // A binary tree node has data, pointer to left child and a pointer to right child...

struct node {
	int data;
	struct node* left;
	struct node* right;
};

// Helper function that allocates a new node with the given data and store NULL in left and right pointers...

struct node* newNode(int data){
	struct node* node
		= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

// Given a binary tree, print its nodes according to the "bottom-up" postorder traversal...
// Post Order = [ Left, Right, Root ]...

void printPostorder(struct node* node){
	if (node == NULL)
		return;

	// first recursion on left subtree...
	printPostorder(node->left);

	// then recursion on right subtree...
	printPostorder(node->right);

	// now print the node data...
	printf("%d ", node->data);
}

// Given a binary tree, print its nodes according to the InOrder traversal...
// InOrder = [Left, Root, Right]...

void printInorder(struct node* node){
	if (node == NULL)
		return;

	// first recursion on left child
	printInorder(node->left);

	// then print the data of node
	printf("%d ", node->data);

	// now recursion on right child
	printInorder(node->right);
}

// Given a binary tree, print its nodes according to the PreOrder traversal...
// PreOrder = [Root, Right, Left]...

void printPreorder(struct node* node){
	if (node == NULL)
		return;

	// first print data of node...
	printf("%d ", node->data);

	// then recursion on left subtree ...
	printPreorder(node->left);

	// now recursion on right subtree...
	printPreorder(node->right);
}

// Main Function to test the above functions...

int main(){

	struct node* root = newNode(1);  // Assign values to the Nodes of a Binary Tree...
	root->left = newNode(6);
	root->right = newNode(4);
	root->left->left = newNode(3);
	root->left->right = newNode(8);
	root->right->right = newNode(15);

	printf("\nPre-Order Traversal of Binary Tree is ??? \n");  // Printing function for PreOrder Traversal...
	printPreorder(root);

	printf("\nIn-Order Traversal of Binary Tree is??? \n");    // Printing function for PostOrder Traversal...
	printInorder(root);

	printf("\nPost-Order Traversal of Binary Tree is??? \n");   // Printing function for InOrder Traversal...
	printPostorder(root);

	getchar();        // getCharacter function/method Called...
	return 0;
}                 // Program Close...
