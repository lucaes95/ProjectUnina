
namespace lasd
{

    /* ************************************************************************** */

    // move constructor
    template <typename Data>
    StackVec<Data>::StackVec(StackVec &&stk) noexcept : Vector<Data>(std::move(stk))
    {
        std::swap(index, stk.index);
    };

    // copy & move assigment operator
    template <typename Data>
    StackVec<Data> &StackVec<Data>::operator=(const StackVec<Data> &stk)
    {
        Vector<Data>::operator=(stk);
        index = stk.index;
        return *this;
    };

    template <typename Data>
    StackVec<Data> &StackVec<Data>::operator=(StackVec<Data> &&stk) noexcept
    {
        Vector<Data>::operator=(std::move(stk));
        std::swap(index, stk.index);
        return *this;
    };

    // comparison operetaor
    template <typename Data>
    bool StackVec<Data>::operator==(const StackVec<Data> &stk) const noexcept
    {
        if (index == stk.index)
        {
            for (ulong cindex = 0; cindex < index; ++cindex)
            {
                if (Elements[cindex] != stk.Elements[cindex])
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
    }

    template <typename Data>
    bool StackVec<Data>::operator!=(const StackVec<Data> &stk) const noexcept
    {
        return !(*this == stk);
    }

    /* ************************************************************************** */

    template <typename Data>
    Data const &StackVec<Data>::Top() const
    {
        if (index != 0)
        {
            return Elements[index - 1];
        }
        else
        {
            throw std::length_error("Acess to an empty stack");
        }
    }

    template <typename Data>
    Data &StackVec<Data>::Top()
    {
        if (index != 0)
        {
            return Elements[index - 1];
        }
        else
        {
            throw std::length_error("Acess to an empty stack");
        }
    }

    template <typename Data>
    void StackVec<Data>::Pop()
    {
        if (index != 0)
        {
            Reduce();
            index--;
        }
        else
            throw std::length_error("Acess to an empty stack");
    }

    template <typename Data>
    Data StackVec<Data>::TopNPop()
    {
        if (index != 0)
        {
            Reduce();
            return std::move(Elements[--index]);
        }
        else
            throw std::length_error("Acess to an empty stack");
    }

    template <typename Data>
    void StackVec<Data>::Push(const Data &dat)
    {
        Expand();
        Elements[index] = dat;
        index++;
    }

    template <typename Data>
    void StackVec<Data>::Push(Data &&dat)
    {
        Expand();
        Elements[index] = std::move(dat);
        index++;
    }

    /* ************************************************************************** */

    // Empty & Size
    template <typename Data>
    inline bool StackVec<Data>::Empty() const noexcept
    {
        return (index == 0);
    }

    template <typename Data>
    inline ulong StackVec<Data>::Size() const noexcept
    {
        return index;
    }

    /* ************************************************************************** */

    template <typename Data>
    void StackVec<Data>::Clear()
    {
        index = 0;
        Vector<Data>::Resize(1);
    }

    /* ************************************************************************** */

    template <typename Data>
    void StackVec<Data>::Expand()
    {
        if (index == size)
            Vector<Data>::Resize(size * 2);
    }

    template <typename Data>
    void StackVec<Data>::Reduce()
    {
        if (index == size / 4)
            Vector<Data>::Resize(size / 2);
    }

    /* ************************************************************************** */

}
