#include<bits/stdc++.h>
using namespace std;


class Node
{
	public:
	int key;
	Node *left;
	Node *right;
	int height;
};

int maxDepth(Node* node)
{
    if (node == NULL)
        return 0;
    else 
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
 
        /* use the larger one */
        if (lDepth > rDepth)
        {   
            return (lDepth + 1);
        }
        else
        {
            return (rDepth + 1);
        }
    }
}
 
int height(Node *N)
{
	if (N == NULL)
	{
        return 0;
    }
	return N->height;
}

int max(int a, int b)
{
	if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

Node* newNode(int key)
{
	Node* node = new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return(node);
}

Node *rightRotate(Node *y)
{
	Node *x = y->left;
	Node *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	// Return new root
	return x;
}

Node *leftRotate(Node *x)
{
	Node *y = x->right;
	Node *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

Node* insert(Node* node, int key)
{
	/* 1. Perform the normal BST insertion */
	if (node == NULL)
    {
		return (newNode(key));
    }
	if (key < node->key)
    {
		node->left = insert(node->left, key);
    }
	else if (key > node->key)
    {
		node->right = insert(node->right, key);
    }
	else
    {
		return node;
    }
	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left), height(node->right));

	/* 3. Get the balance factor of this ancestor
	node to check whether this node became
	unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, then
	// there are 4 cases

	// Left Left Case
	if (balance > 1 && key < node->left->key)
	{	
        return rightRotate(node);
    }
	// Right Right Case
	if (balance < -1 && key > node->right->key)
    {
		return leftRotate(node);
    }
	// Left Right Case
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

// A utility function to print preorder
// traversal of the tree.
void preOrder(Node *root)
{
	if(root != NULL)
	{
		cout << root->key << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

// Driver Code
int main()
{
    auto *array = new int[1000000];
    // Create a text string, which is used to output the text file
    string filename[] = {"Data_Input_Array_1.txt", "Data_Input_Array_2.txt", "Data_Input_Array_3.txt", "Data_Input_Array_4.txt", "Data_Input_Array_5.txt", "Data_Input_Array_6.txt", "Data_Input_Array_7.txt", "Data_Input_Array_8.txt", "Data_Input_Array_9.txt", "Data_Input_Array_10.txt"};
    freopen("D:/C++HW/Result/AVL_Tree.txt", "w", stdout);
    for (int i = 0 ; i < 10 ; i++)
    {
        // Read from the text file
        ifstream MyReadFile("D:/C++HW/Data/" + filename[i]);
        
        Node *root = NULL;
        // Use a while loop together with the getline() function to read the file line by line
        for (int i = 0 ; (MyReadFile.get()) && i < 1000000 ; ++i) 
        {
            MyReadFile >> array[i];
            root = insert(root, array[i]);
        }
        // Close the file
        MyReadFile.close();
        cout << "The height of AVL tree " << filename[i] << ": " << maxDepth(root) << endl;
    }
}