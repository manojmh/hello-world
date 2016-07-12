#include <iostream>
using namespace std;

typedef struct node
{
	int key;
	struct node *left, *right;
}Node;

// A utility function to create a new BST node
struct node *newNode(int item)
{
	struct node *temp = new Node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

/* A utility function to insert a new node with given key in BST */
Node *insert(Node *root, int key)
{
    Node *temp = newNode(key);
    if(!root) return temp;
    
    Node *prev = NULL, *cur = root;
    while(cur)
    {
        prev = cur;
        if(key < cur->key)
            cur = cur->left;
        else
            cur = cur->right;
    }
    if(key < prev->key)
        prev->left = temp;
    else
        prev->right = temp;
    return root;
}

// A utility function to do inorder traversal of BST
void inOrder(Node *root)
{
	if (root != NULL)
	{
		inOrder(root->left);
		cout << root->key << " ";
		inOrder(root->right);
	}
}

// Driver Program to test above functions
int main()
{
	/* Let us create following BST
		 50
	   /   \
	  30   70
	 / \  / \
	20 40 60 80 */
	
	struct node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

    cout << "inOrder\n";
	inOrder(root);
	cout << endl;

	return 0;
}
