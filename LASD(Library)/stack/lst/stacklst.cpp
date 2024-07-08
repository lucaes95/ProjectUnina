
namespace lasd
{

    /* ************************************************************************** */

    // copy & move assignment operator
    template <typename Data>
    StackLst<Data> StackLst<Data>::operator=(const StackLst &stk)
    {
        List<Data>::operator=(stk);
        return *this;
    }

    template <typename Data>
    StackLst<Data> StackLst<Data>::operator=(StackLst &&stk) noexcept
    {
        List<Data>::operator=(std::move(stk));
        return *this;
    }

    // comparison operator
    template <typename Data>
    bool StackLst<Data>::operator==(const StackLst &stk) const noexcept
    {
        return List<Data>::operator==(stk);
    }

    template <typename Data>
    bool StackLst<Data>::operator!=(const StackLst &stk) const noexcept
    {
        return !(*this == stk);
    }

    /* ************************************************************************** */

    template <typename Data>
    Data const &StackLst<Data>::Top() const
    {
        return List<Data>::Front();
    }

    template <typename Data>
    Data &StackLst<Data>::Top()
    {
        return List<Data>::Front();
    }

    template <typename Data>
    void StackLst<Data>::Pop()
    {
        List<Data>::RemoveFromFront();
    }

    template <typename Data>
    Data StackLst<Data>::TopNPop()
    {
        return List<Data>::FrontNRemove();
    }

    template <typename Data>
    void StackLst<Data>::Push(const Data &dat)
    {
        List<Data>::InsertAtFront(dat);
    }

    template <typename Data>
    void StackLst<Data>::Push(Data &&dat)
    {
        List<Data>::InsertAtFront(std::move(dat));
    }

    /* ************************************************************************** */

}
