#include "linear.hpp"

namespace lasd
{

    /* ***********************TRAVERSE*************************************************** */

    // comparison operator
    template <typename Data>
    bool LinearContainer<Data>::operator==(const LinearContainer &con) const noexcept
    {
        bool chk = true;
        if (size != con.size)
        {
            chk = false;
        }
        for (ulong index = 0; index < size; ++index)
        {
            if (operator[](index) != con.operator[](index))
                chk = false;
        }
        return chk;
    }

    template <typename Data>
    bool LinearContainer<Data>::operator!=(const LinearContainer &con) const noexcept
    {
        return !(*this == con);
    }

    template <typename Data>
    inline void LinearContainer<Data>::Traverse(TraverseFun fun) const
    {
        for (ulong index = 0; index < size; ++index)
        {
            fun(operator[](index));
        }
    }

    template <typename Data>
    inline void LinearContainer<Data>::PreOrderTraverse(TraverseFun fun) const
    {
        for (ulong index = 0; index < size; ++index)
        {
            fun(operator[](index));
        }
    }

    template <typename Data>
    inline void LinearContainer<Data>::PostOrderTraverse(TraverseFun fun) const
    {
        ulong index = size;
        while (index > 0)
        {
            --index;
            fun(operator[](index));
        }
    }

    template <typename Data>
    void LinearContainer<Data>::Map(MapFun fun)
    {
        for (ulong index = 0; index < size; ++index)
        {
            fun(operator[](index));
        }
    }

    template <typename Data>
    inline void LinearContainer<Data>::PreOrderMap(MapFun fun)
    {
        for (ulong index = 0; index < size; ++index)
        {
            fun(operator[](index));
        }
    }

    template <typename Data>
    inline void LinearContainer<Data>::PostOrderMap(MapFun fun)
    {
        ulong index = size;
        while (index > 0)
        {
            --index;
            fun(operator[](index));
        }
    }

    // Front() & Back()
    template <typename Data>
    const Data &LinearContainer<Data>::Front() const
    {
        if (size > 0)
            return operator[](0);
        else
            throw std::length_error("Acces to an empty linear struct");
    }

    template <typename Data>
    Data &LinearContainer<Data>::Front()
    {
        if (size > 0)
            return operator[](0);
        else
            throw std::length_error("Acces to an empty linear struct");
    }

    // Front() & Back()
    template <typename Data>
    const Data &LinearContainer<Data>::Back() const
    {
        if (size > 0)
            return operator[](size - 1);
        else
            throw std::length_error("Acces to an empty linear struct");
    }

    template <typename Data>
    Data &LinearContainer<Data>::Back()
    {
        if (size > 0)
            return operator[](size - 1);
        else
            throw std::length_error("Acces to an empty linear struct");
    }

    /* ************************************************************************** */

    template <typename Data>
    void SortableLinearContainer<Data>::Sort() noexcept
    {
        MergeSort(0, size - 1);
    }

    /* ************************************************************************** */

    // Auxiliar function
    template <typename Data>
    void SortableLinearContainer<Data>::MergeSort(ulong l, ulong r) noexcept
    {
        if (l < r)
        {
            int m = l + (r - l) / 2;
            MergeSort(l, m);
            MergeSort(m + 1, r);

            Merge(l, m, r);
        }
    }

    template <typename Data>
    void SortableLinearContainer<Data>::Merge(ulong l, ulong m, ulong r) noexcept
    {
        ulong n1 = m - l + 1;
        ulong n2 = r - m;

        Data *leftarray = new Data[n1]{};
        Data *rightarray = new Data[n2]{};

        ulong tmpindex = 0;
        ulong index, jndex = 0;

        tmpindex = l;

        for (index = 0; index < n1; index++)
        {
            leftarray[index] = this->operator[](tmpindex++);
        }

        tmpindex = m + 1;

        for (index = 0; index < n2; index++)
        {
            rightarray[index] = this->operator[](tmpindex++);
        }

        index = 0;
        ulong indexarr = l;

        while ((index < n1) && (jndex < n2))
        {
            if (leftarray[index] <= rightarray[jndex])
            {
                this->operator[](indexarr) = leftarray[index];
                index++;
            }
            else
            {
                this->operator[](indexarr) = rightarray[jndex];
                jndex++;
            }
            indexarr++;
        }

        while (index < n1)
        {
            this->operator[](indexarr) = leftarray[index];
            indexarr++;
            index++;
        }

        while (jndex < n2)
        {
            this->operator[](indexarr) = rightarray[jndex];
            indexarr++;
            jndex++;
        }

        delete[] rightarray;
        delete[] leftarray;
    }
}
