#include <bits/stdc++.h>
using namespace std;

// Node class template for binary tree
template<typename T>
class Node {
public:
    T data;
    Node<T>* left, *right;

    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};

template<typename T>
class BinaryTree {

private:

    Node<T>* root; // pointer to the root node

    // recursive function to delete a node from the tree
    Node<T>* deleteRecursive(Node<T>* current, T value) {
        if(current == nullptr) return nullptr;

        if(current->data==value) {
            // if node is a leaf, delete it
            if(current->left==nullptr && current->right==nullptr) {
                delete current;
                return nullptr;
            }
            // if node has only right child
            if(current->left==nullptr) {
                Node<T>* temp = current->right;
                delete current;
                return temp; // this will be assigned to previous node's right or left, depend on else statement
            }
            // if node has only left child
            if(current->right==nullptr) {
                Node<T>* temp = current->left;
                delete current;
                return temp;
            }
            // if node has two children, replace with successor
            Node<T>* successor = findMin(current->right);
            current->data = successor->data;
            current->right=deleteRecursive(current->right, successor->data);

        } else {
            // recursively search left and right subtree
            current->left=deleteRecursive(current->left, value);
            current->right=deleteRecursive(current->right, value);
        }
        return current;
    }

    // minimum node in right subtree
    Node<T>* findMin(Node<T>* node) {
        while(node && node->left!=nullptr) node=node->left;
        return node;
    }

    // return searchRecursive(current->left, value) || searchRecursive(current->right, value); 
    // --> without return, cannot get the result if true or false returned in 30th, 31th recursion
    // That's the reason why recursive function call needs return
    bool searchRecursive(Node<T>* current, T value) {
        if(current==nullptr) return false;
        if(current->data==value) return true;
        return searchRecursive(current->left, value) || searchRecursive(current->right, value);
    }

    // function for recursive inorder traversal of the tree
    void inorderRecursive(Node<T>* node) {
        if(node==nullptr) return;
        inorderRecursive(node->left);
        cout << node->data << ' ';
        inorderRecursive(node->right);
    }

    // function for recursive preorder traversal of the tree
    void preorderRecursive(Node<T>* node) {
        if(node==nullptr) return;
        cout<<node->data<<' ';
        preorderRecursive(node->left);
        preorderRecursive(node->right);
    }

    // function for recursive postorder traversal of the tree
    void postorderRecursive(Node<T>* node) {
        if(node==nullptr) return;
        postorderRecursive(node->left);
        postorderRecursive(node->right);
        cout<< node->data <<' ';
    }

    // function for level order traversal (BFS)
    void levelorderRecursive() {
        if(root==nullptr) return;

        queue<Node<T>*> q;
        q.push(root);

        while(!q.empty()) {
            Node<T>* current = q.front();
            q.pop();

            cout<< current->data << ' ';

            if(current->left!=nullptr) q.push(current->left);
            if(current->right!=nullptr) q.push(current->right);
        }
        cout<< '\n';
    }

public:

    // constructor to initialize the tree
    BinaryTree() : root(nullptr){}

    // function to insert a new node (level-order)
    void insertNode(T value) {
        Node<T>* newNode = new Node<T>(value);

        if(root==nullptr) {
            root=newNode;
            return;
        }

        queue<Node<T>*> q;
        q.push(root);

        while(!q.empty()) {
            Node<T>* current=q.front();
            q.pop();

            if(current->left==nullptr) {
                current->left=newNode;
                return;
            } else q.push(current->left);

            if(current->right==nullptr) {
                current->right=newNode;
                return;
            } else q.push(current->right);
        }
    }

    // wrapper functions for traversal and search
    void inorder() { inorderRecursive(root); cout << '\n'; }
    void preorder() { preorderRecursive(root); cout << '\n'; }
    void postorder() { postorderRecursive(root); cout << '\n'; }
    void levelorder() { levelorderRecursive(); }
    bool search(T value) { return searchRecursive(root, value); }
    void deleteNode(T value) { root = deleteRecursive(root, value); }
};

int main() {
    BinaryTree<int> tree;

    // Insert nodes into the tree
    tree.insertNode(1);
    tree.insertNode(2);
    tree.insertNode(3);
    tree.insertNode(4);
    tree.insertNode(5);

    cout << "Inorder: "; tree.inorder();
    cout << "Preorder: "; tree.preorder();
    cout << "Postorder: "; tree.postorder();
    cout << "Levelorder: "; tree.levelorder();

    cout << "search 4: " << (tree.search(4) ? "Found" : "Not Found") << endl;
    tree.deleteNode(3);
    cout << "Inorder after delete 3: "; tree.inorder();
}