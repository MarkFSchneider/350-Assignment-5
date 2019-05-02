#include <iostream>
#include "TreeNode.h"
using namespace std;

template <class T>
class GenBST
{
public:
  GenBST()
  {
    root = NULL;
  }

  virtual ~GenBST()
  {
    //iterate and delete nodes
  }

  void insert(int key, T data)
  {
    //check if value exists. If not:
    if(!contains(key))
    {
    TreeNode<T> *node = new TreeNode<T>(key, data);

    if(isEmpty())
    {
      root = node;
      return;
    }

    if(!isEmpty())
    {
      TreeNode<T> *curr = root;
      TreeNode<T> *parent;

      while (true)
      {
        parent = curr;
        if(key < curr -> key)
        {
          curr = curr -> left;

          if(curr == NULL)
          {
            parent -> left = node;
            break;
          }
        }
        else
        {
          curr = curr -> right;

          if(curr == NULL)
          {
            parent -> right = node;
            break;
          }
        }

      }
    }
  }
  }

  bool contains(int key)
  {
    if(isEmpty())
    {
      return false;
    }
    else
    {
      TreeNode<T> *curr = root;
      while(curr != NULL && curr -> key != key)
      {
        if(key < curr -> key)
        {
          if(curr -> left == NULL)
          {
            return false;
          }
          curr = curr -> left;

        }
        else
        {
          if(curr -> right == NULL)
          {
            return false;
          }
          curr = curr -> right;
        }

        if(curr == NULL)
        {
          return false;
        }

      }

    }
    return true;
  }

  bool deleteNode(int key)
  {
    if(isEmpty())
  {
    return false;
  }

  //check if key exists before continuing

  TreeNode<T> *curr = root;
  TreeNode<T> *parent = root;
  bool isLeft = true;

  while(curr -> key != key)
  {
    parent = curr;
    if(key < curr -> key)
    {
      isLeft = true;
      curr = curr -> left;
    }
    else
    {
      isLeft = false;
      curr = curr -> right;
    }

    if(curr == NULL)
    {
      return false;
    }
  }

  if(curr -> left == curr -> right) //Left and right are only equal when they are NULL, Therefore this is a leaf node
  {
    if(curr == root)
    {
      root = NULL;
    }
    else if(isLeft)
    {
      parent -> left = NULL;

    }
    else //is right
    {
      parent -> right = NULL;
    }
  }
  else if(curr -> right == NULL) //No right child
  {
    if(curr == root)
    {
      root = curr -> left;
    }
    else if(isLeft)
    {
      parent -> left = curr -> left;
    }
    else
    {
      parent -> right = curr -> left;
    }

  }
  else if(curr -> left == NULL) //No right child
  {
    if(curr == root)
    {
      root = curr -> right;
    }
    else if(isLeft)
    {
      parent -> left = curr -> right;
    }
    else
    {
      parent -> right = curr -> right;
    }

  }
  else //two children
  {
    TreeNode<T> *successor = getSuccessor(curr);

    if(curr == root)
    {
      root = successor;
    }
    else if(isLeft)
    {
      parent -> left = successor;
    }
    else
    {
      parent -> right = successor;
    }

    successor -> left = curr -> left;
    return true;
  }

}

  bool isEmpty()
  {
    return (root == NULL);
  }

  TreeNode<T>* getMin()
  {

  }

  TreeNode<T>* getMax()
  {

  }

  TreeNode<T>* getSuccessor(TreeNode<T>* d)
  {
    TreeNode<T> *sp = d; //parent of successor
    TreeNode<T> *successor = d;
    TreeNode<T> *curr = d -> right;

    while(curr != NULL)
    {
      sp = successor;
      successor = curr;
      curr = curr -> left;
    }

    if(successor != d -> right)
    {
      sp -> left = successor -> right;
      successor -> right = d -> right;
    }

    return successor;
  }



  void printTree()
  {
    recPrint(root);
  }

  void recPrint(TreeNode<T> *node)
  {
    //inorder
    if(node == NULL)
    {
      return;
    }

    recPrint(node -> left);
    cout << node -> key << endl;
    recPrint(node -> right);
  }

  string toString()
  {
    return stringPrint(root);
  }

  string stringPrint(TreeNode<T> *node)
  {
    //prints contents of tree to a string, as long as data has a toString() function
    //modified recPrint
    string out = "";
    //inorder
    if(node == NULL)
    {
      return "";
    }

    out += stringPrint(node -> left);
    out += node -> data.toString();
    out += '\n';
    out += stringPrint(node -> right);

    return out;
  }

  TreeNode<T>* getRoot()
  {
    return root;
  }

  T* getNode(int key)
  {
    //returns a pointer to a node, useful for modifying information inside the tree
    if(contains(key))
    {
      TreeNode<T> *curr = root;
      while(curr != NULL && curr -> key != key)
      {
        if(curr -> key < key)
        {
          curr = curr -> right;
        }
        else // curr > key
        {
          curr = curr -> left;
        }
      }
      return &curr -> data;
    }
    else
    {
      throw "ID not found";
    }

  }



private:
  TreeNode<T> *root;


};
