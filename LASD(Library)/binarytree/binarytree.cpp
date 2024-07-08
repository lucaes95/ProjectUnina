#include "binarytree.hpp"

namespace lasd
{

    // Comparison Operator Node
    template <typename Data>
    bool BinaryTree<Data>::Node::operator==(const Node &nod) const noexcept
    {
        return ((Element() = nod.Element()) && (((LeftChild() == nullptr && nod.LeftChild() == nullptr) || (LeftChild() != nullptr && nod.LeftChild() != nullptr)) && ((RightChild() == nullptr && nod.RightChild() == nullptr) || (RightChild() != nullptr && nod.RightChild() != nullptr))));
    }

    template <typename Data>
    bool BinaryTree<Data>::Node::operator!=(const Node &nod) const noexcept
    {
        return !(*this == nod);
    }

    /* ************************************************************************** */

    // Comparison Operator
    template <typename Data>
    bool BinaryTree<Data>::operator==(const BinaryTree &tree) const noexcept
    {

        bool chk = true;
        if (size == tree.Size())
        {

            BTBreadthIterator<Data> itr(*this);
            BTBreadthIterator<Data> itr2(tree);

            for (ulong index = 0; index < size; index++)
            {
                if (*itr != *itr2)
                    chk = false;

                ++itr;
                ++itr2;
            }
        }
        else
            chk = false;

        return chk;
    }

    template <typename Data>
    bool BinaryTree<Data>::operator!=(const BinaryTree &tree) const noexcept
    {
        return !(*this == tree);
    }

    // Specific member function (inherited from TraversableContainer)
    template <typename Data>
    inline void BinaryTree<Data>::Traverse(TraverseFun fun) const
    {
        if (!(this->Empty()))
            PreOrderTraverse(fun);
    }

    template <typename Data>
    inline void BinaryTree<Data>::PreOrderTraverse(TraverseFun fun) const
    {
        if (!(this->Empty()))
            PreOrderTraverseRicorsive(fun, Root());
    }

    template <typename Data>
    inline void BinaryTree<Data>::PostOrderTraverse(TraverseFun fun) const
    {
        if (!(this->Empty()))
            PostOrderTraverseRicorsive(fun, Root());
    }

    template <typename Data>
    inline void BinaryTree<Data>::InOrderTraverse(TraverseFun fun) const
    {
        if (!(this->Empty()))
            InOrderTraverseRicorsive(fun, Root());
    }

    template <typename Data>
    inline void BinaryTree<Data>::BreadthTraverse(TraverseFun fun) const
    {
        if (!(this->Empty()))
            BreadthTraverse(fun, Root());
    }

    // Auxiliary functions
    template <typename Data>
    void BinaryTree<Data>::PreOrderTraverseRicorsive(TraverseFun fun, const Node &tmproot) const
    {
        fun(tmproot.Element());
        if (tmproot.HasLeftChild())
            PreOrderTraverseRicorsive(fun, tmproot.LeftChild());
        if (tmproot.HasRightChild())
            PreOrderTraverseRicorsive(fun, tmproot.RightChild());
    }

    template <typename Data>
    void BinaryTree<Data>::PostOrderTraverseRicorsive(TraverseFun fun, const Node &tmproot) const
    {
        if (tmproot.HasLeftChild())
            PostOrderTraverseRicorsive(fun, tmproot.LeftChild());
        if (tmproot.HasRightChild())
            PostOrderTraverseRicorsive(fun, tmproot.RightChild());
        fun(tmproot.Element());
    }

    template <typename Data>
    void BinaryTree<Data>::InOrderTraverseRicorsive(TraverseFun fun, const Node &tmproot) const
    {
        if (tmproot.HasLeftChild())
            InOrderTraverseRicorsive(fun, tmproot.LeftChild());
        fun(tmproot.Element());
        if (tmproot.HasRightChild())
            InOrderTraverseRicorsive(fun, tmproot.RightChild());
    }

    template <typename Data>
    void BinaryTree<Data>::BreadthTraverse(TraverseFun fun, const Node &tmproot) const
    {
        const Node *curr = &tmproot;

        QueueLst<const Node *> que;

        que.Enqueue(curr);

        while (que.Size() != 0)
        {
            curr = que.HeadNDequeue();
            fun(curr->Element());

            if (curr->HasLeftChild())
                que.Enqueue(&curr->LeftChild());
            if (curr->HasRightChild())
                que.Enqueue(&curr->RightChild());
        }
    }

    /* ************************************************************************** */

    template <typename Data>
    inline void MutableBinaryTree<Data>::Map(MapFun fun)
    {
        PreOrderMap(fun);
    }

    template <typename Data>
    inline void MutableBinaryTree<Data>::PreOrderMap(MapFun fun)
    {
        PreOrderMapRicorsive(fun, Root());
    }

    template <typename Data>
    inline void MutableBinaryTree<Data>::PostOrderMap(MapFun fun)
    {
        PostOrderMapRicorsive(fun, Root());
    }

    template <typename Data>
    inline void MutableBinaryTree<Data>::InOrderMap(MapFun fun)
    {
        InOrderMapRicorsive(fun, Root());
    }

    template <typename Data>
    inline void MutableBinaryTree<Data>::BreadthMap(MapFun fun)
    {
        BreadthMap(fun, Root());
    }

    // Auxiliary functions
    template <typename Data>
    void MutableBinaryTree<Data>::PreOrderMapRicorsive(MapFun fun, MutableNode &tmproot)
    {
        fun(tmproot.Element());
        if (tmproot.HasLeftChild())
            PreOrderMapRicorsive(fun, tmproot.LeftChild());
        if (tmproot.HasRightChild())
            PreOrderMapRicorsive(fun, tmproot.RightChild());
    }

    template <typename Data>
    void MutableBinaryTree<Data>::PostOrderMapRicorsive(MapFun fun, MutableNode &tmproot)
    {
        if (tmproot.HasLeftChild())
            PostOrderMapRicorsive(fun, tmproot.LeftChild());
        if (tmproot.HasRightChild())
            PostOrderMapRicorsive(fun, tmproot.RightChild());
        fun(tmproot.Element());
    }

    template <typename Data>
    void MutableBinaryTree<Data>::InOrderMapRicorsive(MapFun fun, MutableNode &tmproot)
    {
        if (tmproot.HasLeftChild())
            InOrderMapRicorsive(fun, tmproot.LeftChild());
        fun(tmproot.Element());
        if (tmproot.HasRightChild())
            InOrderMapRicorsive(fun, tmproot.RightChild());
    }

    template <typename Data>
    void MutableBinaryTree<Data>::BreadthMap(MapFun fun, MutableNode &tmproot)
    {
        MutableNode *curr = &tmproot;

        QueueLst<MutableNode *> que;

        que.Enqueue(curr);

        while (que.Size() != 0)
        {
            curr = que.HeadNDequeue();
            fun(curr->Element());

            if (curr->HasLeftChild())
                que.Enqueue(&curr->LeftChild());
            if (curr->HasRightChild())
                que.Enqueue(&curr->RightChild());
        }
    }
    /* ************************************************************************** */

    template <typename Data>
    BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data> &tree)
    {
        if (tree.Size() != 0)
        {
            root = &tree.Root();
            current = root;
        }
    }

    template <typename Data>
    BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator<Data> &itr)
    {
        current = itr.current;
        root = itr.root;
        stk = itr.stk;
    }

    template <typename Data>
    BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator &&itr) noexcept
    {
        swap(current, itr.current);
        swap(root, itr.root);
        swap(stk, itr.stk);
    }

    // Copy & Move assignment BTPreOrderIterator
    template <typename Data>
    BTPreOrderIterator<Data> &BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator &itr)
    {
        current = itr.current;
        root = itr.root;
        stk = itr.stk;

        return *this;
    }

    template <typename Data>
    BTPreOrderIterator<Data> &BTPreOrderIterator<Data>::operator=(BTPreOrderIterator &&itr) noexcept
    {
        swap(current, itr.current);
        swap(root, itr.root);
        swap(stk, itr.stk);

        return *this;
    }

    // Operator *()
    template <typename Data>
    const Data &BTPreOrderIterator<Data>::operator*() const
    {
        if (current != nullptr)
        {
            return current->Element();
        }
        else
            throw std::out_of_range("Iterator is terminated.");
    };

    // Terminated
    template <typename Data>
    bool BTPreOrderIterator<Data>::Terminated() const noexcept
    {
        return (current == nullptr);
    }

    /* ************************************************************************** */

    // Copy & Move assignment BTPreOrderIterator
    template <typename Data>
    BTPreOrderMutableIterator<Data> &BTPreOrderMutableIterator<Data>::operator=(const BTPreOrderMutableIterator &itr)
    {
        BTPreOrderIterator<Data>::operator=(itr);
    }

    template <typename Data>
    BTPreOrderMutableIterator<Data> &BTPreOrderMutableIterator<Data>::operator=(BTPreOrderMutableIterator &&itr) noexcept
    {
        BTPreOrderIterator<Data>::operator=(move(itr));
    }

    /* ************************************************************************** */

    template <typename Data>
    BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data> &tree)
    {
        bool flag = false;

        if (tree.Size() != 0)
        {
            root = &tree.Root();
            tmpnode = root;
            while (!flag && (tmpnode != nullptr || stk.Size() != 0))
            {
                if (tmpnode != nullptr)
                {
                    stk.Push(tmpnode);

                    if (tmpnode->HasLeftChild())
                        tmpnode = &tmpnode->LeftChild();
                    else
                        tmpnode = nullptr;
                }
                else
                {
                    tmpnode = stk.Top();
                    if (!(tmpnode->HasRightChild()))
                    {
                        current = tmpnode;
                        flag = true;
                        stk.Pop();
                        tmpnode = nullptr;
                    }
                    else
                        tmpnode = &tmpnode->RightChild();
                }
            }
        }
    }

    template <typename Data>
    BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator &itr)
    {
        current = itr.current;
        root = itr.root;
        tmpnode = itr.tmpnode;
        stk = itr.stk;
    }

    template <typename Data>
    BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator &&itr) noexcept
    {
        swap(current, itr.current);
        swap(root, itr.root);
        swap(tmpnode, itr.tmpnode);
        swap(stk, itr.stk);
    }

    // Copy & Move assignment BTPreOrderIterator
    template <typename Data>
    BTPostOrderIterator<Data> &BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator &itr)
    {
        current = itr.current;
        root = itr.root;
        stk = itr.stk;
        tmpnode = itr.tmpnode;

        return *this;
    }

    template <typename Data>
    BTPostOrderIterator<Data> &BTPostOrderIterator<Data>::operator=(BTPostOrderIterator &&itr) noexcept
    {
        swap(current, itr.current);
        swap(root, itr.root);
        swap(stk, itr.stk);
        swap(tmpnode, itr.tmpnode);

        return *this;
    }

    // Operator *()
    template <typename Data>
    const Data &BTPostOrderIterator<Data>::operator*() const
    {
        if (current != nullptr)
        {
            return current->Element();
        }
        else
            throw std::out_of_range("Iterator is terminated.");
    }

    // Terminated
    template <typename Data>
    bool BTPostOrderIterator<Data>::Terminated() const noexcept
    {
        return (current == nullptr);
    }

    /* ************************************************************************** */

    // Copy & Move assignment BTPreOrderIterator
    template <typename Data>
    BTPostOrderMutableIterator<Data> &BTPostOrderMutableIterator<Data>::operator=(const BTPostOrderMutableIterator &itr)
    {
        BTPostOrderIterator<Data>::operator=(itr);
    }

    template <typename Data>
    BTPostOrderMutableIterator<Data> &BTPostOrderMutableIterator<Data>::operator=(BTPostOrderMutableIterator &&itr) noexcept
    {
        BTPostOrderIterator<Data>::operator=(std::move(itr));
    }

    /* ************************************************************************** */

    template <typename Data>
    BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data> &tree)
    {

        if (tree.Size() != 0)
        {
            root = &tree.Root();
            current = root;
            tmpnode = current;
            bool flag = false;

            while (!flag)
            {
                if (tmpnode != nullptr)
                {

                    stk.Push(tmpnode);
                    if (tmpnode->HasLeftChild())
                        tmpnode = &tmpnode->LeftChild();
                    else
                        tmpnode = nullptr;
                }
                else
                {
                    current = stk.TopNPop();

                    if (current->HasRightChild())
                        stk.Push(&current->RightChild());

                    flag = true;
                    tmpnode = nullptr;
                }
            }
        }
    }

    template <typename Data>
    BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator &itr)
    {
        current = itr.current;
        root = itr.root;
        tmpnode = itr.tmpnode;
        stk = itr.stk;
    }

    template <typename Data>
    BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator &&itr) noexcept
    {
        swap(current, itr.current);
        swap(root, itr.root);
        swap(stk, itr.stk);
        swap(tmpnode, itr.tmpnode);
    }

    // Copy & Move assignment BTPreOrderIterator
    template <typename Data>
    BTInOrderIterator<Data> &BTInOrderIterator<Data>::operator=(const BTInOrderIterator &itr)
    {
        current = itr.current;
        root = itr.root;
        stk = itr.stk;
        tmpnode = itr.tmpnode;

        return *this;
    }

    template <typename Data>
    BTInOrderIterator<Data> &BTInOrderIterator<Data>::operator=(BTInOrderIterator &&itr) noexcept
    {
        swap(current, itr.current);
        swap(root, itr.root);
        swap(stk, itr.stk);
        swap(tmpnode, itr.tmpnode);

        return *this;
    }

    // Operator *()
    template <typename Data>
    const Data &BTInOrderIterator<Data>::operator*() const
    {
        if (current != nullptr)
        {
            return current->Element();
        }
        else
            throw std::out_of_range("Iterator is terminated.");
    }

    // Terminated
    template <typename Data>
    bool BTInOrderIterator<Data>::Terminated() const noexcept
    {
        return (current == nullptr);
    }

    /* ************************************************************************** */

    // Copy & Move assignment BTPreOrderIterator
    template <typename Data>
    BTInOrderMutableIterator<Data> &BTInOrderMutableIterator<Data>::operator=(const BTInOrderMutableIterator &itr)
    {
        BTInOrderIterator<Data>::operator=(itr);
    }

    template <typename Data>
    BTInOrderMutableIterator<Data> &BTInOrderMutableIterator<Data>::operator=(BTInOrderMutableIterator &&itr) noexcept
    {
        BTInOrderIterator<Data>::operator=(std::move(itr));
    }

    /* ************************************************************************** */

    template <typename Data>
    BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data> &tree)
    {

        if (tree.Size() != 0)
        {
            root = &tree.Root();
            current = root;

            if (current->HasLeftChild())
                que.Enqueue(&current->LeftChild());
            if (current->HasRightChild())
                que.Enqueue(&current->RightChild());
        }
    }

    template <typename Data>
    BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator &itr)
    {
        current = itr.current;
        que = itr.que;
        root = itr.root;
    }

    template <typename Data>
    BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator &&itr) noexcept
    {
        swap(current, itr.current);
        swap(que, itr.que);
        swap(root, itr.root);
    }

    // Copy & Move assignment BTPreOrderIterator
    template <typename Data>
    BTBreadthIterator<Data> &BTBreadthIterator<Data>::operator=(const BTBreadthIterator &itr)
    {
        current = itr.current;
        que = itr.que;
        root = itr.root;

        return *this;
    }

    template <typename Data>
    BTBreadthIterator<Data> &BTBreadthIterator<Data>::operator=(BTBreadthIterator &&itr) noexcept
    {
        swap(current, itr.current);
        swap(que, itr.que);
        swap(root, itr.root);

        return *this;
    }

    // Operator *()
    template <typename Data>
    const Data &BTBreadthIterator<Data>::operator*() const
    {
        if (current != nullptr)
        {
            return current->Element();
        }
        else
            throw std::out_of_range("Iterator is terminated.");
    }

    // Terminated
    template <typename Data>
    bool BTBreadthIterator<Data>::Terminated() const noexcept
    {
        return (current == nullptr);
    }

    /* ************************************************************************** */

    // Copy & Move assignment BTPreOrderIterator
    template <typename Data>
    BTBreadthMutableIterator<Data> &BTBreadthMutableIterator<Data>::operator=(const BTBreadthMutableIterator &itr)
    {
        BTBreadthIterator<Data>::operator=(itr);
    }

    template <typename Data>
    BTBreadthMutableIterator<Data> &BTBreadthMutableIterator<Data>::operator=(BTBreadthMutableIterator &&itr) noexcept
    {
        BTBreadthIterator<Data>::operator=(std::move(itr));
    }

}
