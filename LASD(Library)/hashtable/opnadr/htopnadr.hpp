
#ifndef HTOPNADR_HPP
#define HTOPNADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
// #include ...

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class HashTableOpnAdr : virtual public HashTable<Data>
  {
    // Must extend HashTable<Data>

  private:
    // ...

  protected:
    using HashTable<Data>::size;
    using HashTable<Data>::tablesize;
    using HashTable<Data>::acf;
    using HashTable<Data>::bcf;
    using HashTable<Data>::enchash;
    using HashTable<Data>::HashKey;

    Vector<Data> Table{};
    Vector<char> state{}; // state = {N,I,C}, N (date not entered), I (date entered),  C (date deleted)

    ulong cremove = 0;

  public:
    // Default constructor
    HashTableOpnAdr();

    /* ************************************************************************ */

    // Specific constructors
    HashTableOpnAdr(const ulong);                                     // A hash table of a given size
    HashTableOpnAdr(const TraversableContainer<Data> &);              // A hash table obtained from a TraversableContainer
    HashTableOpnAdr(const ulong, const TraversableContainer<Data> &); // A hash table of a given size obtained from a TraversableContainer
    HashTableOpnAdr(MappableContainer<Data> &&);                      // A hash table obtained from a MappableContainer
    HashTableOpnAdr(const ulong, MappableContainer<Data> &&);         // A hash table of a given size obtained from a MappableContainer

    /* ************************************************************************ */

    // Copy constructor
    HashTableOpnAdr(const HashTableOpnAdr &);

    // Move constructor
    HashTableOpnAdr(HashTableOpnAdr &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    virtual ~HashTableOpnAdr() = default;

    /* ************************************************************************ */

    // Copy assignment
    HashTableOpnAdr &operator=(const HashTableOpnAdr &);

    // Move assignment
    HashTableOpnAdr &operator=(HashTableOpnAdr &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const HashTableOpnAdr &) const noexcept;
    bool operator!=(const HashTableOpnAdr &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from DictionaryContainer)

    bool Insert(const Data &dat) override; // Override DictionaryContainer member (Copy of the value)
    bool Insert(Data &&dat) override;      // Override DictionaryContainer member (Move of the value)
    bool Remove(const Data &dat) override; // Override DictionaryContainer member

    /* ************************************************************************ */

    // Specific member functions (inherited from TestableContainer)

    bool Exists(const Data &) const noexcept override; // Override TestableContainer member

    /* ************************************************************************ */

    // Specific member functions (inherited from ResizableContainer)

    void Resize(const ulong) override; // Resize the hashtable to a given size

    /* ************************************************************************ */

    // Specific member functions (inherited from ClearableContainer)

    void Clear() override; // Override Container member

  protected:
    // Auxiliary member functions

    virtual ulong HashKey(const Data &dat, ulong &index) const noexcept
    {
      return HashKey(enchash(dat), index);
    }

    virtual ulong HashKey(ulong key, ulong &index) const noexcept
    {
      return ((((acf * key + bcf) % 1111 + (index * (index + 1)) / 2)) % (tablesize));
    }
  };

  /* ************************************************************************** */
}

#include "htopnadr.cpp"

#endif
