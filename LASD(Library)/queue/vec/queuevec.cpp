
#include "queuevec.hpp"

namespace lasd
{

    /* ************************************************************************** */

    // constructor specific
    template <typename Data>
    QueueVec<Data>::QueueVec(const TraversableContainer<Data> &con) : Vector<Data>(con), tail(size)
    {
        Vector<Data>::Resize(size * 2);
    }

    template <typename Data>
    QueueVec<Data>::QueueVec(MappableContainer<Data> &&con) : Vector<Data>(std::move(con)), tail(size)
    {
        Vector<Data>::Resize(size * 2);
    }

    // move constructor
    template <typename Data>
    QueueVec<Data>::QueueVec(QueueVec &&que) noexcept : Vector<Data>(std::move(que))
    {
        std::swap(head, que.head);
        std::swap(tail, que.tail);
    }

    // copy e move assignement operator
    template <typename Data>
    QueueVec<Data> &QueueVec<Data>::operator=(const QueueVec<Data> &que)
    {
        Vector<Data>::operator=(que);
        head = que.head;
        tail = que.tail;
        return *this;
    };

    template <typename Data>
    QueueVec<Data> &QueueVec<Data>::operator=(QueueVec<Data> &&que) noexcept
    {
        Vector<Data>::operator=(std::move(que));
        std::swap(head, que.head);
        std::swap(tail, que.tail);
        return *this;
    };

    // comparison operator
    template <typename Data>
    bool QueueVec<Data>::operator==(const QueueVec<Data> &que) const noexcept
    {
        if (Size() == que.Size())
        {
            for (ulong index = head, queindex = que.head; index < tail; ++index %= size, ++queindex %= que.size)
            {
                if (Elements[index] != que.Elements[queindex])
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    };

    template <typename Data>
    bool QueueVec<Data>::operator!=(const QueueVec<Data> &que) const noexcept
    {
        return !(*this == que);
    }

    // specific function override queue
    template <typename Data>
    Data const &QueueVec<Data>::Head() const
    {
        if (head != tail)
        {
            return Elements[head];
        }
        else
        {
            throw std::length_error("Acces to an empty queue");
        }
    }

    template <typename Data>
    Data &QueueVec<Data>::Head()
    {
        if (head != tail)
        {
            return Elements[head];
        }
        else
        {
            throw std::length_error("Acces to an empty queue");
        }
    }

    template <typename Data>
    void QueueVec<Data>::Dequeue()
    {
        if (head != tail)
        {
            Reduce();
            ++head %= size;
        }
        else
        {
            throw std::length_error("Access to an empy Queue");
        }
    }

    template <typename Data>
    Data QueueVec<Data>::HeadNDequeue()
    {
        if (head != tail)
        {
            Reduce();
            Data felement(std::move(Elements[head]));
            ++head %= size;
            return felement;
        }
        else
        {
            throw std::length_error("Access to an empy Queue");
        }
    }

    template <typename Data>
    void QueueVec<Data>::Enqueue(const Data &dat)
    {
        Expand();
        Elements[tail++] = dat;
        tail %= size;
    }

    template <typename Data>
    void QueueVec<Data>::Enqueue(Data &&dat)
    {
        Expand();
        Elements[tail++] = std::move(dat);
        tail %= size;
    }

    // specific function override container & clearcontainer
    template <typename Data>
    inline bool QueueVec<Data>::Empty() const noexcept
    {
        return (head == tail);
    }

    template <typename Data>
    inline ulong QueueVec<Data>::Size() const noexcept
    {
        return (((size + tail) - head) % size);
    }

    template <typename Data>
    void QueueVec<Data>::Clear()
    {
        head = 0;
        tail = 0;
        Vector<Data>::Resize(4);
    }

    // auxialiar function
    template <typename Data>
    void QueueVec<Data>::Expand()
    {
        ulong sizevec = Size();
        if (sizevec + 1 == size)
        {
            Resize((size * 2), sizevec);
        }
    }

    template <typename Data>
    void QueueVec<Data>::Reduce()
    {
        ulong sizevec = Size();
        if (sizevec + 1 == size / 4)
            Resize(size / 2, sizevec);
    }

    template <typename Data>
    void QueueVec<Data>::Resize(ulong newsize, ulong sizevec)
    {

        Data *tmpElements = new Data[newsize]{};

        ulong limit = (sizevec < newsize) ? sizevec : newsize;

        for (ulong hindex = head, tmpindex = 0; tmpindex < limit; ++hindex %= size, ++tmpindex)
        {
            ::swap(Elements[hindex], tmpElements[tmpindex]);
        }

        ::swap(Elements, tmpElements);
        delete[] tmpElements;
        tail = sizevec;
        head = 0;
        size = newsize;
    }

    /* ************************************************************************** */
}