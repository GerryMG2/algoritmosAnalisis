

#include <iostream>
#include <stdexcept>
#include "quicksort.h"

using namespace std;

template <class T>
struct nodeBST
{
    int key;
    T val;

    nodeBST<T> *left;
    nodeBST<T> *rigth;
};

template <class T>
nodeBST<T> *newNode(int key, T value)
{
    nodeBST<T> *temp = new nodeBST<T>;
    temp->key = key;
    temp->val = value;
    temp->left = temp->right = NULL;
    return temp;
}

template <class T>
nodeBST<T> *insert(nodeBST<T> *node, int key, T val)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key, val);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key, val);
    else if (key > node->key)
        node->right = insert(node->right, key, val);

    /* return the (unchanged) node pointer */
    return node;
}

template <class T>
nodeBST<T> *minValueNode(nodeBST<T> *node)
{
    nodeBST<T> *current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

template <class T>
nodeBST<T> *deleteNode(nodeBST<T> *root, int key)
{
    // base case
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            nodeBST<T> *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            nodeBST<T> *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        nodeBST<T> *temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;
        root->val = temp->val;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

template <class B>
class bst
{
private:
    nodeBST<B> *root;
    /* data */
public:
    static bool isValidBST(nodeBST<B> *test)
    {
        if (test->left && test->rigth)
        {
            return test->key > test->left->key && isValidBST(test->left) && test->key < test->rigth->key && isValidBST(test->rigth);
        }
        else
        {
            if (test->left)
            {
                //left exist
                return test->key > test->left->key && isValidBST(test->left);
            }
            else
            {
                if (test->rigth)
                {
                    //rigt exist
                    return test->key < test->rigth->key && isValidBST(test->rigth);
                }
                else
                {
                    return true;
                }
            }
        }
    }



    static nodeBST<B> *sortedArrayToBST(int arr[],
                                   int start, int end)
    {
        /* Base Case */
        if (start > end)
            return NULL;

        
        int mid = (start + end) / 2;
        nodeBST<B> *root = newNode(arr[mid]);

        
        root->left = sortedArrayToBST(arr, start,
                                      mid - 1);

        
        root->right = sortedArrayToBST(arr, mid + 1, end);

        return root;
    }

    static bst<B>(int size, int list[])
    {
        bst<B> ret = new bst<B>;
        for (int i = 0; i < size; i++)
        {
            ret.insert(list[i]);
        }
        return ret;
    }

    static bstBalanced<B>(int size, int list[])
    {
        int arr[size] = list;
        bst<B> aux = new bst<B>;
        quickSort(arr,0,size -1);
        aux = sortedArrayToBST(arr,0,size -1);

        
        return aux;
    }

    bst(/* args */)
    {
        root = new nodeBST<B>;
    }

    insert(int key, B val)
    {
        this->root = insert<B>(root, key, val);
    }

    delete (int key)
    {
        this->root = deleteNode<B>(root, key);
    }

    ~bst()
    {
    }
};
