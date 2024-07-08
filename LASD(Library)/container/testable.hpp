
#ifndef TESTABLE_HPP
#define TESTABLE_HPP

/* ************************************************************************** */

#include <iostream>

#include "container.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class TestableContainer : virtual public Container
  {
    // Must extend Container

  private:
    // ...

  protected:
    // ...

  public:
    // Destructor
    virtual ~TestableContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    TestableContainer &operator=(const TestableContainer &) = delete;

    // Move assignment
    TestableContainer &operator=(TestableContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const TestableContainer &) const noexcept = delete;
    bool operator!=(const TestableContainer &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member function

    virtual inline bool Exists(const Data &) const noexcept = 0; // (concrete function should not throw exceptions)
  };

  /* ************************************************************************** */

}

#endif
