
#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class Vector : virtual public ResizableContainer, virtual public LinearContainer<Data>
  {
    // Must extend ResizableContainer,
    //             LinearContainer<Data>

  private:
    // ...

  protected:
    using LinearContainer<Data>::size;
    Data *Elements = nullptr;

    // ...

  public:
    // Default constructor
    Vector() = default;

    /* ************************************************************************ */

    // Specific constructors
    Vector(const ulong);                        // A vector with a given initial dimension
    Vector(const TraversableContainer<Data> &); // A vector obtained from a TraversableContainer
    Vector(MappableContainer<Data> &&);         // A vector obtained from a MappableContainer

    /* ************************************************************************ */

    // Copy constructor
    Vector(const Vector &); // specifiers;

    // Move constructor
    Vector(Vector &&) noexcept; // specifiers;

    /* ************************************************************************ */

    // Destructor
    ~Vector(); // specifiers;

    /* ************************************************************************ */

    // Copy assignment
    Vector &operator=(const Vector &); // specifiers;

    // Move assignment
    Vector &operator=(Vector &&) noexcept; // specifiers;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const Vector &) const noexcept; // specifiers;
    bool operator!=(const Vector &) const noexcept; // specifiers;

    /* ************************************************************************ */

    // Specific member function (inherited from ClearableContainer)

    void Clear() override; // specifiers; // Override ClearableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from ResizableContainer)

    void Resize(const ulong) override; // specifiers; // Override ResizableContainer member

    /* ************************************************************************ */

    // Specific member functions (inherited from LinearContainer)

    inline const Data &operator[](ulong) const override; // Override (NonMutable) LinearContainer member (must throw std::out_of_range when out of range)
    inline Data &operator[](ulong) override;             // Override (Mutable) LinearContainer member (must throw std::out_of_range when out of range)

    const Data &Front() const override; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
    inline Data &Front() override;      // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

    const Data &Back() const override; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
    inline Data &Back() override;      // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

  protected:
    // Auxiliary functions, if necessary!
  };

  /* ************************************************************************** */

  template <typename Data>
  class SortableVector : virtual public Vector<Data>, virtual public SortableLinearContainer<Data>
  {
    // Must extend Vector<Data>,
    //             SortableLinearContainer<Data>

  private:
  protected:
    using Container::size;
    using Vector<Data>::Elements;

    // ...

  public:
    // Default constructor
    SortableVector() = default;

    /* ************************************************************************ */

    // Specific constructors
    SortableVector(const ulong);                        // A vector with a given initial dimension
    SortableVector(const TraversableContainer<Data> &); // A vector obtained from a TraversableContainer
    SortableVector(MappableContainer<Data> &&);         // A vector obtained from a MappableContainer

    /* ************************************************************************ */

    // Copy constructor
    SortableVector(const SortableVector &); // specifiers;

    // Move constructor
    SortableVector(SortableVector &&) noexcept; // specifiers;

    /* ************************************************************************ */

    // Destructor
    ~SortableVector() = default;

    /* ************************************************************************ */

    // Copy assignment
    SortableVector &operator=(const SortableVector &); // specifiers;

    // Move assignment
    SortableVector &operator=(SortableVector &&) noexcept; // specifiers;

    // Auxiliary functions, if necessary!

  protected:
    // Auxiliary functions, if necessary!
  };

  /* ************************************************************************** */

}

#include "vector.cpp"

#endif
