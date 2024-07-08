
#ifndef MAPPABLE_HPP
#define MAPPABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "traversable.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class MappableContainer : virtual public TraversableContainer<Data>
  {
    // Must extend TraversableContainer<Data>

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    virtual ~MappableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    MappableContainer &operator=(const MappableContainer &) = delete;

    // Move assignment
    MappableContainer &operator=(MappableContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const MappableContainer &) const noexcept = delete;
    bool operator!=(const MappableContainer &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member function

    using MapFun = std::function<void(Data &)>;

    virtual void Map(MapFun) = 0; // specifiers;
  };

  /* ************************************************************************** */

  template <typename Data>
  class PreOrderMappableContainer : virtual public MappableContainer<Data>,
                                    virtual public PreOrderTraversableContainer<Data>
  {
    // Must extend MappableContainer<Data>,
    //             PreOrderTraversableContainer<Data>

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    virtual ~PreOrderMappableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    PreOrderMappableContainer &operator=(const PreOrderMappableContainer &) = delete;

    // Move assignment
    PreOrderMappableContainer &operator=(PreOrderMappableContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const PreOrderMappableContainer &) const noexcept = delete;
    bool operator!=(const PreOrderMappableContainer &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member function

    using typename MappableContainer<Data>::MapFun;

    virtual inline void PreOrderMap(MapFun) = 0; // specifiers;

    /* ************************************************************************ */

    // Specific member function (inherited from MappableContainer)

    virtual inline void Map(MapFun) override; // specifiers; // Override MappableContainer member
  };

  /* ************************************************************************** */

  template <typename Data>
  class PostOrderMappableContainer : virtual public MappableContainer<Data>, virtual public PostOrderTraversableContainer<Data>
  {
    // Must extend MappableContainer<Data>,
    //             PostOrderTraversableContainer<Data>

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    virtual ~PostOrderMappableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    PostOrderMappableContainer &operator=(const PostOrderMappableContainer &) = delete;

    // Move assignment
    PostOrderMappableContainer &operator=(PostOrderMappableContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const PostOrderMappableContainer &) const noexcept = delete;
    bool operator!=(const PostOrderMappableContainer &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member function

    using typename MappableContainer<Data>::MapFun;

    inline virtual void PostOrderMap(MapFun) = 0;

    /* ************************************************************************ */

    // Specific member function (inherited from MappableContainer)

    inline virtual void Map(MapFun) override; // Override MappableContainer member
  };

  /* ************************************************************************** */

  template <typename Data>
  class InOrderMappableContainer : virtual public MappableContainer<Data>,
                                   virtual public InOrderTraversableContainer<Data>
  {
    // Must extend MappableContainer<Data>,
    //             InOrderTraversableContainer<Data>

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    virtual ~InOrderMappableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    InOrderMappableContainer &operator=(const InOrderMappableContainer &) = delete; // Copy assignment of abstract types is not possible.

    // Move assignment
    InOrderMappableContainer &operator=(InOrderMappableContainer &&) noexcept = delete; // Move assignment of abstract types is not possible.

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const InOrderMappableContainer) const noexcept = delete; // Comparison of abstract types is not possible.
    bool operator!=(const InOrderMappableContainer) const noexcept = delete; // Comparison of abstract types is not possible.

    /* ************************************************************************ */

    // Specific member function

    using typename MappableContainer<Data>::MapFun;

    virtual inline void InOrderMap(MapFun) = 0;

    /* ************************************************************************ */

    // Specific member function (inherited from MappableContainer)

    virtual inline void Map(MapFun) override; // Override MappableContainer member
  };

  /* ************************************************************************** */

  template <typename Data>
  class BreadthMappableContainer : virtual public MappableContainer<Data>,
                                   virtual public BreadthTraversableContainer<Data>
  {
    // Must extend MappableContainer<Data>,
    //             BreadthTraversableContainer<Data>

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    virtual ~BreadthMappableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    BreadthMappableContainer &operator=(const BreadthMappableContainer &) = delete; // Copy assignment of abstract types is not possible.

    // Move assignment
    BreadthMappableContainer &operator=(BreadthMappableContainer &&) noexcept = delete; // Move assignment of abstract types is not possible.

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const BreadthMappableContainer &) const noexcept = delete; // Comparison of abstract types is not possible.
    bool operator!=(const BreadthMappableContainer &) const noexcept = delete; // Comparison of abstract types is not possible.

    /* ************************************************************************ */

    // Specific member function

    using typename MappableContainer<Data>::MapFun;

    virtual inline void BreadthMap(MapFun) = 0;

    /* ************************************************************************ */

    // Specific member function (inherited from MappableContainer)

    virtual inline void Map(MapFun) override; // Override MappableContainer member
  };

  /* ************************************************************************** */

}

#include "mappable.cpp"

#endif
