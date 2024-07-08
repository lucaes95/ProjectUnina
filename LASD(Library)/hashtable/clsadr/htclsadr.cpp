#include "htclsadr.hpp"

namespace lasd
{

    /* ************************************************************************** */
    template <typename Data>
    HashTableClsAdr<Data>::HashTableClsAdr()
    {
        Table.Resize(128);
    }

    template <typename Data>
    HashTableClsAdr<Data>::HashTableClsAdr(const ulong dim)
    {
        if (dim > 64)
        {
            tablesize = dim;
            Table.Resize(dim);
        }
        else
            this->Clear();
    }

    // Specific constructors (from a TraversableContainer)
    template <typename Data>
    HashTableClsAdr<Data>::HashTableClsAdr(const TraversableContainer<Data> &con)
    {
        if (!con.Empty())
        {
            if (con.Size() < 64)
                tablesize = 128;
            else
                tablesize = con.Size() * 2;

            Table.Resize(tablesize);

            con.Traverse([this](const Data dat)
                         { this->Insert(dat); });
        }
    }

    template <typename Data>
    HashTableClsAdr<Data>::HashTableClsAdr(const ulong dim, const TraversableContainer<Data> &con)
    {
        if (!con.Empty())
        {
            if (dim < 64)
                tablesize = 128;
            else
                tablesize = dim;

            Table.Resize(tablesize);

            con.Traverse([this](const Data dat)
                         { this->Insert(dat); });
        }
    }

    // Specific constructors (from a MappableContainer)

    template <typename Data>
    HashTableClsAdr<Data>::HashTableClsAdr(MappableContainer<Data> &&con)
    {
        if (!con.Empty())
        {
            if (con.Size() < 64)
                tablesize = 128;
            else
                tablesize = con.Size() * 2;

            Table.Resize(tablesize);

            con.Map([this](Data dat)
                    { this->Insert(move(dat)); });
        }
    }

    template <typename Data>
    HashTableClsAdr<Data>::HashTableClsAdr(const ulong dim, MappableContainer<Data> &&con)
    {
        if (!con.Empty())
        {
            if (dim < 64)
                tablesize = 128;
            else
                tablesize = dim;

            Table.Resize(tablesize);

            con.Map([this](const Data dat)
                    { this->Insert(move(dat)); });
        }
    }

    /* ************************************************************************** */

    // Copy constructor
    template <typename Data>
    HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr &htc)
    {

        if (htc.Size() > 0)
        {
            Table.Resize(htc.tablesize);
            tablesize = htc.tablesize;

            htc.Table.Traverse([this](const BST<Data> bst)
                               {
                        if (!bst.Empty())
                            {
                                 bst.Traverse([this](const Data dat)
                                        { 
                                        this->Insert(dat);
                                         });
                            } });
        }
        else
            this->Clear();
    }

    // Move constructor
    template <typename Data>
    HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr &&htc) noexcept
    {
        swap(this->acf, htc.acf);
        swap(this->bcf, htc.bcf);
        swap(size, htc.size);
        swap(Table, htc.Table);
        swap(tablesize, htc.tablesize);
    }

    /* ************************************************************************** */

    // Copy assignment
    template <typename Data>
    HashTableClsAdr<Data> &HashTableClsAdr<Data>::operator=(const HashTableClsAdr &htc)
    {

        if (htc.Size() > 0)
        {
            Table.Resize(htc.tablesize);
            tablesize = htc.tablesize;

            htc.Table.Traverse([this](const BST<Data> bst)
                               {
                        if (!bst.Empty())
                            {
                                 bst.Traverse([this](const Data dat)
                                        { 
                                        this->Insert(dat);
                                         });
                            } });
        }
        else
            this->Clear();

        return *this;
    }

    // Move assignment
    template <typename Data>
    HashTableClsAdr<Data> &HashTableClsAdr<Data>::operator=(HashTableClsAdr &&htc) noexcept
    {
        swap(this->acf, htc.acf);
        swap(this->bcf, htc.bcf);
        swap(size, htc.size);
        swap(Table, htc.Table);
        swap(tablesize, htc.tablesize);

        return *this;
    }

    /* ************************************************************************ */

    // Comparison operators
    template <typename Data>
    bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr &htc) const noexcept
    {
        bool chk = true;

        if (size == htc.size)
        {
            this->Table.Traverse([&htc, &chk](const BST<Data> bst)
                                 {
                                     if (!(bst.Empty()))
                                     {
                                         bst.Traverse([&htc, &chk](const Data dat){
                                                       chk &= htc.Exists(dat); 
                                                        });

                                     } });
            return chk;
        }
        else
            return false;
    }

    template <typename Data>
    bool HashTableClsAdr<Data>::operator!=(const HashTableClsAdr &htc) const noexcept
    {
        return !(*this == htc);
    }

    /* *************************************************************************** */

    // Specific member functions (inherited from DictionaryContainer)
    template <typename Data>
    bool HashTableClsAdr<Data>::Insert(const Data &dat)
    {

        if (Table[HashKey(dat)].Insert(dat))
        {
            size++;
            return true;
        }
        else
            return false;
    }

    template <typename Data>
    bool HashTableClsAdr<Data>::Insert(Data &&dat)
    {
        if (Table[HashKey(move(dat))].Insert(move(dat)))
        {
            size++;
            return true;
        }
        else
            return false;
    }

    template <typename Data>
    bool HashTableClsAdr<Data>::Remove(const Data &dat)
    {
        if (Table[HashKey(dat)].Remove(dat))
        {
            size--;
            return true;
        }
        else
            return false;
    }

    /* ************************************************************************** */

    // Specific member functions (inherited from TestableContainer)
    template <typename Data>
    bool HashTableClsAdr<Data>::Exists(const Data &dat) const noexcept
    {
        if (!(this->Empty()))
        {
            return Table[HashKey(dat)].Exists(dat);
        }

        return false;
    }

    // Specific member functions (inherited from ResizableContainer)
    template <typename Data>
    void HashTableClsAdr<Data>::Resize(const ulong dim)
    {
        if (dim > 0)
        {
            HashTableClsAdr<Data> newtable(dim);

            newtable.acf = this->acf;
            newtable.bcf = this->bcf;

            Table.Traverse([&newtable, this](const BST<Data> bst)
                           {
                        if (!bst.Empty())
                            {
                                 bst.Traverse([&newtable](const Data dat)
                                        { 
                                        if(newtable.Table[newtable.HashKey(dat)].Insert(dat))
                                        newtable.size++; });
                            } });

            swap(Table, newtable.Table);
            swap(tablesize, newtable.tablesize);
            swap(size, newtable.size);
        }
        else
            this->Clear();
    }

    // Specific member functions (inherited from ClearableContainer)
    template <typename Data>
    void HashTableClsAdr<Data>::Clear()
    {
        HashTableClsAdr<Data> newtable(128);

        swap(Table, newtable.Table);
        swap(tablesize, newtable.tablesize);
        swap(size, newtable.size);
    }
}
