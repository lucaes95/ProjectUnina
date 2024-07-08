
#ifndef QUEUE_HPP
#define QUEUE_HPP

/* ************************************************************************** */

#include <iostream>

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class Queue : virtual public ClearableContainer
  {
    // Must extend ClearableContainer

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    virtual ~Queue() = default;

    /* ************************************************************************ */

    // Copy assignment
    Queue &operator=(const Queue &) = delete;

    // Move assignment
    Queue &operator=(Queue &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const Queue &) const noexcept = delete;
    bool operator!=(const Queue &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member functions

    virtual Data const &Head() const = 0;   // (non-mutable version; concrete function must throw std::length_error when empty)
    virtual Data &Head() = 0;               // (mutable version; concrete function must throw std::length_error when empty)
    virtual void Dequeue() = 0;             // (concrete function must throw std::length_error when empty)
    virtual Data HeadNDequeue() = 0;        // (concrete function must throw std::length_error when empty)
    virtual void Enqueue(const Data &) = 0; // Copy of the value
    virtual void Enqueue(Data &&) = 0;      // Move of the value
  };

  /* ************************************************************************** */

}

#endif
