//David Oguns
//binary tree interface

#pragma once

#include <functional>

template <class T>
bool lessThanDefault(T const &a, T const &b)
{
  return a < b;
}

template <class T, bool(lessThan)(T const &, T const &) = lessThanDefault<T>>
class BinaryTree
{
  public:
    BinaryTree();
    ~BinaryTree();

    //adds an item to the tree, tree interface allows duplicate values -- effectively a multiset
    virtual void put(T const & data) = 0;
    //returns whether or not a given data item is in the tree
    virtual bool contains(T const & data) const = 0;

    //perform a function on every node in dfs order
    void dfs(std::function<void (T const &)>);
    //perform a function on every node in bfs order
    void bfs(std::function<void (T const &)>);

    unsigned int depth();   //returns the depth of the tree

  protected:
    class BinaryTreeNode
    {
      public:
        explicit BinaryTreeNode(T const & data);
        ~BinaryTreeNode();
        
        void setLeft(BinaryTreeNode *node) { left = node; }
        void setRight(BinaryTreeNode *node) { right = node; }
        BinaryTreeNode* getLeft() { return left; }
        BinaryTreeNode* getRight() { return right; }

      private:
        T data;
        BinaryTreeNode  *left;
        BinaryTreeNode  *right;
    };
    BinaryTreeNode      *root;
};

template <class T, bool (lessThan)(T const &, T const &)>
BinaryTree<T, lessThan>::BinaryTree() :
   root(nullptr)  //initialize root to null
{

}

template <class T, bool (lessThan)(T const &, T const &)>
BinaryTree<T, lessThan>::~BinaryTree()
{
  if(root)
  {
    delete root;
    root = nullptr;
  }
}

template <class T, bool (lessThan)(T const &, T const &)>
BinaryTree<T, lessThan>::BinaryTreeNode::BinaryTreeNode(T const & data) :
  data(data),
  left(nullptr),
  right(nullptr)
{ }

template <class T, bool (lessThan)(T const &, T const &)>
BinaryTree<T, lessThan>::BinaryTreeNode::~BinaryTreeNode()
{
  if(left)
  {
    delete left;
    left = nullptr;
  }
  if(right)
  {
    delete right;
    right = nullptr;
  }
}

/*******************************************************************
 *    NOT IMPLEMENTED YET 
 * *****************************************************************/
template <class T, bool (lessThan)(T const &, T const &)>
void BinaryTree<T, lessThan>::dfs(std::function<void (T const &)> func)
{

}


template <class T, bool (lessThan)(T const &, T const &)>
void BinaryTree<T, lessThan>::bfs(std::function<void (T const &)> func)
{

}

