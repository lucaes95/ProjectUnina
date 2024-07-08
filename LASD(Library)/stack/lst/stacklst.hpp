
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class StackLst : virtual protected List<Data>, virtual public Stack<Data>
  {
    // Must extend Stack<Data>,
    //             List<Data>

  private:
    // ...

  protected:
    // ...

  public:
    // Default constructor
    inline StackLst() = default;

    /* ************************************************************************ */

    // Specific constructor
    StackLst(const TraversableContainer<Data> &con) : List<Data>(con){};    // A stack obtained from a TraversableContainer
    StackLst(MappableContainer<Data> &&con) : List<Data>(std::move(con)){}; // A stack obtained from a MappableContainer

    /* ************************************************************************ */

    // Copy constructor
    StackLst(const StackLst &stk) : List<Data>(stk){};

    // Move constructor
    StackLst(StackLst &&stk) noexcept : List<Data>(std::move(stk)){};

    /* ************************************************************************ */

    // Destructor
    virtual ~StackLst() = default;

    /* ************************************************************************ */

    // Copy assignment
    StackLst operator=(const StackLst &);

    // Move assignment
    StackLst operator=(StackLst &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const StackLst &) const noexcept;
    bool operator!=(const StackLst &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from Stack)

    Data const &Top() const override; // Override Stack member (non-mutable version; must throw std::length_error when empty)
    Data &Top() override;             // Override Stack member (mutable version; must throw std::length_error when empty)
    void Pop() override;              // Override Stack member (must throw std::length_error when empty)
    Data TopNPop() override;          // Override Stack member (must throw std::length_error when empty)
    void Push(const Data &) override; // Override Stack member (copy of the value)
    void Push(Data &&) override;      // Override Stack member (move of the value)

    /* ************************************************************************ */

    // Specific member function (inherited from ClearableContainer)

    using List<Data>::Clear;

  protected:
    // Auxiliary functions, if necessary!
  };

  /* ************************************************************************** */

}

#include "stacklst.cpp"

#endif
