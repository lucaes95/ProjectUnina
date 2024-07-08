
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/* ************************************************************************** */

#include <random>

/* ************************************************************************** */

#include "../container/dictionary.hpp"

/* ************************************************************************** */

typedef unsigned long ulong;

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class Hashable
  {

  public:
    ulong operator()(const Data &dat) const noexcept = 0; // (concrete function should not throw exceptions)
  };

  /* ************************************************************************** */

  template <typename Data>
  class HashTable : virtual public ResizableContainer, virtual public DictionaryContainer<Data>
  {
    // Must extend ResizableContainer,
    //             DictionaryContainer<Data>

  private:
    // ...

  protected:
    using DictionaryContainer<Data>::size;

    ulong acf = 1;
    ulong bcf = 0;

    static const ulong prime = 1000234657;
    static const Hashable<Data> enchash;

    std::default_random_engine gen = std::default_random_engine(std::random_device{}());
    std::uniform_int_distribution<ulong> dista = std::uniform_int_distribution<ulong>(1, prime - 1);
    std::uniform_int_distribution<ulong> distb = std::uniform_int_distribution<ulong>(0, prime - 1);

    ulong tablesize = 128;

    // default constructor
    HashTable()
    {
      acf = dista(gen);
      bcf = distb(gen);
    }

    // copy constructor
    HashTable(const HashTable &ht)
    {
      size = ht.size;
      acf = ht.acf;
      bcf = ht.bcf;
      tablesize = ht.tablesize;
    }

    // move constructor
    HashTable(HashTable &&ht)
    {
      std::swap(size, ht.size);
      std::swap(acf, ht.acf);
      std::swap(bcf, ht.bfc);
      std::swap(tablesize, ht.tablesize);
    }

  public:
    // Destructor
    virtual ~HashTable() = default;

    /* ************************************************************************ */

    // Copy assignment
    HashTable &operator=(const HashTable &) = delete; // Copy assignment of abstract types should not be possible.

    // Move assignment
    HashTable &operator=(HashTable &&) noexcept = delete; // Move assignment of abstract types should not be possible.

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const HashTable &) const noexcept = delete; // Comparison of abstract hashtable is possible but not required.
    bool operator!=(const HashTable &) const noexcept = delete; // Comparison of abstract hashtable is possible but not required.

  protected:
    // Auxiliary member functions

    virtual ulong HashKey(const Data &dat) const noexcept
    {
      return HashKey(enchash(dat));
    }

    virtual ulong HashKey(ulong key) const noexcept
    {
      return (((acf * key + bcf) % prime) % tablesize);
    }
  };

  /* ************************************************************************** */

}

#include "hashtable.cpp"

#endif
