//David Oguns
//rb_tree.h

#pragma once

#include "binary_tree.h"

template <class T>
class RedBlackData
{
  public:
    explicit RedBlackData(T const &data);

    T       data;
    bool    is_red; //true if this node is red
};

//template class constructor?
template <class T>
RedBlackData<T>::RedBlackData(T const &data) :
      data(data),
      is_red(false) //TODO: new nodes red or black by default?
{ }

template <class T, bool (lessThan)(T const &, T const &) = lessThanDefault<T>>
bool rbLessThan(RedBlackData<T> const &l, RedBlackData<T> const &r) {
  return lessThan(l.data, r.data);
}

template <class T, bool (lessThan)(T const &, T const &) = lessThanDefault<T>>
class RbTree : public BinaryTree<RedBlackData<T>, rbLessThan<T, lessThan>> 
{
  public:
    typedef BinaryTree<RedBlackData<T>, rbLessThan<T, lessThan>>  BTREE;

    //adds an item to the tree, tree interface allows duplicate values -- effectively a multiset
    virtual void put(T const & data);
    //returns whether or not a given data item is in the tree
    virtual bool contains(T const & data) const;

  private:
    //red-black tree implementation of insert
    void red_back_insert(typename BTREE::BinaryTreeNode *node, T const & data);

  protected:

};

template <class T, bool (lessThan)(T const &, T const &)>
void RbTree<T, lessThan>::put(T const & data)
{
  typename BTREE::BinaryTreeNode node = new BTREE::BinaryTreeNode(data);

  if(!this->root)
  {
    this->root = node; 
  }
  else
  {
    
  }
}

//adds an item to the tree, tree interface allows duplicate values -- effectively a multiset
template <class T, bool (lessThan)(T const &, T const &)>
bool RbTree<T, lessThan>::contains(T const & data) const
{
  return false;
}



