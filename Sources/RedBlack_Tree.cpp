// Implementing Red-Black Tree in C++

#include<bits/stdc++.h>
using namespace std;

struct Node 
{
  int data;
  Node *parent;
  Node *left;
  Node *right;
  int color;
};

class RedBlackTree 
{
    public:
        Node* root;
        Node* TNULL;

        void initializeNULLNode(Node* node, Node* parent) 
        {
                node->data = 0;
                node->parent = parent;
                node->left = nullptr;
                node->right = nullptr;
                node->color = 0;
        }

        // Preorder
        void preOrder(Node* node) 
        {
            if (node != TNULL) 
            {
            cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
            }
        }

        Node* searchTree(Node* node, int key) 
        {
            if (node == TNULL || key == node->data) 
            {
            return node;
            }
            if (key < node->data) 
            {
            return searchTree(node->left, key);
            }
            return searchTree(node->right, key);
        }

        void rbTransplant(Node* u, Node* v) 
        {
            if (u->parent == nullptr) 
            {
            root = v;
            } 
            else if (u == u->parent->left) 
            {
            u->parent->left = v;
            } 
            else 
            {
            u->parent->right = v;
            }
            v->parent = u->parent;
        }

        // For balancing the tree after insertion
        void insertFix(Node* k) 
        {
            Node* u;
            while (k->parent->color == 1) {
            if (k->parent == k->parent->parent->right) 
            {
                    u = k->parent->parent->left;
                    if (u->color == 1)
                    {
                        u->color = 0;
                        k->parent->color = 0;
                        k->parent->parent->color = 1;
                        k = k->parent->parent;
                    } 
                    else 
                    {
                        if (k == k->parent->left) 
                        {
                            k = k->parent;
                            rightRotate(k);
                        }
                        k->parent->color = 0;
                        k->parent->parent->color = 1;
                        leftRotate(k->parent->parent);
                    }
            } 
            else 
            {
                    u = k->parent->parent->right;

                    if (u->color == 1) 
                    {
                        u->color = 0;
                        k->parent->color = 0;
                        k->parent->parent->color = 1;
                        k = k->parent->parent;
                    } 
                    else 
                    {
                        if (k == k->parent->right) 
                        {
                            k = k->parent;
                            leftRotate(k);
                        }
                        k->parent->color = 0;
                        k->parent->parent->color = 1;
                        rightRotate(k->parent->parent);
                    }
            }
            if (k == root)
            {
                    break;
            }
            }
            root->color = 0;
        }

        RedBlackTree() 
        {
            TNULL = new Node;
            TNULL->color = 0;
            TNULL->left = nullptr;
            TNULL->right = nullptr;
            root = TNULL;
        }


        void leftRotate(Node* x)
        {
            Node* y = x->right;
            x->right = y->left;
            if (y->left != TNULL) 
            {
                y->left->parent = x;
            }
            y->parent = x->parent;
            if (x->parent == nullptr) 
            {
                this->root = y;
            } 
            else if (x == x->parent->left) 
            {
                x->parent->left = y;
            } 
            else 
            {
                x->parent->right = y;
            }
            y->left = x;
            x->parent = y;
        }

        void rightRotate(Node* x) 
        {
            Node* y = x->left;
            x->left = y->right;
            if (y->right != TNULL) 
            {
                y->right->parent = x;
            }
            y->parent = x->parent;
            if (x->parent == nullptr) 
            {
                this->root = y;
            } 
            else if (x == x->parent->right) 
            {
                x->parent->right = y;
            } 
            else 
            {
                x->parent->left = y;
            }
            y->right = x;
            x->parent = y;
        }

    // Inserting a node
        void insert(int key) 
        {
            Node* node = new Node;
            node->parent = nullptr;
            node->data = key;
            node->left = TNULL;
            node->right = TNULL;
            node->color = 1;

            Node* y = nullptr;
            Node* x = this->root;

            while (x != TNULL) 
            {
                y = x;
                if (node->data < x->data) 
                {
                    x = x->left;
                } 
                else 
                {
                    x = x->right;
                }
            }

            node->parent = y;
            if (y == nullptr) 
            {
                root = node;
            } 
            else if (node->data < y->data) 
            {
                y->left = node;
            } 
            else 
            {
                y->right = node;
            }

            if (node->parent == nullptr) 
            {
                node->color = 0;
                return;
            }

            if (node->parent->parent == nullptr) 
            {
                return;
            }
            insertFix(node);
        }
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

int main() 
{
    auto *array = new int[1000000];
    // Create a text string, which is used to output the text file
    string filename[] = {"Data_Input_Array_1.txt", "Data_Input_Array_2.txt", "Data_Input_Array_3.txt", "Data_Input_Array_4.txt", "Data_Input_Array_5.txt", "Data_Input_Array_6.txt", "Data_Input_Array_7.txt", "Data_Input_Array_8.txt", "Data_Input_Array_9.txt", "Data_Input_Array_10.txt"};
    freopen("D:/C++HW/Result/BlackRed_Tree.txt", "w", stdout);
    for (int i = 0 ; i < 10 ; i++)
    {
        RedBlackTree bst;
        // Read from the text file
        ifstream MyReadFile("D:/C++HW/Data/" + filename[i]);
        
        Node *root = NULL;
        // Use a while loop together with the getline() function to read the file line by line
        for (int i = 0 ; (MyReadFile.get()) && i < 1000000 ; ++i) 
        {
            MyReadFile >> array[i];
            bst.insert(array[i]);
        }
        // Close the file
        MyReadFile.close();
        cout << "The height of Red-Black tree " << filename[i] << ": " << maxDepth(bst.root) << endl;
    }
}