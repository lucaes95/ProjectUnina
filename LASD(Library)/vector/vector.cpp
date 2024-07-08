
#include <iostream>

#include "vector.hpp"

using namespace std;

namespace lasd
{

    /* ************************************************************************** */

    template <typename Data>
    Vector<Data>::Vector(const ulong dim)
    {
        Elements = new Data[dim]{};
        size = dim;
    }

    template <typename Data>
    Vector<Data>::Vector(const TraversableContainer<Data> &con) : Vector(con.Size())
    {
        ulong index = 0;

        con.Traverse(
            [this, &index](const Data &dat)
            {
                Elements[index++] = dat;
            });
    }

    template <typename Data>
    Vector<Data>::Vector(MappableContainer<Data> &&con) : Vector(con.Size())
    {
        ulong index = 0;
        con.Map([this, &index](Data &dat)
                { Elements[index++] = move(dat); });
    }

    // copy constructor
    template <typename Data>
    Vector<Data>::Vector(const Vector<Data> &vec)
    {
        Elements = new Data[vec.size];
        copy(vec.Elements, vec.Elements + vec.size, Elements);
        size = vec.size;
    }

    // move constructor
    template <typename Data>
    Vector<Data>::Vector(Vector<Data> &&vec) noexcept
    {
        swap(Elements, vec.Elements);
        swap(size, vec.size);
    }

    // destructor
    template <typename Data>
    Vector<Data>::~Vector()
    {
        delete[] Elements;
    }

    // copy assignment
    template <typename Data>
    Vector<Data> &Vector<Data>::operator=(const Vector<Data> &vec)
    {
        Vector<Data> *tmpvec = new Vector<Data>(vec);
        swap(*tmpvec, *this);
        delete tmpvec;
        return *this;
    }

    // move assignment
    template <typename Data>
    Vector<Data> &Vector<Data>::operator=(Vector<Data> &&vec) noexcept
    {
        swap(Elements, vec.Elements);
        swap(size, vec.size);
        return *this;
    }

    // comparison operator ==
    template <typename Data>
    bool Vector<Data>::operator==(const Vector<Data> &vec) const noexcept
    {
        if (size == vec.size && size == 0)
        {
            return true;
        }
        else if (size != vec.size)
        {
            return false;
        }
        else
        {
            for (ulong i = 0; i < size; i++)
            {
                if (Elements[i] != vec.Elements[i])
                    return false;
            }
        }
        return true;
    }

    // comparison operator !=
    template <typename Data>
    bool Vector<Data>::operator!=(const Vector<Data> &vec) const noexcept
    {
        return !(*this == vec);
    }

    // override Clear() Container
    template <typename Data>
    void Vector<Data>::Clear()
    {
        delete[] Elements;
        Elements = nullptr;
        size = 0;
    }

    // override Resize(ulong) Container
    template <typename Data>
    void Vector<Data>::Resize(const ulong newsize)
    {
        if (newsize == 0)
            Clear();
        else if (size != newsize)
        {
            ulong limit = (size < newsize) ? size : newsize;
            Data *tmpvec = new Data[newsize]{};

            for (ulong index = 0; index < limit; ++index)
            {
                swap(Elements[index], tmpvec[index]);
            }
            swap(Elements, tmpvec);

            delete[] tmpvec;
            size = newsize;
        }
    }

    // operator[]
    template <typename Data>
    inline const Data &Vector<Data>::operator[](ulong index) const
    {
        if (index < size)
        {
            return Elements[index];
        }
        else
        {
            throw std::out_of_range("Access at index " + std::to_string(index) + "; vector size " + std::to_string(size) + ".");
        }
    }

    template <typename Data>
    inline Data &Vector<Data>::operator[](ulong index)
    {
        if (index < size)
        {
            return Elements[index];
        }
        else
        {
            throw std::out_of_range("Access at index " + std::to_string(index) + "; vector size " + std::to_string(size) + ".");
        }
    }

    // Front() & Back()
    template <typename Data>
    const Data &Vector<Data>::Front() const
    {
        if (size > 0)
            return Elements[0];
        else
            throw std::length_error("Acces to an empty vector");
    }

    template <typename Data>
    Data &Vector<Data>::Front()
    {
        if (size > 0)
            return Elements[0];
        else
            throw std::length_error("Acces to an empty vector");
    }

    template <typename Data>
    const Data &Vector<Data>::Back() const
    {
        if (size > 0)
            return Elements[size - 1];
        else
            throw std::length_error("Acces to an empty vector");
    }

    template <typename Data>
    Data &Vector<Data>::Back()
    {
        if (size > 0)
            return Elements[size - 1];
        else
            throw std::length_error("Acces to an empty vector");
    }

    /* ************************************************************************** */

    template <typename Data>
    SortableVector<Data>::SortableVector(const ulong dim) : Vector<Data>(dim) {}

    template <typename Data>
    SortableVector<Data>::SortableVector(const TraversableContainer<Data> &con) : Vector<Data>(con) {}

    template <typename Data>
    SortableVector<Data>::SortableVector(MappableContainer<Data> &&con) : Vector<Data>(move(con)) {}

    // copy constructor
    template <typename Data>
    SortableVector<Data>::SortableVector(const SortableVector<Data> &vec) : Vector<Data>(vec) {}

    // move constructor
    template <typename Data>
    SortableVector<Data>::SortableVector(SortableVector<Data> &&vec) noexcept : Vector<Data>(move(vec)) {}

    // copy assignment
    template <typename Data>
    SortableVector<Data> &SortableVector<Data>::operator=(const SortableVector<Data> &vec)
    {
        Vector<Data>::operator=(vec);
        return *this;
    }

    // move assignment
    template <typename Data>
    SortableVector<Data> &SortableVector<Data>::operator=(SortableVector<Data> &&vec) noexcept
    {
        Vector<Data>::operator=(move(vec));
        return *this;
    }
}
