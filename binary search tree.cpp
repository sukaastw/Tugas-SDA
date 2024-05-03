#include <iostream>
#include <climits> // Untuk menggunakan INT_MIN dan INT_MAX
using namespace std;

class Node {
public:
    Node *left;
    Node *right;
    int key;

    Node() {
        left = right = NULL;
    }
};

class BST {
public:
    Node *root;

    BST() {
        root = NULL;
    }

    Node *insertRecursive(int inputKey, Node *currentRoot) {
        if (currentRoot == NULL) {
            Node *newNode = new Node();
            newNode->key = inputKey;
            return newNode;
        }
        if (inputKey < currentRoot->key) {
            currentRoot->left = insertRecursive(inputKey, currentRoot->left);
        } else if (inputKey > currentRoot->key) {
            currentRoot->right = insertRecursive(inputKey, currentRoot->right);
        }

        return currentRoot;
    }
    
    void insert(int inputKey) {
        root = insertRecursive(inputKey, root);
    }
    
    void preOrderTraversal(Node *currentNode) {
        if (currentNode != NULL) {
            cout << currentNode->key << " ";
            preOrderTraversal(currentNode->left);
            preOrderTraversal(currentNode->right);
        }
    }
    
    void inOrderTraversal(Node *currentNode) {
        if (currentNode != NULL) {
            inOrderTraversal(currentNode->left);
            cout << currentNode->key << " ";
            inOrderTraversal(currentNode->right);
        }
    }
    
    void postOrderTraversal(Node *currentNode) {
        if (currentNode != NULL) {
            postOrderTraversal(currentNode->left);
            postOrderTraversal(currentNode->right);
            cout << currentNode->key << " ";
        }
    }
    
    void preOrder() {
        cout << "Pre Order Traversal: ";
        preOrderTraversal(root);
        cout << endl;
    }
    
    void inOrder() {
        cout << "In Order Traversal: ";
        inOrderTraversal(root);
        cout << endl;
    }
    
    void postOrder() {
        cout << "Post Order Traversal: ";
        postOrderTraversal(root);
        cout << endl;
    }
    
    int findMin() {
        return findMin(root);
    }

    int findMin(Node *currentRoot) {
        if (currentRoot == NULL) {
            cout << "BST is empty" << endl;
            return INT_MIN;
        }
        while (currentRoot->left != NULL) {
            currentRoot = currentRoot->left;
        }
        return currentRoot->key;
    }

    int findMax() {
        return findMax(root);
    }

    int findMax(Node *currentRoot) {
        if (currentRoot == NULL) {
            cout << "BST is empty" << endl;
            return INT_MAX;
        }
        while (currentRoot->right != NULL) {
            currentRoot = currentRoot->right;
        }
        return currentRoot->key;
    }
    Node *deleteNode(Node *currentRoot, int key) {
        if (currentRoot == NULL) {
            return currentRoot;
        }
        if (key < currentRoot->key) {
            currentRoot->left = deleteNode(currentRoot->left, key);
        } else if (key > currentRoot->key) {
            currentRoot->right = deleteNode(currentRoot->right, key);
        } else {
            // Node with only one child or no child
            if (currentRoot->left == NULL) {
                Node *temp = currentRoot->right;
                delete currentRoot;
                return temp;
            } else if (currentRoot->right == NULL) {
                Node *temp = currentRoot->left;
                delete currentRoot;
                return temp;
            }

            Node *temp = minValueNode(currentRoot->right);
            currentRoot->key = temp->key; 
            currentRoot->right = deleteNode(currentRoot->right, temp->key);
        }
        return currentRoot;
    }
	
	Node *minValueNode(Node *node) {
        Node *current = node;
        while (current->left != NULL) {
            current = current->left;
        }
        return current;
    }
    
     Node *search(Node *currentRoot, int key) {
        if (currentRoot == NULL || currentRoot->key == key) {
            return currentRoot;
        }
        if (key < currentRoot->key) {
            return search(currentRoot->left, key);
        }
        return search(currentRoot->right, key);
    }
};

int main(int argc, char **argv) {

    BST *bin1 = new BST();

    bin1->insert(6);
    bin1->insert(7);
    bin1->insert(4);
    bin1->insert(8);
    bin1->insert(5);
    bin1->insert(3);

    bin1->preOrder();
    bin1->inOrder();
    bin1->postOrder();

    cout << "Minimum: " << bin1->findMin() << endl;
    cout << "Maximum: " << bin1->findMax() << endl;
    
    cout << "Delete 4" << endl;
    bin1->root = bin1->deleteNode(bin1->root, 4);
    bin1->inOrder();

    cout << "Delete 6" << endl;
    bin1->root = bin1->deleteNode(bin1->root, 6);
    bin1->inOrder();

	int keyToSearch = 5;
    Node *searchResult = bin1->search(bin1->root, keyToSearch);
    if (searchResult != NULL) {
        cout << "Found " << keyToSearch << " in the BST" << endl;
    } else {
        cout << keyToSearch << " not found in the BST" << endl;
    }

    keyToSearch = 10;
    searchResult = bin1->search(bin1->root, keyToSearch);
    if (searchResult != NULL) {
        cout << "Found " << keyToSearch << " in the BST" << endl;
    } else {
        cout << keyToSearch << " not found in the BST" << endl;
    }
    return 0;
}

