
#include "htopnadr.hpp"

namespace lasd
{

    /* ************************************************************************** */
    template <typename Data>
    HashTableOpnAdr<Data>::HashTableOpnAdr()
    {
        Table.Resize(128);
        state.Resize(128);

        for (ulong i = 0; i < state.Size(); ++i)
        {
            state[i] = 'N';
        }
    }

    template <typename Data>
    HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong dim)
    {
        if (dim > tablesize / 2)
        {
            ulong limit = tablesize;

            if (dim < (tablesize / 4))
            {
                while ((limit / 4) > dim)
                {
                    limit /= 2;
                }
            }
            else if (dim > limit)
            {
                while (dim > limit)
                {
                    limit *= 2;
                }
            }

            tablesize = limit;
            size = 0;

            Table.Resize(tablesize);
            state.Resize(tablesize);

            for (ulong i = 0; i < state.Size(); ++i)
            {
                state[i] = 'N';
            }
        }
        else
            this->Clear();
    }

    // Specific constructors (from a TraversableContainer)
    template <typename Data>
    HashTableOpnAdr<Data>::HashTableOpnAdr(const TraversableContainer<Data> &con)
    {
        if (!con.Empty())
        {

            while (con.Size() > (tablesize / 2))
            {
                tablesize *= 2;
            }

            Table.Resize(tablesize);
            state.Resize(tablesize);

            for (ulong i = 0; i < state.Size(); ++i)
            {
                state[i] = 'N';
            }

            con.Traverse([this](const Data dat)
                         { this->Insert(dat); });
        }
    }

    template <typename Data>
    HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong dim, const TraversableContainer<Data> &con)
    {
        if (!con.Empty())
        {

            while (dim > (tablesize / 2))
            {
                tablesize *= 2;
            }

            Table.Resize(tablesize);
            state.Resize(tablesize);

            for (ulong i = 0; i < state.Size(); ++i)
            {
                state[i] = 'N';
            }

            con.Traverse([this](const Data dat)
                         { this->Insert(dat); });
        }
    }

    // Specific constructors (from a MappableContainer)

    template <typename Data>
    HashTableOpnAdr<Data>::HashTableOpnAdr(MappableContainer<Data> &&con)
    {
        if (!con.Empty())
        {

            while (con.Size() > (tablesize / 2))
            {
                tablesize *= 2;
            }

            Table.Resize(tablesize);
            state.Resize(tablesize);

            for (ulong i = 0; i < state.Size(); ++i)
            {
                state[i] = 'N';
            }

            con.Map([this](Data dat)
                    { this->Insert(move(dat)); });
        }
    }

    template <typename Data>
    HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong dim, MappableContainer<Data> &&con)
    {
        if (!con.Empty())
        {

            while (dim > (tablesize / 2))
            {
                tablesize *= 2;
            }

            Table.Resize(tablesize);
            state.Resize(tablesize);

            for (ulong i = 0; i < state.Size(); ++i)
            {
                state[i] = 'N';
            }

            con.Map([this](Data dat)
                    { this->Insert(move(dat)); });
        }
    }

    /* ************************************************************************** */

    // Copy constructor
    template <typename Data>
    HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr &hto)
    {

        HashTableOpnAdr<Data> newtable((hto.tablesize));

        if (hto.Size() > 0)
        {

            for (ulong index = 0; index < hto.tablesize; ++index)
            {
                if (hto.state[index] == 'I')
                {
                    newtable.Insert(hto.Table[index]);
                }
            }
        }

        swap(Table, newtable.Table);
        swap(tablesize, newtable.tablesize);
        swap(state, newtable.state);
        swap(size, newtable.size);
        swap(cremove, newtable.cremove);
    }

    // Move constructor
    template <typename Data>
    HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr &&hto) noexcept
    {
        swap(Table, hto.Table);
        swap(tablesize, hto.tablesize);
        swap(state, hto.state);
        swap(size, hto.size);
        swap(cremove, hto.cremove);
    }

    /* ************************************************************************ */

    // Copy assignment
    template <typename Data>
    HashTableOpnAdr<Data> &HashTableOpnAdr<Data>::operator=(const HashTableOpnAdr &hto)
    {
        HashTableOpnAdr<Data> newtable(hto.tablesize);

        if (hto.Size() > 0)
        {

            for (ulong index = 0; index < hto.tablesize; ++index)
            {
                if (hto.state[index] == 'I')
                {
                    newtable.Insert(hto.Table[index]);
                }
            }
        }

        swap(*this, newtable);

        return *this;
    }

    // Move assignment
    template <typename Data>
    HashTableOpnAdr<Data> &HashTableOpnAdr<Data>::operator=(HashTableOpnAdr &&hto) noexcept
    {
        swap(Table, hto.Table);
        swap(tablesize, hto.tablesize);
        swap(state, hto.state);
        swap(size, hto.size);
        swap(cremove, hto.cremove);

        return *this;
    }

    /* ************************************************************************ */

    // Comparison operators
    template <typename Data>
    bool HashTableOpnAdr<Data>::operator==(const HashTableOpnAdr &hto) const noexcept
    {
        if (this->size == hto.Size())
        {
            for (ulong index = 0; index < tablesize; ++index)
            {
                if (state[index] == 'I')
                {
                    if (!hto.Exists(Table[index]))
                        return false;
                }
            }
            return true;
        }
        else
            return false;
    }

    template <typename Data>
    bool HashTableOpnAdr<Data>::operator!=(const HashTableOpnAdr &hto) const noexcept
    {
        return !(*this == hto);
    }

    /* ************************************************************************** */

    // Specific member functions (inherited from DictionaryContainer)
    template <typename Data>
    bool HashTableOpnAdr<Data>::Insert(const Data &dat)
    {
        if (size + 1 > tablesize / 2)
            this->Resize(tablesize * 2);

        for (ulong index = 0; index < tablesize; ++index)
        {
            if ((state[HashKey(dat, index)] == 'N'))
            {
                Table[HashKey(dat, index)] = dat;
                state[HashKey(dat, index)] = 'I';
                size++;

                return true;
            }
            else if ((Table[HashKey(dat, index)] == dat) && (state[HashKey(dat, index)] == 'I'))
            {
                return false;
            }
        }
        return false;
    }

    template <typename Data>
    bool HashTableOpnAdr<Data>::Insert(Data &&dat)
    {
        if (size + 1 > tablesize / 2)
            this->Resize(tablesize * 2);

        for (ulong index = 0; index < tablesize; ++index)
        {
            if ((state[HashKey(move(dat), index)] == 'N'))
            {
                Table[HashKey(move(dat), index)] = move(dat);
                state[HashKey(move(dat), index)] = 'I';
                size++;

                return true;
            }
            else if ((Table[HashKey(move(dat), index)] == move(dat)) && (state[HashKey(move(dat), index)] == 'I'))
            {
                return false;
            }
        }
        return false;
    }

    template <typename Data>
    bool HashTableOpnAdr<Data>::Remove(const Data &dat)
    {
        for (ulong index = 0; index < tablesize; ++index)
        {
            if ((state[HashKey(dat, index)] == 'I') && (Table[HashKey(dat, index)] == dat))
            {
                state[HashKey(dat, index)] = 'C';
                cremove++;
                size--;

                if (cremove > tablesize / 4)
                    this->Resize(tablesize / 2);

                return true;
            }
        }
        return false;
    }

    /* ************************************************************************** */

    // Specific member functions (inherited from TestableContainer)
    template <typename Data>
    bool HashTableOpnAdr<Data>::Exists(const Data &dat) const noexcept
    {
        if (!(this->Empty()))
        {
            for (ulong index = 0; index < tablesize; ++index)
            {
                if ((state[HashKey(dat, index)] == 'I') && (Table[HashKey(dat, index)] == dat))
                    return true;
            }
        }

        return false;
    }

    // Specific member functions (inherited from ResizableContainer)
    template <typename Data>
    void HashTableOpnAdr<Data>::Resize(const ulong dim)
    {
        if (dim > 0)
        {
            // Calcolo della nuova dimensione della tabella. Per evitare di saturare memoria. (da migliorare)

            ulong limit = tablesize;

            if (dim < (tablesize / 4))
            {
                while ((limit / 4) > dim)
                {
                    limit /= 2;
                }
            }
            else if (dim > limit)
            {
                while (dim > limit)
                {
                    limit *= 2;
                }
            }

            //

            HashTableOpnAdr<Data> newtable(limit);

            if (this->size > 0)
            {
                for (ulong index = 0; index < tablesize; ++index)
                {
                    if (state[index] == 'I')
                        newtable.Insert(Table[index]);
                }
            }

            swap(*this, newtable);
        }
        else
            this->Clear();
    }

    // Specific member functions (inherited from ClearableContainer)
    template <typename Data>
    void HashTableOpnAdr<Data>::Clear()
    {
        HashTableOpnAdr<Data> newtable(128);

        swap(*this, newtable);
    }
}
