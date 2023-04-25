#include <iostream>
using namespace std;

struct node {
  int val;
  struct node *left, *right;
};

// Inorder traversal
void inorderTraversal(struct node *root) {

    if (root != NULL) {
        // Traverse the left subtree
        inorderTraversal(root->left);

        // Visit the node
        cout << root->val << " ";

        // Traverse the right subtree
        inorderTraversal(root->right);
    }
}

// Insert a node
struct node* insertNode(node* root, int val) {
    // If the tree is empty, create a new node
    if (root == NULL) {
        return new node({val, NULL, NULL});
    }

    // Otherwise, recur down the tree
    if (val < root->val) {
        root->left = insertNode(root->left, val);
    } else if (val > root->val) {
        root->right = insertNode(root->right, val);
    }

    // Return the (unchanged) node pointer
    return root;
}

// Find the minimum value node
struct node* findMin(struct node* node){
    struct node* current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Deleting a node
struct node *deleteNode(node *root, int val) {
    // Base case
    if (root == NULL) return root;

    // When the val to be deleted is less than the val of the root
    if (val < root->val)
        root->left = deleteNode(root->left, val);

    // When the val to be deleted is greater than the val of the root
    else if (val > root->val)
        root->right = deleteNode(root->right, val);

    // When the val to be deleted equals to the val of the root
    else {
	
        // One child or no child
        if (root->left == NULL)
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // Two children
        else if (root->left != NULL && root->right != NULL){
		
		    struct node* temp = findMin(root->right);
		
		    root->val = temp->val;
		
		    root->right = deleteNode(root->right, temp->val);
		}
    }
    return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  inorderTraversal(root);
}
