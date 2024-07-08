
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class BinaryTreeLnk : virtual public MutableBinaryTree<Data>
  {
    // Must extend MutableBinaryTree<Data>

  private:
    // ...

  protected:
    using Container::size;

  public:
    using typename BinaryTree<Data>::Node;
    using typename MutableBinaryTree<Data>::MutableNode;

    struct NodeLnk : virtual MutableNode
    { // Must extend MutableNode

    private:
      // ...

    protected:
      // ...

    public:
      NodeLnk *left = nullptr;
      NodeLnk *right = nullptr;
      Data info;

      // Specific contructors
      NodeLnk(const Data &dat) noexcept : info(dat){};
      NodeLnk(Data &&) noexcept;

      // Copy constructor
      NodeLnk(const NodeLnk &nod);

      // Move constructor
      NodeLnk(NodeLnk &&) noexcept;

      // Desturctor specific
      virtual ~NodeLnk();

      // Copy assignment
      NodeLnk &operator=(const NodeLnk &);

      // Move assignment
      NodeLnk &operator=(NodeLnk &&) noexcept;

      // Comparison operator
      bool operator==(const NodeLnk &) const noexcept;
      inline bool operator!=(const NodeLnk &) const noexcept;

      // Specific member functions

      inline const Data &Element() const noexcept override; // Immutable access to the element (concrete function should not throw exceptions)
      inline Data &Element() noexcept override;             // Mutable access to the element (concrete function should not throw exceptions)

      inline bool IsLeaf() const noexcept override;        // (concrete function should not throw exceptions)
      inline bool HasLeftChild() const noexcept override;  // (concrete function should not throw exceptions)
      inline bool HasRightChild() const noexcept override; // (concrete function should not throw exceptions)

      virtual const Node &LeftChild() const override;  // (concrete function must throw std::out_of_range when not existent)
      virtual const Node &RightChild() const override; // (concrete function must throw std::out_of_range when not existent)

      // Specific member functions (MutableNode)

      virtual NodeLnk &LeftChild() override;  // (concrete function must throw std::out_of_range when not existent)
      virtual NodeLnk &RightChild() override; // (concrete function must throw std::out_of_range when not existent)
    };

  public:
    NodeLnk *root = nullptr;

    // Default constructor
    BinaryTreeLnk() = default;

    /* ************************************************************************ */

    // // Specific constructors
    BinaryTreeLnk(const TraversableContainer<Data> &con); // A binary tree obtained from a TraversableContainer
    BinaryTreeLnk(MappableContainer<Data> &&con);         // A binary tree obtained from a MappableContainer

    /* ************************************************************************ */

    // Copy constructor
    BinaryTreeLnk(const BinaryTreeLnk &);

    // Move constructor
    BinaryTreeLnk(BinaryTreeLnk &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    virtual ~BinaryTreeLnk();

    /* ************************************************************************ */

    // Copy assignment
    BinaryTreeLnk &operator=(const BinaryTreeLnk &);

    // Move assignment
    BinaryTreeLnk &operator=(BinaryTreeLnk &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const BinaryTreeLnk &) const noexcept;
    bool operator!=(const BinaryTreeLnk &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from BinaryTree)

    const Node &Root() const override; // Override BinaryTree member (throw std::length_error when empty)

    /* ************************************************************************ */

    // Specific member function (inherited from MutableBinaryTree)

    MutableNode &Root() override; // Override MutableBinaryTree member (throw std::length_error when empty)

    /* ************************************************************************ */

    // Specific member function (inherited from ClearableContainer)

    void Clear() override; // Override ClearableContainer member

    /* ************************************************************************ */
  };

}

#include "binarytreelnk.cpp"

#endif
