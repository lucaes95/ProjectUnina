
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/traversable.hpp"
#include "../container/mappable.hpp"

#include "../iterator/iterator.hpp"

#include "../stack/vec/stackvec.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../queue/lst/queuelst.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class BinaryTree : virtual public PreOrderTraversableContainer<Data>,
                     virtual public PostOrderTraversableContainer<Data>,
                     virtual public InOrderTraversableContainer<Data>,
                     virtual public BreadthTraversableContainer<Data>
  {
    // Must extend PreOrderTraversableContainer<Data>,
    //             PostOrderTraversableContainer<Data>,
    //             InOrderTraversableContainer<Data>,
    //             BreadthTraversableContainer<Data>

  private:
    // ...

  protected:
    using Container::size;

  public:
    struct Node
    {

    protected:
      // Comparison operators
      bool operator==(const Node &) const noexcept; // Comparison of abstract types is possible, but is not visible.
      bool operator!=(const Node &) const noexcept; // Comparison of abstract types is possible, but is not visible.

    public:
      // friend class BinaryTree<Data>;
      friend class BinaryTree<Data>;

      /* ********************************************************************** */

      // Destructor
      virtual ~Node() = default;

      /* ********************************************************************** */

      // Copy assignment
      Node &operator=(const Node &) = delete; // Copy assignment of abstract types is not possible.

      // Move assignment
      Node &operator=(Node &&) noexcept = delete; // Move assignment of abstract types is not possible.

      /* ********************************************************************** */

      // Specific member functions

      inline virtual const Data &Element() const noexcept = 0; // Immutable access to the element (concrete function should not throw exceptions)
      inline virtual bool IsLeaf() const noexcept = 0;         // (concrete function should not throw exceptions)
      inline virtual bool HasLeftChild() const noexcept = 0;   // (concrete function should not throw exceptions)
      inline virtual bool HasRightChild() const noexcept = 0;  // (concrete function should not throw exceptions)

      virtual const Node &LeftChild() const = 0;  // (concrete function must throw std::out_of_range when not existent)
      virtual const Node &RightChild() const = 0; // (concrete function must throw std::out_of_range when not existent)
    };

  public:
    Node *root = nullptr;

    /* ************************************************************************ */

    // Destructor
    virtual ~BinaryTree() = default;

    /* ************************************************************************ */

    // Copy assignment
    BinaryTree &operator=(const BinaryTree &) = delete; // Copy assignment of abstract types is not possible.

    // Move assignment
    BinaryTree &operator=(BinaryTree &&) noexcept = delete; // Move assignment of abstract types is not possible.

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const BinaryTree &) const noexcept; // Comparison of abstract binary tree is possible.
    bool operator!=(const BinaryTree &) const noexcept; // Comparison of abstract binary tree is possible.

    /* ************************************************************************ */

    // Specific member functions

    virtual const Node &Root() const = 0; // (concrete function must throw std::length_error when empty)

    /* ************************************************************************ */

    // Specific member function (inherited from TraversableContainer)

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

  protected:
    // Auxiliary functions, if necessary!
    void PreOrderTraverseRicorsive(TraverseFun, const Node &) const;
    void PostOrderTraverseRicorsive(TraverseFun, const Node &) const;
    void InOrderTraverseRicorsive(TraverseFun, const Node &) const;
    void BreadthTraverse(TraverseFun, const Node &) const;
  };

  /* ************************************************************************** */

  template <typename Data>
  class MutableBinaryTree : virtual public ClearableContainer,
                            virtual public BinaryTree<Data>,
                            virtual public PreOrderMappableContainer<Data>,
                            virtual public PostOrderMappableContainer<Data>,
                            virtual public InOrderMappableContainer<Data>,
                            virtual public BreadthMappableContainer<Data>
  {
    // Must extend ClearableContainer,
    //             BinaryTree<Data>,
    //             PreOrderMappableContainer<Data>,
    //             PostOrderMappableContainer<Data>,
    //             InOrderMappableContainer<Data>,
    //             BreadthMappableContainer<Data>

  private:
    // ...

  protected:
    // ...
    using Container::size;
    using typename BinaryTree<Data>::Node;

  public:
    struct MutableNode : Node
    {
    public:
      // friend class MutableBinaryTree<Data>;
      friend class MutableBinaryTree<Data>;

      /* ********************************************************************** */

      // Destructor
      virtual ~MutableNode() = default;

      /* ********************************************************************** */

      // Copy assignment
      MutableNode &operator=(const MutableNode &) = delete; // Copy assignment of abstract types is not possible.

      // Move assignment
      MutableNode &operator=(MutableNode &&) noexcept = delete; // Move assignment of abstract types is not possible.

      /* ********************************************************************** */

      // Specific member functions
      using Node::Element;
      inline virtual Data &Element() noexcept = 0; // Mutable access to the element (concrete function should not throw exceptions)

      using Node::LeftChild;
      virtual MutableNode &LeftChild() = 0; // (concrete function must throw std::out_of_range when not existent)
      using Node::RightChild;
      virtual MutableNode &RightChild() = 0; // (concrete function must throw std::out_of_range when not existent)
    };

    /* ************************************************************************ */

    MutableNode *root = nullptr;

    // Destructor
    virtual ~MutableBinaryTree() = default;

    /* ************************************************************************ */

    // Copy assignment
    MutableBinaryTree &operator=(const MutableBinaryTree &) = delete; // Copy assignment of abstract types is not possible.

    // Move assignment
    MutableBinaryTree &operator=(MutableBinaryTree &&) noexcept = delete; // Move assignment of abstract types is not possible.

    /* ************************************************************************ */

    using BinaryTree<Data>::Root;

    // Specific member functions
    virtual MutableNode &Root() = 0; // (concrete function must throw std::length_error when empty)

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

  protected:
    // Auxiliary functions, if necessary!
    void PreOrderMapRicorsive(MapFun, MutableNode &);
    void PostOrderMapRicorsive(MapFun, MutableNode &);
    void InOrderMapRicorsive(MapFun, MutableNode &);
    void BreadthMap(MapFun, MutableNode &);
  };

  /* ************************************************************************** */

  template <typename Data>
  class BTPreOrderIterator : virtual public ForwardIterator<Data>,
                             virtual public ResettableIterator<Data>
  {
    // Must extend ForwardIterator<Data>,
    //             ResettableIterator<Data>

  private:
    // ...

  protected:
    const typename BinaryTree<Data>::Node *current = nullptr;
    const typename BinaryTree<Data>::Node *root = nullptr;

    StackLst<const typename BinaryTree<Data>::Node *> stk;

  public:
    // Specific constructors
    BTPreOrderIterator(const BinaryTree<Data> &); // An iterator over a given binary tree

    /* ************************************************************************ */

    // Copy constructor
    BTPreOrderIterator(const BTPreOrderIterator &itr);

    // Move constructor
    BTPreOrderIterator(BTPreOrderIterator &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    virtual ~BTPreOrderIterator() = default;

    /* ************************************************************************ */

    // Copy assignment
    BTPreOrderIterator &operator=(const BTPreOrderIterator &);

    // Move assignment
    BTPreOrderIterator &operator=(BTPreOrderIterator &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const BTPreOrderIterator &) const noexcept = default;
    bool operator!=(const BTPreOrderIterator &) const noexcept = default;

    /* ************************************************************************ */

    // Specific member functions (inherited from Iterator)

    const Data &operator*() const override;

    bool Terminated() const noexcept override; // (should not throw exceptions)

    /* ************************************************************************ */

    // Specific member functions (inherited from ForwardIterator)

    ForwardIterator<Data> &operator++() override
    {
      if (!(current == nullptr && stk.Size() == 0))
      {
        if (current->HasRightChild())
          stk.Push(&current->RightChild());

        if (current->HasLeftChild())
          current = &current->LeftChild();
        else
          current = nullptr;

        if (current == nullptr && stk.Size() != 0)
          current = stk.TopNPop();
      }
      else
        throw std::out_of_range("The iterator is terminated");

      return *this;

    } // (throw std::out_of_range when terminated)

    /* ************************************************************************ */

    // Specific member functions (inherited from ResettableIterator)

    void Reset() noexcept override
    {
      if (root != nullptr)
      {
        current = root;
        stk.Clear();
      }
    } // (should not throw exceptions)
  };

  /* ************************************************************************** */

  template <typename Data>
  class BTPreOrderMutableIterator : virtual public MutableIterator<Data>,
                                    virtual public BTPreOrderIterator<Data>
  {
    // Must extend MutableIterator<Data>,
    //             BTPreOrderIterator<Data>

  private:
    // ...

  protected:
    using BTPreOrderIterator<Data>::stk;
    using BTPreOrderIterator<Data>::current;
    using BTPreOrderIterator<Data>::root;

  public:
    // Specific constructors
    BTPreOrderMutableIterator(MutableBinaryTree<Data> &tree) : BTPreOrderIterator<Data>(tree){}; // An iterator over a given mutable binary tree

    /* ************************************************************************ */

    // Copy constructor
    BTPreOrderMutableIterator(const BTPreOrderMutableIterator &itr) : BTPreOrderIterator<Data>(itr){};

    // Move constructor
    BTPreOrderMutableIterator(BTPreOrderMutableIterator &&itr) noexcept : BTPreOrderIterator<Data>(std::move(itr)){};

    /* ************************************************************************ */

    // Destructor
    virtual ~BTPreOrderMutableIterator() = default;

    /* ************************************************************************ */

    // Copy assignment
    BTPreOrderMutableIterator &operator=(const BTPreOrderMutableIterator &);

    // Move assignment
    BTPreOrderMutableIterator &operator=(BTPreOrderMutableIterator &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const BTPreOrderMutableIterator &) const noexcept = default;
    bool operator!=(const BTPreOrderMutableIterator &) const noexcept = default;

    /* ************************************************************************ */

    // Specific member functions (inherited from MutableIterator)

    Data &operator*() override
    {
      if (current != nullptr)
      {
        return const_cast<Data &>(current->Element());
      }
      else
        throw std::out_of_range("The iterator is terminated");
    } // (throw std::out_of_range when terminated)
  };

  /* ************************************************************************** */

  template <typename Data>
  class BTPostOrderIterator : virtual public ForwardIterator<Data>, virtual public ResettableIterator<Data>
  {
    // Must extend ForwardIterator<Data>,
    //             ResettableIterator<Data>

  private:
    // ...

  protected:
    const typename BinaryTree<Data>::Node *current = nullptr;
    const typename BinaryTree<Data>::Node *root = nullptr;
    const typename BinaryTree<Data>::Node *tmpnode = nullptr;

    StackLst<const typename BinaryTree<Data>::Node *> stk;

  public:
    // Specific constructors
    BTPostOrderIterator(const BinaryTree<Data> &tree); // An iterator over a given binary tree

    /* ************************************************************************ */

    // Copy constructor
    BTPostOrderIterator(const BTPostOrderIterator &itr);

    // Move constructor
    BTPostOrderIterator(BTPostOrderIterator &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    virtual ~BTPostOrderIterator() = default;

    /* ************************************************************************ */

    // Copy assignment
    BTPostOrderIterator &operator=(const BTPostOrderIterator &);

    // Move assignment
    BTPostOrderIterator &operator=(BTPostOrderIterator &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const BTPostOrderIterator &) const noexcept = default;
    bool operator!=(const BTPostOrderIterator &) const noexcept = default;

    /* ************************************************************************ */

    // Specific member functions (inherited from Iterator)

    const Data &operator*() const override;

    bool Terminated() const noexcept override; // (should not throw exceptions)

    /* ************************************************************************ */

    // Specific member functions (inherited from ForwardIterator)

    ForwardIterator<Data> &operator++() override
    {
      bool flag = false;

      if (!((tmpnode == nullptr) && (current == nullptr && stk.Size() == 0)))
      {
        if (tmpnode == nullptr && stk.Size() == 0)
        {
          current = nullptr;
        }
        else
        {
          while (!flag && (tmpnode != nullptr || stk.Size() != 0))
          {
            if (tmpnode != nullptr)
            {

              stk.Push(tmpnode);
              if (tmpnode->HasLeftChild())
                tmpnode = &tmpnode->LeftChild();
              else
                tmpnode = nullptr;
            }
            else
            {
              tmpnode = stk.Top();

              if (!(tmpnode->HasRightChild()) || current == &tmpnode->RightChild())
              {
                current = tmpnode;
                flag = true;
                stk.Pop();
                tmpnode = nullptr;
              }
              else
                tmpnode = &tmpnode->RightChild();
            }
          }
        }
      }
      else
        throw std::out_of_range("The iterator is terminated");

      return *this;

      // (throw std::out_of_range when terminated)
    }

    /* ************************************************************************ */

    // Specific member functions (inherited from ResettableIterator)

    void Reset() noexcept override
    {
      if (root != nullptr)
      {
        stk.Clear();

        tmpnode = root;
        bool flag = false;

        while (!flag && (tmpnode != nullptr || stk.Size() != 0))
        {
          if (tmpnode != nullptr)
          {
            stk.Push(tmpnode);

            if (tmpnode->HasLeftChild())
              tmpnode = &tmpnode->LeftChild();
            else
              tmpnode = nullptr;
          }
          else
          {
            tmpnode = stk.Top();
            if (!(tmpnode->HasRightChild()))
            {
              current = tmpnode;
              flag = true;
              stk.Pop();
              tmpnode = nullptr;
            }
            else
              tmpnode = &tmpnode->RightChild();
          }
        }
      }
    } // (should not throw exceptions)
  };

  /* ************************************************************************** */

  template <typename Data>
  class BTPostOrderMutableIterator : virtual public MutableIterator<Data>, virtual public BTPostOrderIterator<Data>
  {
    // Must extend MutableIterator<Data>,
    //             BTPostOrderIterator<Data>

  private:
    // ...

  protected:
    using BTPostOrderIterator<Data>::stk;
    using BTPostOrderIterator<Data>::current;
    using BTPostOrderIterator<Data>::root;

  public:
    // Specific constructors
    BTPostOrderMutableIterator(MutableBinaryTree<Data> &tree) : BTPostOrderIterator<Data>(tree){}; // An iterator over a given binary tree

    /* ************************************************************************ */

    // Copy constructor
    BTPostOrderMutableIterator(const BTPostOrderMutableIterator<Data> &itr) : BTPostOrderIterator<Data>(itr){};

    // Move constructor
    BTPostOrderMutableIterator(BTPostOrderMutableIterator &&itr) noexcept : BTPostOrderIterator<Data>(std::move(itr)){};

    /* ************************************************************************ */

    // Destructor
    virtual ~BTPostOrderMutableIterator() = default;

    /* ************************************************************************ */

    // Copy assignment
    BTPostOrderMutableIterator &operator=(const BTPostOrderMutableIterator &);

    // Move assignment
    BTPostOrderMutableIterator &operator=(BTPostOrderMutableIterator &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const BTPostOrderMutableIterator &) const noexcept = default;
    bool operator!=(const BTPostOrderMutableIterator &) const noexcept = default;

    /* ************************************************************************ */

    // Specific member functions (inherited from Iterator)

    Data &operator*() override
    {
      if (current != nullptr)
      {
        return const_cast<Data &>(current->Element());
      }
      else
        throw std::out_of_range("The iterator is terminated");
    } // (throw std::out_of_range when terminated)

    /* ************************************************************************ */
  };

  /* ************************************************************************** */

  template <typename Data>
  class BTInOrderIterator : virtual public ForwardIterator<Data>, virtual public ResettableIterator<Data>
  {
    // Must extend ForwardIterator<Data>,
    //             ResettableIterator<Data>

  private:
    // ...

  protected:
    const typename BinaryTree<Data>::Node *current = nullptr;
    const typename BinaryTree<Data>::Node *tmpnode = nullptr;
    const typename BinaryTree<Data>::Node *root = nullptr;

    StackLst<const typename BinaryTree<Data>::Node *> stk;

  public:
    // Specific constructors
    BTInOrderIterator(const BinaryTree<Data> &); // An iterator over a given binary tree

    /* ************************************************************************ */

    // Copy constructor
    BTInOrderIterator(const BTInOrderIterator &itr);

    // Move constructor
    BTInOrderIterator(BTInOrderIterator &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    virtual ~BTInOrderIterator() = default;

    /* ************************************************************************ */

    // Copy assignment
    BTInOrderIterator &operator=(const BTInOrderIterator &);

    // Move assignment
    BTInOrderIterator &operator=(BTInOrderIterator &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const BTInOrderIterator &) const noexcept;
    bool operator!=(const BTInOrderIterator &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from Iterator)

    const Data &operator*() const override;

    bool Terminated() const noexcept override; // (should not throw exceptions)

    /* ************************************************************************ */

    // Specific member functions (inherited from ForwardIterator)

    ForwardIterator<Data> &operator++() override
    {

      bool flag = false;

      if (!((tmpnode == nullptr) && (current == nullptr && stk.Size() == 0)))
      {
        if (tmpnode == nullptr && stk.Size() == 0)
        {
          current = nullptr;
        }
        else
        {
          while (!flag && (tmpnode != nullptr || stk.Size() != 0))
          {
            if (tmpnode != nullptr)
            {

              stk.Push(tmpnode);
              if (tmpnode->HasLeftChild())
                tmpnode = &tmpnode->LeftChild();
              else
                tmpnode = nullptr;
            }
            else
            {
              tmpnode = stk.TopNPop();

              flag = true;
              current = tmpnode;

              if (tmpnode->HasRightChild())
                tmpnode = &tmpnode->RightChild();
              else
                tmpnode = nullptr;
            }
          }
        }
      }
      else
        throw std::out_of_range("The iterator is terminated");

      return *this;

    } // (throw std::out_of_range when terminated)

    /* ************************************************************************ */

    // Specific member functions (inherited from ResettableIterator)

    void Reset() noexcept override
    {
      if (root != nullptr)
      {
        current = root;
        stk.Clear();

        bool flag = false;

        while (!flag)
        {
          if (current != nullptr)
          {
            stk.Push(current);
            if (current->HasLeftChild())
              current = &current->LeftChild();
            else
              current = nullptr;
          }
          else
          {
            current = stk.TopNPop();

            if (current->HasRightChild())
              stk.Push(&current->RightChild());

            flag = true;
          }
        }
      }
    } // (should not throw exceptions)
  };

  /* ************************************************************************** */

  template <typename Data>
  class BTInOrderMutableIterator : virtual public MutableIterator<Data>, virtual public BTInOrderIterator<Data>
  {
    // Must extend MutableIterator<Data>,
    //             BTInOrderIterator<Data>

  private:
    // ...

  protected:
    using BTInOrderIterator<Data>::stk;
    using BTInOrderIterator<Data>::current;
    using BTInOrderIterator<Data>::tmpnode;
    using BTInOrderIterator<Data>::root;

  public:
    // Specific constructors
    BTInOrderMutableIterator(MutableBinaryTree<Data> &tree) : BTInOrderIterator<Data>(tree){}; // An iterator over a given binary tree

    /* ************************************************************************ */

    // Copy constructor
    BTInOrderMutableIterator(const BTInOrderMutableIterator<Data> &itr) : BTInOrderIterator<Data>(itr){};

    // Move constructor
    BTInOrderMutableIterator(BTInOrderMutableIterator &&itr) noexcept : BTInOrderIterator<Data>(std::move(itr)){};

    /* ************************************************************************ */

    // Destructor
    virtual ~BTInOrderMutableIterator() = default;

    /* ************************************************************************ */

    // Copy assignment
    BTInOrderMutableIterator &operator=(const BTInOrderMutableIterator &);

    // Move assignment
    BTInOrderMutableIterator &operator=(BTInOrderMutableIterator &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const BTInOrderMutableIterator &) const noexcept = default;
    bool operator!=(const BTInOrderMutableIterator &) const noexcept = default;

    /* ************************************************************************ */

    // Specific member functions (inherited from Iterator)

    Data &operator*() override
    {
      if (current != nullptr)
      {
        return const_cast<Data &>(current->Element());
      }
      else
        throw std::out_of_range("The iterator is terminated");
    } // (throw std::out_of_range when terminated)
  };

  /* ************************************************************************** */

  template <typename Data>
  class BTBreadthIterator : virtual public ForwardIterator<Data>, virtual public ResettableIterator<Data>
  {
    // Must extend ForwardIterator<Data>,
    //             ResettableIterator<Data>

  private:
    // ...

  protected:
    const typename BinaryTree<Data>::Node *current = nullptr;
    const typename BinaryTree<Data>::Node *root = nullptr;

    QueueLst<const typename BinaryTree<Data>::Node *> que;

  public:
    // Specific constructors
    BTBreadthIterator(const BinaryTree<Data> &); // An iterator over a given binary tree

    /* ************************************************************************ */

    // Copy constructor
    BTBreadthIterator(const BTBreadthIterator &itr);

    // Move constructor
    BTBreadthIterator(BTBreadthIterator &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    virtual ~BTBreadthIterator() = default;

    /* ************************************************************************ */

    // Copy assignment
    BTBreadthIterator &operator=(const BTBreadthIterator &);

    // Move assignment
    BTBreadthIterator &operator=(BTBreadthIterator &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const BTBreadthIterator &) const noexcept = default;
    bool operator!=(const BTBreadthIterator &) const noexcept = default;

    /* ************************************************************************ */

    // Specific member functions (inherited from Iterator)

    const Data &operator*() const override;

    bool Terminated() const noexcept override; // (should not throw exceptions)

    /* ************************************************************************ */

    // Specific member functions (inherited from ForwardIterator)

    ForwardIterator<Data> &operator++() override
    {

      if (current != nullptr || que.Size() != 0)
      {
        if (que.Size() == 0)
        {
          current = nullptr;
        }
        else
        {
          current = que.HeadNDequeue();

          if (current->HasLeftChild())
            que.Enqueue(&current->LeftChild());
          if (current->HasRightChild())
            que.Enqueue(&current->RightChild());
        }
      }
      else
        throw std::out_of_range("The iterator is terminated");

      return *this;
    };

    /* ************************************************************************ */

    // Specific member functions (inherited from ResettableIterator)

    void Reset() noexcept override
    {
      if (root != nullptr)
      {
        current = root;
        que.Clear();

        if (current->HasLeftChild())
          que.Enqueue(&current->LeftChild());
        if (current->HasRightChild())
          que.Enqueue(&current->RightChild());
      }

    } // (should not throw exceptions)
  };

  template <typename Data>
  class BTBreadthMutableIterator : virtual public MutableIterator<Data>, virtual public BTBreadthIterator<Data>
  {
    // Must extend MutableIterator<Data>,
    //             BTBreadthIterator<Data>

  private:
    // ...

  protected:
    using BTBreadthIterator<Data>::current;
    using BTBreadthIterator<Data>::root;
    using BTBreadthIterator<Data>::que;

  public:
    // Specific constructors
    BTBreadthMutableIterator(MutableBinaryTree<Data> &tree) : BTBreadthIterator<Data>(tree){}; // An iterator over a given binary tree

    /* ************************************************************************ */

    // Copy constructor
    BTBreadthMutableIterator(const BTBreadthMutableIterator<Data> &itr) : BTBreadthIterator<Data>(itr){};

    // Move constructor
    BTBreadthMutableIterator(BTBreadthMutableIterator &&itr) noexcept : BTBreadthIterator<Data>(std::move(itr)){};

    /* ************************************************************************ */

    // Destructor
    virtual ~BTBreadthMutableIterator() = default;

    /* ************************************************************************ */

    // Copy assignment
    BTBreadthMutableIterator &operator=(const BTBreadthMutableIterator &);

    // Move assignment
    BTBreadthMutableIterator &operator=(BTBreadthMutableIterator &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const BTBreadthMutableIterator &) const noexcept = default;
    bool operator!=(const BTBreadthMutableIterator &) const noexcept = default;

    /* ************************************************************************ */

    // Specific member functions (inherited from Iterator)

    Data &operator*() override
    {
      if (current != nullptr)
      {
        return const_cast<Data &>(current->Element());
      }
      else
        throw std::out_of_range("The iterator is terminated");
    }
  };

  /* ************************************************************************** */
}

#include "binarytree.cpp"

#endif
