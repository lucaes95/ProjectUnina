
namespace lasd
{

    /* ************************************************************************** */

    // Specific member function (from NodeVec)
    template <typename Data>
    inline Data &BinaryTreeVec<Data>::NodeVec::Element() noexcept
    {
        return Tree->Elements[Index()];
    }

    template <typename Data>
    inline const Data &BinaryTreeVec<Data>::NodeVec::Element() const noexcept
    {
        return Tree->Elements[Index()];
    }

    template <typename Data>
    inline bool BinaryTreeVec<Data>::NodeVec::IsLeaf() const noexcept
    {
        return (2 * Index() + 1 >= Tree->size);
    }

    template <typename Data>
    inline bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept
    {
        return (2 * Index() + 1 < Tree->size);
    }

    template <typename Data>
    inline bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept
    {
        return (2 * Index() + 2 < Tree->size);
    }

    template <typename Data>
    inline const typename BinaryTreeVec<Data>::Node &BinaryTreeVec<Data>::NodeVec::LeftChild() const
    {
        ulong child = 2 * Index() + 1;
        if (child < Tree->size)
        {
            return Tree->Nodes[child];
        }
        else
        {
            throw std::out_of_range("Left child does not exists.");
        }
    }

    template <typename Data>
    inline const typename BinaryTreeVec<Data>::Node &BinaryTreeVec<Data>::NodeVec::RightChild() const
    {
        ulong child = 2 * Index() + 2;
        if (child < Tree->size)
        {
            return Tree->Nodes[child];
        }
        else
        {
            throw std::out_of_range("Left child does not exists.");
        }
    }

    template <typename Data>
    inline typename BinaryTreeVec<Data>::MutableNode &BinaryTreeVec<Data>::NodeVec::LeftChild()
    {
        ulong child = 2 * Index() + 1;
        if (child < Tree->size)
        {
            return Tree->Nodes[child];
        }
        else
        {
            throw std::out_of_range("Left child does not exists.");
        }
    }

    template <typename Data>
    inline typename BinaryTreeVec<Data>::MutableNode &BinaryTreeVec<Data>::NodeVec::RightChild()
    {
        ulong child = 2 * Index() + 2;
        if (child < Tree->size)
        {
            return Tree->Nodes[child];
        }
        else
        {
            throw std::out_of_range("Right child does not exists.");
        }
    }

    /* ************************************************************************** */

    // Auxiliar function(From NodeVec)
    template <typename Data>
    ulong BinaryTreeVec<Data>::NodeVec::Index() const noexcept
    {
        ulong index = 0;

        while (&Tree->Nodes[index] != this)
        {
            index++;
        }

        return index;
    }

    // Specific constructors (From BinaryTreeVec)
    template <typename Data>
    BinaryTreeVec<Data>::BinaryTreeVec(const TraversableContainer<Data> &con)
    {
        if (con.Size() > 0)
        {
            size = con.Size();
            Elements = new Data[size];
            Nodes = new NodeVec[size];

            ulong index = 0;

            con.Traverse([this, &index](const Data &dat)
                         {
                Nodes[index].Tree = this;
                Elements[index] = dat;
                ++index; });
        }
    }

    template <typename Data>
    BinaryTreeVec<Data>::BinaryTreeVec(MappableContainer<Data> &&con)
    {
        if (con.Size() > 0)
        {
            size = con.Size();
            Elements = new Data[size];
            Nodes = new NodeVec[size];

            ulong index = 0;

            con.Traverse([this, &index](const Data &dat)
                         {
                Nodes[index].Tree = this;
                Elements[index] = move(dat);
                ++index; });
        }
    }

    template <typename Data>
    BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data> &btv)
    {
        if (btv.Size() > 0)
        {
            size = btv.Size();
            Elements = new Data[size];
            Nodes = new NodeVec[size];

            ulong index = 0;

            btv.BreadthTraverse([this, &index](const Data &dat)
                                {
                Nodes[index].Tree = this;
                Elements[index] = dat;
                ++index; });
        }
    }

    template <typename Data>
    BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data> &&btv) noexcept
    {
        swap(size, btv.size);
        swap(Elements, btv.Elements);
        swap(Nodes, btv.Nodes);

        if (size > 0)
        {

            ulong index = 0;

            BreadthTraverse([this, &index](const Data &dat)
                            {
                Nodes[index].Tree = this;
                ++index; });
        }
    }

    /* ************************************************************************** */

    template <typename Data>
    BinaryTreeVec<Data>::~BinaryTreeVec()
    {
        delete[] Nodes;
    }

    /* ************************************************************************** */

    // Copy & Move operator assignment
    template <typename Data>
    BinaryTreeVec<Data> &BinaryTreeVec<Data>::operator=(const BinaryTreeVec &btv)
    {

        if (btv.size == 0)
        {
            if (size > 0)
            {
                this->Clear();
            }
        }
        else
        {
            if (btv.size <= size)
            {

                for (ulong index = 0; index < btv.size; ++index)
                {
                    Elements[index] = btv.Elements[index];
                    Nodes[index].Tree = this;
                }
                size = btv.size;
            }
            else
            {
                if (size > 0)
                {
                    this->Clear();
                }

                size = btv.size;
                Elements = new Data[size];
                Nodes = new NodeVec[size];

                for (ulong index = 0; index < btv.size; ++index)
                {
                    Elements[index] = btv.Nodes[index].Element();
                    Nodes[index].Tree = this;
                }
            }
        }

        return *this;
    }

    template <typename Data>
    BinaryTreeVec<Data> &BinaryTreeVec<Data>::operator=(BinaryTreeVec &&btv) noexcept
    {
        swap(Elements, btv.Elements);
        swap(Nodes, btv.Nodes);
        swap(size, btv.size);

        return *this;
    }

    /* ************************************************************************** */

    // Comparison operator
    template <typename Data>
    bool BinaryTreeVec<Data>::operator==(const BinaryTreeVec &btv) const noexcept
    {
        if (size == btv.Size())
        {
            for (uint index = 0; index < btv.Size(); index++)
            {
                if (Nodes[index].Element() != btv.Nodes[index].Element())
                    return false;
            }
        }
        else
            return false;

        return true;
    }

    template <typename Data>
    bool BinaryTreeVec<Data>::operator!=(const BinaryTreeVec &btv) const noexcept
    {
        return !(*this == btv);
    }

    /* ************************************************************************** */

    // Specific member function (From BinaryTreeVec)
    template <typename Data>
    const BinaryTreeVec<Data>::Node &BinaryTreeVec<Data>::Root() const
    {
        if (size > 0)
        {
            return Nodes[0];
        }
        else
            throw std::length_error("Access to node not exists");
    }

    template <typename Data>
    BinaryTreeVec<Data>::MutableNode &BinaryTreeVec<Data>::Root()
    {
        if (size > 0)
        {
            return Nodes[0];
        }
        else
            throw std::length_error("Access to node not exists");
    }

    template <typename Data>
    void BinaryTreeVec<Data>::Clear()
    {
        delete[] Elements;
        delete[] Nodes;

        size = 0;
        Elements = nullptr;
        Nodes = nullptr;
    }

    /* ************************************************************************** */

    // Specific member function (inherited from TraversableContainer)
    template <typename Data>
    inline void BinaryTreeVec<Data>::Traverse(TraverseFun fun) const
    {
        PreOrderTraverse(fun);
    }

    template <typename Data>
    inline void BinaryTreeVec<Data>::PreOrderTraverse(TraverseFun fun) const
    {
        PreOrderTraverseRicorsive(fun, Root());
    }

    template <typename Data>
    inline void BinaryTreeVec<Data>::PostOrderTraverse(TraverseFun fun) const
    {
        PostOrderTraverseRicorsive(fun, Root());
    }

    template <typename Data>
    inline void BinaryTreeVec<Data>::InOrderTraverse(TraverseFun fun) const
    {
        InOrderTraverseRicorsive(fun, Root());
    }

    template <typename Data>
    inline void BinaryTreeVec<Data>::BreadthTraverse(TraverseFun fun) const
    {
        for (ulong index = 0; index < size; index++)
            fun(Elements[index]);
    }

    /* ************************************************************************** */

    // Auxiliary functions (for TraversableContainer)

    template <typename Data>
    void BinaryTreeVec<Data>::PreOrderTraverseRicorsive(TraverseFun fun, const Node &tmproot) const
    {
        fun(tmproot.Element());
        if (tmproot.HasLeftChild())
            PreOrderTraverseRicorsive(fun, tmproot.LeftChild());
        if (tmproot.HasRightChild())
            PreOrderTraverseRicorsive(fun, tmproot.RightChild());
    }

    template <typename Data>
    void BinaryTreeVec<Data>::PostOrderTraverseRicorsive(TraverseFun fun, const Node &tmproot) const
    {
        if (tmproot.HasLeftChild())
            PostOrderTraverseRicorsive(fun, tmproot.LeftChild());
        if (tmproot.HasRightChild())
            PostOrderTraverseRicorsive(fun, tmproot.RightChild());
        fun(tmproot.Element());
    }

    template <typename Data>
    void BinaryTreeVec<Data>::InOrderTraverseRicorsive(TraverseFun fun, const Node &tmproot) const
    {
        if (tmproot.HasLeftChild())
            InOrderTraverseRicorsive(fun, tmproot.LeftChild());
        fun(tmproot.Element());
        if (tmproot.HasRightChild())
            InOrderTraverseRicorsive(fun, tmproot.RightChild());
    }

    /* ************************************************************************** */

    // Specific member function (inherited from MappableContainer)

    template <typename Data>
    inline void BinaryTreeVec<Data>::Map(MapFun fun)
    {
        PreOrderMap(fun);
    }

    template <typename Data>
    inline void BinaryTreeVec<Data>::PreOrderMap(MapFun fun)
    {
        PreOrderMapRicorsive(fun, Root());
    }

    template <typename Data>
    inline void BinaryTreeVec<Data>::PostOrderMap(MapFun fun)
    {
        PostOrderMapRicorsive(fun, Root());
    }

    template <typename Data>
    inline void BinaryTreeVec<Data>::InOrderMap(MapFun fun)
    {
        InOrderMapRicorsive(fun, Root());
    }

    template <typename Data>
    inline void BinaryTreeVec<Data>::BreadthMap(MapFun fun)
    {
        for (ulong index = 0; index < size; index++)
            fun(Elements[index]);
    }

    /* ************************************************************************** */

    // Auxiliary functions (for MappableContainer)
    template <typename Data>
    void BinaryTreeVec<Data>::PreOrderMapRicorsive(MapFun fun, MutableNode &tmproot)
    {
        fun(tmproot.Element());
        if (tmproot.HasLeftChild())
            PreOrderMapRicorsive(fun, tmproot.LeftChild());
        if (tmproot.HasRightChild())
            PreOrderMapRicorsive(fun, tmproot.RightChild());
    }

    template <typename Data>
    void BinaryTreeVec<Data>::PostOrderMapRicorsive(MapFun fun, MutableNode &tmproot)
    {
        if (tmproot.HasLeftChild())
            PostOrderMapRicorsive(fun, tmproot.LeftChild());
        if (tmproot.HasRightChild())
            PostOrderMapRicorsive(fun, tmproot.RightChild());
        fun(tmproot.Element());
    }

    template <typename Data>
    void BinaryTreeVec<Data>::InOrderMapRicorsive(MapFun fun, MutableNode &tmproot)
    {
        if (tmproot.HasLeftChild())
            InOrderMapRicorsive(fun, tmproot.LeftChild());
        fun(tmproot.Element());
        if (tmproot.HasRightChild())
            InOrderMapRicorsive(fun, tmproot.RightChild());
    }
}
