
#ifndef TRAVERSABLE_HPP
#define TRAVERSABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "testable.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class TraversableContainer : virtual public TestableContainer<Data>
  {
    // Must extend TestableContainer<Data>

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    virtual ~TraversableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    TraversableContainer &operator=(const TraversableContainer &) = delete;

    // Move assignment
    TraversableContainer &operator=(TraversableContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
    // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.

    /* ************************************************************************ */

    // Specific member function

    using TraverseFun = std::function<void(const Data &)>;

    virtual void Traverse(TraverseFun) const = 0; // specifiers;

    template <typename Accumulator>
    using FoldFun = std::function<Accumulator(const Data &, const Accumulator &)>;

    template <typename Accumulator>
    Accumulator Fold(FoldFun<Accumulator>, Accumulator) const;

    /* ************************************************************************ */

    // Specific member function (inherited from TestableContainer)

    inline bool Exists(const Data &) const noexcept override; // Override TestableContainer member
  };

  /* ************************************************************************** */

  template <typename Data>
  class PreOrderTraversableContainer : virtual public TraversableContainer<Data>
  {
    // Must extend TraversableContainer<Data>

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    virtual ~PreOrderTraversableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    PreOrderTraversableContainer &operator=(const PreOrderTraversableContainer &) = delete;

    // Move assignment
    PreOrderTraversableContainer &operator=(PreOrderTraversableContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
    // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.

    /* ************************************************************************ */

    // Specific member function

    using typename TraversableContainer<Data>::TraverseFun;

    // aggiunto noexcept
    virtual inline void PreOrderTraverse(TraverseFun) const = 0; // specifiers;

    template <typename Accumulator>
    using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

    template <typename Accumulator>
    inline Accumulator PreOrderFold(FoldFun<Accumulator>, Accumulator) const;

    /* ************************************************************************ */

    // Specific member function (inherited from TraversableContainer)

    virtual inline void Traverse(TraverseFun) const override; // Override TraversableContainer member
  };

  /* ************************************************************************** */

  template <typename Data>
  class PostOrderTraversableContainer : virtual public TraversableContainer<Data>
  {
    // Must extend TraversableContainer<Data>

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    virtual ~PostOrderTraversableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    PostOrderTraversableContainer &operator=(const PostOrderTraversableContainer &) = delete;

    // Move assignment
    PostOrderTraversableContainer &operator=(PostOrderTraversableContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
    // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.

    /* ************************************************************************ */

    // Specific member function

    using typename TraversableContainer<Data>::TraverseFun;

    virtual inline void PostOrderTraverse(TraverseFun) const = 0; // specifiers;

    template <typename Accumulator>
    using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

    template <typename Accumulator>
    inline Accumulator PostOrderFold(FoldFun<Accumulator>, Accumulator) const;

    /* ************************************************************************ */

    // Specific member function (inherited from TraversableContainer)

    virtual inline void Traverse(TraverseFun) const override; // Override TraversableContainer member
  };

  /* ************************************************************************** */

  template <typename Data>
  class InOrderTraversableContainer : virtual public TraversableContainer<Data>
  {
    // Must extend TraversableContainer<Data>

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    virtual ~InOrderTraversableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    InOrderTraversableContainer &operator=(const InOrderTraversableContainer &) = delete; // Copy assignment of abstract types is not possible.

    // Move assignment
    InOrderTraversableContainer &operator=(InOrderTraversableContainer &&) noexcept = delete; // Move assignment of abstract types is not possible.

    /* ************************************************************************ */

    // Comparison operators
    // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
    // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.

    /* ************************************************************************ */

    // Specific member function

    using typename TraversableContainer<Data>::TraverseFun;

    virtual inline void InOrderTraverse(TraverseFun) const = 0;

    template <typename Accumulator>
    using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

    template <typename Accumulator>
    inline Accumulator InOrderFold(FoldFun<Accumulator>, Accumulator) const;

    /* ************************************************************************ */

    // Specific member function (inherited from TraversableContainer)

    virtual inline void Traverse(TraverseFun) const override; // Override TraversableContainer member
  };

  /* ************************************************************************** */

  template <typename Data>
  class BreadthTraversableContainer : virtual public TraversableContainer<Data>
  {
    // Must extend TraversableContainer<Data>

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    virtual ~BreadthTraversableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    BreadthTraversableContainer &operator=(const BreadthTraversableContainer &) = delete; // Copy assignment of abstract types is not possible.

    // Move assignment
    BreadthTraversableContainer &operator=(BreadthTraversableContainer &&) noexcept = delete; // Move assignment of abstract types is not possible.

    /* ************************************************************************ */

    // Comparison operators
    // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
    // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.

    /* ************************************************************************ */

    // Specific member function

    using typename TraversableContainer<Data>::TraverseFun;

    virtual inline void BreadthTraverse(TraverseFun) const = 0;

    template <typename Accumulator>
    using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

    template <typename Accumulator>
    inline Accumulator BreadthFold(FoldFun<Accumulator>, Accumulator) const;

    /* ************************************************************************ */

    // Specific member function (inherited from TraversableContainer)

    virtual inline void Traverse(TraverseFun) const override; // Override TraversableContainer member
  };

  /* ************************************************************************** */

}

#include "traversable.cpp"

#endif
