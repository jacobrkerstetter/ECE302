#include "binary_search_tree.h"

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree()
{
    root = 0;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree(
    const BinarySearchTree<KeyType, ItemType> &rhs)
{
    root = 0;
    clone(rhs.root);
}

// this is an alternative implementation using a stack to simulate the recursion
template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::clone(Node<KeyType, ItemType> *rhs)
{
    Node<KeyType, ItemType> **lhs = &root;

    std::stack<stackvar<KeyType, ItemType>> s;

    stackvar<KeyType, ItemType> rootvar;
    rootvar.rhs = rhs;
    rootvar.lhs = lhs;
    s.push(rootvar);

    while (!s.empty())
    {
        stackvar<KeyType, ItemType> currentvar = s.top();
        s.pop();

        Node<KeyType, ItemType> *curr_rhs = currentvar.rhs;
        Node<KeyType, ItemType> **curr_lhs = currentvar.lhs;

        if (curr_rhs == 0)
            continue;

        // allocate new node and copy contents
        Node<KeyType, ItemType> *temp = new Node<KeyType, ItemType>;
        temp->key = curr_rhs->key;
        temp->data = curr_rhs->data;
        temp->left = 0;
        temp->right = 0;
        *curr_lhs = temp;

        // push left subtree
        currentvar.rhs = curr_rhs->left;
        currentvar.lhs = &((*curr_lhs)->left);
        s.push(currentvar);

        // push right subtree
        currentvar.rhs = curr_rhs->right;
        currentvar.lhs = &((*curr_lhs)->right);
        s.push(currentvar);
    }
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::destroy()
{
    std::stack<Node<KeyType, ItemType> *> s;
    s.push(root);

    while (!s.empty())
    {
        Node<KeyType, ItemType> *curr = s.top();
        s.pop();

        if (curr != 0)
        {
            s.push(curr->left);
            s.push(curr->right);
            delete curr;
        }
    }
    root = 0;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType> &BinarySearchTree<KeyType, ItemType>::
operator=(const BinarySearchTree<KeyType, ItemType> &rhs)
{
    if (&rhs == this)
        return *this;

    destroy();

    root = 0;
    clone(rhs.root);

    return *this;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::~BinarySearchTree()
{
    destroy();
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::insert(
    const KeyType &key, const ItemType &item)
{
    // create temp node to assign
    Node<KeyType, ItemType> *temp = new Node<KeyType, ItemType>;
    temp -> data = item;
    temp -> key = key;

    if (isEmpty())
    {
        root = temp;
        temp = nullptr;
        return true;
    }

    // search for node
    Node<KeyType, ItemType> *parent, *curr;
    search(key, curr, parent);

    if (key < curr -> key)
        curr -> left = temp;
    else if (key > curr -> key)
        curr -> right = temp;
    else {
        temp = nullptr;
        return false;
    }

    temp = nullptr;

    return true;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::isEmpty()
{
    return (root == 0);
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::retrieve(
    const KeyType &key, ItemType &item)
{
    Node<KeyType, ItemType> *curr;
    Node<KeyType, ItemType> *curr_parent;
    search(key, curr, curr_parent);

    if (curr == 0)
        return false;

    if (curr->key == key)
    {
        item = curr->data;
        return true;
    }

    return false;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::remove(KeyType key)
{
    if (isEmpty())
        return false; // empty tree

    Node<KeyType, ItemType> *parent, *curr;
    search(key, curr, parent);

    if (curr -> key != key) return false; // key not found

    // case one thing in the tree
    if (!(root -> left) && !(root -> right)) {
        delete root;
        root = nullptr;
    }
    // case, found deleted item at leaf
    else if (!(curr -> left) && !(curr -> right)) {
        // unlink from tree
        if (parent -> left == curr) parent -> left = nullptr;
        else parent -> right = nullptr;

        // deallocate memory
        delete curr;
        curr = nullptr;
    }
    // case, item to delete has only a right child
    else if (curr -> right && !(curr -> left)) {
        // attach parent to right subtree
        if (parent)
            if (parent -> right == curr) parent -> right = curr -> right;
            else parent -> left = curr -> right;
        else
            root = curr -> right;

        // delete node and set right to null
        curr -> right = nullptr;
        delete curr;
        curr = nullptr;
    }
    // case, item to delete has only a left child
    else if (curr -> left && !(curr -> right)) {
        // attach parent to right subtree
        if (parent)
            if (parent -> right == curr) parent -> right = curr -> left;
            else parent -> left = curr -> left;
        else
            root = curr -> left;

        // delete node and set right to null
        curr -> left = nullptr;
        delete curr;
        curr = nullptr;
    }
    // case, item to delete has two children
    else if (curr -> left && curr -> right) {
        // find inorder successor
        Node<KeyType, ItemType> *successor, *sucParent;
        inorder(curr, successor, sucParent);

        // swap successor with curr key and item
        KeyType tempKey;
        ItemType tempData;

        tempKey = successor -> key;
        successor -> key = curr -> key;
        curr -> key = tempKey;

        tempData = successor -> data;
        successor -> data = curr -> data;
        curr -> data = tempData;

        // delete successor
        delete successor;
        successor = nullptr;
    }

    return true;
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inorder(Node<KeyType, ItemType> *curr,
                                                  Node<KeyType, ItemType> *&in, Node<KeyType, ItemType> *&parent)
{
    // move right once
    curr = curr -> right;
    
    // set in to curr
    if (!(curr->left))
    {
        in = curr;
        return;
    }

    inorder(curr->left, in, curr);
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::search(KeyType key,
                                                 Node<KeyType, ItemType> *&curr, Node<KeyType, ItemType> *&parent)
{
    curr = root;
    parent = 0;

    if (isEmpty())
        return;

    while (true)
    {
        if (key == curr->key) break;
        else if (key < curr->key)
        {
            if (curr->left != 0)
            {
                parent = curr;
                curr = curr->left;
            }
            else break;
        }
        else
        {
            if (curr->right != 0)
            {
                parent = curr;
                curr = curr->right;
            }
            else break;
        }
    }
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::treeSort(ItemType arr[], int size)
{
    // make sure tree is empty
    destroy();

    // insert all items into the tree while checking for dupes
    for (int i = 0; i < size; i++)
        if (!retrieve(arr[i], arr[i]))
            insert(arr[i], arr[i]);

    // overwrite input array values with sorted values
    Node<KeyType, ItemType> *curr = root;
    traverse(curr, arr, 0);
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::traverse(Node<KeyType, ItemType>* curr, ItemType arr[], int i) {
    if (curr) {
        traverse(curr -> left, arr, i);
        std::cout << curr -> key << std::endl;
        arr[i++] = curr -> key;
        traverse(curr -> right, arr, i);
    }
}