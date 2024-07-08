
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

typedef unsigned int uint;
typedef unsigned long ulong;

/* ************************************************************************** */

#include <string>

/* ************************************************************************** */

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  class Container
  {

  private:
    // ...

  protected:
    ulong size = 0;

    /* ************************************************************************ */

    // // Default constructor
    // Container() = default;

  public:
    // Destructor
    virtual ~Container() = default;

    /* ************************************************************************ */

    // Copy assignment
    Container &operator=(const Container &) = delete;

    // Move assignment
    Container &operator=(Container &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const Container &) const noexcept = delete;
    bool operator!=(const Container &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member functions

    virtual inline bool Empty() const noexcept { return (size == 0); } // (concrete function should not throw exceptions)

    virtual inline ulong Size() const noexcept { return size; } // (concrete function should not throw exceptions)
  };

  /* ************************************************************************** */

  class ClearableContainer : virtual public Container
  {
    // Must extend Container

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    virtual ~ClearableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    ClearableContainer &operator=(const ClearableContainer &) = delete;

    // Move assignment
    ClearableContainer &operator=(ClearableContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const ClearableContainer &) const noexcept = delete;
    bool operator!=(const ClearableContainer &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member functions

    virtual void Clear() = 0;
  };

  /* ************************************************************************** */

  class ResizableContainer : virtual public ClearableContainer
  {
    // Must extend ClearableContainer

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    virtual ~ResizableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    ResizableContainer &operator=(const ResizableContainer &) = delete;

    // Move assignment
    ResizableContainer &operator=(ResizableContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const ResizableContainer &) const noexcept = delete;
    bool operator!=(const ResizableContainer &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member functions

    virtual void Resize(const ulong) = 0;

    /* ************************************************************************ */

    // Specific member function (inherited from ClearableContainer)

    virtual void Clear() override = 0; // Override ClearableContainer member
  };

  /* ************************************************************************** */

};

#endif
