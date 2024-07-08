
namespace lasd
{

    /* ************************************************************************** */

    template <typename Data>
    template <typename Accumulator>
    Accumulator TraversableContainer<Data>::Fold(FoldFun<Accumulator> fun, Accumulator Acc) const
    {
        Traverse([fun, &Acc](const Data &dat)
                 { Acc = fun(dat, Acc); });
        return Acc;
    }

    template <typename Data>
    template <typename Accumulator>
    inline Accumulator PreOrderTraversableContainer<Data>::PreOrderFold(FoldFun<Accumulator> fun, Accumulator Acc) const
    {
        PreOrderTraverse([fun, &Acc](const Data &dat)
                         { Acc = fun(dat, Acc); });
        return Acc;
    }

    template <typename Data>
    template <typename Accumulator>
    inline Accumulator PostOrderTraversableContainer<Data>::PostOrderFold(FoldFun<Accumulator> fun, Accumulator Acc) const
    {
        PostOrderTraverse([fun, &Acc](const Data &dat)
                          { Acc = fun(dat, Acc); });
        return Acc;
    }

    template <typename Data>
    template <typename Accumulator>
    inline Accumulator InOrderTraversableContainer<Data>::InOrderFold(FoldFun<Accumulator> fun, Accumulator Acc) const
    {
        InOrderTraverse([fun, &Acc](const Data &dat)
                        { Acc = fun(dat, Acc); });
        return Acc;
    }

    template <typename Data>
    template <typename Accumulator>
    inline Accumulator BreadthTraversableContainer<Data>::BreadthFold(FoldFun<Accumulator> fun, Accumulator Acc) const
    {
        BreadthTraverse([fun, &Acc](const Data &dat)
                        { Acc = fun(dat, Acc); });
        return Acc;
    }

    template <typename Data>
    inline bool TraversableContainer<Data>::Exists(const Data &val) const noexcept
    {
        bool exists = false;
        Traverse(
            [val, &exists](const Data &dat)
            {
                exists |= (dat == val);
            });
        return exists;
    }

    template <typename Data>
    inline void PreOrderTraversableContainer<Data>::Traverse(TraverseFun fun) const
    {
        PreOrderTraverse(fun);
    }

    template <typename Data>
    inline void PostOrderTraversableContainer<Data>::Traverse(TraverseFun fun) const
    {
        PostOrderTraverse(fun);
    }

    template <typename Data>
    inline void InOrderTraversableContainer<Data>::Traverse(TraverseFun fun) const
    {
        InOrderTraverse(fun);
    }

    template <typename Data>
    inline void BreadthTraversableContainer<Data>::Traverse(TraverseFun fun) const
    {
        BreadthTraverse(fun);
    }

    // ...

    /* ************************************************************************** */

}
