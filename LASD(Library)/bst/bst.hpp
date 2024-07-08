
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class BST : virtual public ClearableContainer,
              virtual public DictionaryContainer<Data>,
              virtual public BinaryTree<Data>,
              virtual public BinaryTreeLnk<Data>
  {
    // Must extend ClearableContainer,
    //             DictionaryContainer<Data>,
    //             BinaryTree<Data>,
    //             BinaryTreeLnk<Data>

  private:
    // ...

  protected:
    using BinaryTreeLnk<Data>::size;
    using BinaryTreeLnk<Data>::root;

    using typename BinaryTreeLnk<Data>::NodeLnk;

    // ...

  public:
    // Default constructor
    BST() = default;

    /* ************************************************************************ */

    // Specific constructors
    BST(const TraversableContainer<Data> &); // A bst obtained from a TraversableContainer
    BST(MappableContainer<Data> &&);         // A bst obtained from a MappableContainer

    /* ************************************************************************ */

    // Copy constructor
    BST(const BST &);

    // Move constructor
    BST(BST &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    virtual ~BST() = default;

    /* ************************************************************************ */

    // Copy assignment
    BST &operator=(const BST &);

    // Move assignment
    BST &operator=(BST &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const BST &) const noexcept;
    bool operator!=(const BST &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions

    virtual const Data &Min() const; // (concrete function must throw std::length_error when empty)
    virtual Data MinNRemove();       // (concrete function must throw std::length_error when empty)
    virtual void RemoveMin();        // (concrete function must throw std::length_error when empty)

    virtual const Data &Max() const; // (concrete function must throw std::length_error when empty)
    virtual Data MaxNRemove();       // (concrete function must throw std::length_error when empty)
    virtual void RemoveMax();        // (concrete function must throw std::length_error when empty)

    virtual const Data &Predecessor(const Data &) const; // (concrete function must throw std::length_error when not found)
    virtual Data PredecessorNRemove(const Data &);       // (concrete function must throw std::length_error when not found)
    virtual void RemovePredecessor(const Data &);        // (concrete function must throw std::length_error when not found)

    virtual const Data &Successor(const Data &) const; // (concrete function must throw std::length_error when not found)
    virtual Data SuccessorNRemove(const Data &);       // (concrete function must throw std::length_error when not found)
    virtual void RemoveSuccessor(const Data &);        // (concrete function must throw std::length_error when not found)

    /* ************************************************************************ */

    // Specific member function (inherited from BinaryTree)

    using BinaryTreeLnk<Data>::Root; // Override BinaryTree member

    /* ************************************************************************ */

    // Specific member functions (inherited from DictionaryContainer)

    bool Insert(const Data &) override; // Override DictionaryContainer member (Copy of the value)
    bool Insert(Data &&) override;      // Override DictionaryContainer member (Move of the value)
    bool Remove(const Data &) override; // Override DictionaryContainer member

    /* ************************************************************************ */

    // Specific member functions (inherited from TestableContainer)

    bool Exists(const Data &) const noexcept override; // Override TestableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from ClearableContainer)

    using BinaryTreeLnk<Data>::Clear; // Override ClearableContainer member

  protected:
    // Auxiliary functions, if necessary!

    virtual NodeLnk *DetachMin(NodeLnk *&) noexcept;
    virtual NodeLnk *DetachMax(NodeLnk *&) noexcept;

    virtual NodeLnk *Skip2Left(NodeLnk *&) noexcept;
    virtual NodeLnk *Skip2Right(NodeLnk *&) noexcept;

    virtual NodeLnk *&FindPointerToMin(NodeLnk *&) noexcept;                               // Both mutable versions
    virtual const NodeLnk *const &FindPointerToMin(const NodeLnk *const &) const noexcept; // Both unmutable versions
    virtual NodeLnk *&FindPointerToMax(NodeLnk *&) noexcept;                               // Both mutable versions
    virtual const NodeLnk *const &FindPointerToMax(const NodeLnk *const &) const noexcept; // Both unmutable versions

    virtual NodeLnk *&FindPointerTo(NodeLnk *&, const Data &) noexcept;                               // Both mutable versions
    virtual const NodeLnk *const &FindPointerTo(const NodeLnk *const &, const Data &) const noexcept; // Both unmutable versions

    virtual NodeLnk **FindPointerToPredecessor(NodeLnk *&, const Data &) noexcept;                               // Both mutable versions
    virtual const NodeLnk *const *FindPointerToPredecessor(const NodeLnk *const &, const Data &) const noexcept; // Both unmutable versions

    virtual NodeLnk **FindPointerToSuccessor(NodeLnk *&, const Data &) noexcept;                               // Both mutable versions
    virtual const NodeLnk *const *FindPointerToSuccessor(const NodeLnk *const &, const Data &) const noexcept; // Both unmutable versions
  };

  /* ************************************************************************** */

}

#include "bst.cpp"

#endif
