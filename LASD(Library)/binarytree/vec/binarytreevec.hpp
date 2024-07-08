
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class BinaryTreeVec : virtual protected Vector<Data>,
                        virtual public MutableBinaryTree<Data>
  {

  private:
    // ...

  protected:
    using Vector<Data>::size;
    using Vector<Data>::Elements;

  public:
    using typename BinaryTree<Data>::Node;
    using typename MutableBinaryTree<Data>::MutableNode;

    friend class BinaryTree<Data>;

    struct NodeVec : virtual MutableNode
    { // Must extend MutableNode
      BinaryTreeVec *Tree = nullptr;

      NodeVec() = default;

      virtual ~NodeVec() = default;

      // Specific member functions (inherited from Node)
      inline const Data &Element() const noexcept override;
      inline Data &Element() noexcept override;

      inline bool IsLeaf() const noexcept override;
      inline bool HasLeftChild() const noexcept override;
      inline bool HasRightChild() const noexcept override;

      virtual const Node &LeftChild() const override;
      virtual const Node &RightChild() const override;

      // Specific member functions (inherited from MutableNode)
      virtual MutableNode &LeftChild() override;
      virtual MutableNode &RightChild() override;

    protected:
      // Auxiliar function
      virtual ulong Index() const noexcept;
    };

    NodeVec *Nodes = nullptr;

  public:
    // Default constructor
    BinaryTreeVec() = default;

    /* ************************************************************************ */

    // Specific constructors
    BinaryTreeVec(const TraversableContainer<Data> &); // A binary tree obtained from a TraversableContainer
    BinaryTreeVec(MappableContainer<Data> &&);         // A binary tree obtained from a MappableContainer

    /* ************************************************************************ */

    // Copy constructor
    BinaryTreeVec(const BinaryTreeVec &);

    // Move constructor
    BinaryTreeVec(BinaryTreeVec &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    ~BinaryTreeVec();

    /* ************************************************************************ */

    // Copy assignment
    BinaryTreeVec &operator=(const BinaryTreeVec &);

    // Move assignment
    BinaryTreeVec &operator=(BinaryTreeVec &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const BinaryTreeVec &) const noexcept;
    bool operator!=(const BinaryTreeVec &) const noexcept;

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

    // Specific member function(inherited from TraversableContainer)

    using typename TraversableContainer<Data>::TraverseFun;

    inline void Traverse(TraverseFun) const override; // Override TraversableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from PreOrderTraversableContainer)

    inline void PreOrderTraverse(TraverseFun) const override; // Override PreOrderTraversableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from PostOrderTraversableContainer)

    inline void PostOrderTraverse(TraverseFun) const override; // Override PostOrderTraversableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from InOrderTraversableContainer)

    inline void InOrderTraverse(TraverseFun) const override; // Override InOrderTraversableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from BreadthTraversableContainer)

    inline void BreadthTraverse(TraverseFun) const override; // Override BreadthTraversableContainer member

    /* ************************************************************************ */
    // Specific member function (inherited from MappableContainer)

    using typename MappableContainer<Data>::MapFun;

    inline void Map(MapFun) override; // Override MappableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from PreOrderMappableContainer)

    inline void PreOrderMap(MapFun) override; // Override PreOrderMappableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from PostOrderMappableContainer)

    inline void PostOrderMap(MapFun) override; // Override PostOrderMappableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from InOrderMappableContainer)

    inline void InOrderMap(MapFun) override; // Override InOrderMappableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from BreadthMappableContainer)

    inline void BreadthMap(MapFun) override; // Override BreadthMappableContainer member

    /* ************************************************************************ */

  protected:
    // Auxiliary functions
    void PreOrderTraverseRicorsive(TraverseFun, const Node &) const;
    void PostOrderTraverseRicorsive(TraverseFun, const Node &) const;
    void InOrderTraverseRicorsive(TraverseFun, const Node &) const;

    void PreOrderMapRicorsive(MapFun, MutableNode &);
    void PostOrderMapRicorsive(MapFun, MutableNode &);
    void InOrderMapRicorsive(MapFun, MutableNode &);
  };

  /* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
