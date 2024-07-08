#include "bst.hpp"

namespace lasd
{

    /* ************************************************************************** */

    // Specific Constructor
    template <typename Data>
    BST<Data>::BST(const TraversableContainer<Data> &con)
    {
        con.Traverse([this](const Data &dat)
                     { this->Insert(dat); });
    }

    template <typename Data>
    BST<Data>::BST(MappableContainer<Data> &&con)
    {
        con.Traverse([this](const Data &dat)
                     { this->Insert(move(dat)); });
    }

    // Copy constructor
    template <typename Data>
    BST<Data>::BST(const BST &bst)
    {

        BTBreadthIterator<Data> itr(bst);

        while (!(itr.Terminated()))
        {
            Insert(*itr);
            ++itr;
        }
    }

    // Move constructor
    template <typename Data>
    BST<Data>::BST(BST &&bst) noexcept
    {
        if (bst.root != nullptr)
        {
            std::swap(root, bst.root);
            std::swap(size, bst.size);
        }
    }

    // Copy assignment
    template <typename Data>
    BST<Data> &BST<Data>::operator=(const BST<Data> &bst)
    {
        if (root == nullptr)
        {
            if (bst.root != nullptr)
                root = new NodeLnk(*bst.root);
        }
        else
        {
            if (bst.root == nullptr)
            {
                delete root;
                root = nullptr;
            }
            else
            {
                *root = *bst.root;
            }
        }
        size = bst.size;

        return *this;
    }

    // Move assignment
    template <typename Data>
    BST<Data> &BST<Data>::operator=(BST<Data> &&bst) noexcept
    {
        swap(size, bst.size);
        swap(root, bst.root);

        return *this;
    }

    // Comparison operators
    template <typename Data>
    bool BST<Data>::operator==(const BST &bst) const noexcept
    {

        if (size == bst.size)
        {
            if (size == 0)
                return true;

            BTInOrderIterator<Data> curitr(*this);
            BTInOrderIterator<Data> curitr2(bst);

            while (!curitr.Terminated())
            {
                if (*curitr != *curitr2)
                    return false;

                ++curitr;
                ++curitr2;
            }
        }
        else
            return false;

        return true;
    }

    template <typename Data>
    bool BST<Data>::operator!=(const BST &bst) const noexcept
    {
        return !(*this == bst);
    }

    /* ************************************************************************** */

    // Specific member functions
    template <typename Data>
    const Data &BST<Data>::Min() const
    {
        if (root != nullptr)
            return FindPointerToMin(this->root)->Element();
        else
            throw std::length_error("Access to an Empty BST");
    }

    template <typename Data>
    Data BST<Data>::MinNRemove()
    {

        if (root != nullptr)
        {
            NodeLnk *nod = DetachMin(root);
            Data elem = move(nod->info);
            delete nod;
            return elem;
        }
        else
            throw std::length_error("Access to an Empty BST");
    }

    template <typename Data>
    void BST<Data>::RemoveMin()
    {

        if (root != nullptr)
            delete DetachMin(root);
        else
            throw std::length_error("Access to an Empty BST");
    }

    template <typename Data>
    Data BST<Data>::MaxNRemove()
    {

        if (root != nullptr)
        {
            NodeLnk *nod = DetachMax(root);
            Data elem = move(nod->info);
            delete nod;
            return elem;
        }
        else
            throw std::length_error("Access to an Empty BST");
    }

    template <typename Data>
    void BST<Data>::RemoveMax()
    {

        if (root != nullptr)
            delete DetachMax(root);
        else
            throw std::length_error("Access to an Empty BST");
    }

    template <typename Data>
    const Data &BST<Data>::Max() const
    {
        if (!(this->Empty()))
            return FindPointerToMax(this->root)->Element();
        else
            throw std::length_error("Access to an Empty BST");
    }

    template <typename Data>
    const Data &BST<Data>::Predecessor(const Data &dat) const
    {
        if (root != nullptr && (FindPointerToPredecessor(root, dat) != nullptr))
            return (*FindPointerToPredecessor(root, dat))->Element();
        else
            throw std::length_error("Data not found");
    }

    template <typename Data>
    Data BST<Data>::PredecessorNRemove(const Data &dat)
    {
        if (root != nullptr)
        {
            NodeLnk **nod = FindPointerToPredecessor(root, dat);

            if (nod != nullptr)
            {
                {
                    Data elem((*nod)->Element());
                    Remove(elem);
                    return elem;
                }
            }
            else
                throw std::length_error("Data not found");
        }
        else
            throw std::length_error("Data not found");
    }

    template <typename Data>
    void BST<Data>::RemovePredecessor(const Data &dat)
    {
        if (root != nullptr && (FindPointerToPredecessor(root, dat) != nullptr))
            Remove(Predecessor(dat));
        else
            throw std::length_error("Data not found");
    }

    template <typename Data>
    const Data &BST<Data>::Successor(const Data &dat) const
    {
        if (root != nullptr && (FindPointerToSuccessor(root, dat) != nullptr))
            return (*FindPointerToSuccessor(root, dat))->Element();
        else
            throw std::length_error("Data not found");
    }

    template <typename Data>
    Data BST<Data>::SuccessorNRemove(const Data &dat)
    {
        if (root != nullptr)
        {
            NodeLnk **nod = FindPointerToSuccessor(root, dat);

            if (nod != nullptr)
            {
                {
                    Data elem((*nod)->Element());
                    Remove(elem);
                    return elem;
                }
            }
            else
                throw std::length_error("Data not found");
        }
        else
            throw std::length_error("Data not found");
    }

    template <typename Data>
    void BST<Data>::RemoveSuccessor(const Data &dat)
    {
        if (root != nullptr && (FindPointerToSuccessor(root, dat) != nullptr))
            Remove(Successor(dat));
        else
            throw std::length_error("Data not found");
    }

    /* ************************************************************************** */

    // Specific member functions (inherited from DictionaryContainer)
    template <typename Data>
    bool BST<Data>::Insert(const Data &dat)
    {

        if (root == nullptr)
        {
            root = new NodeLnk(dat);
            ++size;
            return true;
        }
        else
        {
            if (FindPointerTo(root, dat) == nullptr)
            {
                FindPointerTo(root, dat) = new NodeLnk(dat);
                ++size;
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    template <typename Data>
    bool BST<Data>::Insert(Data &&dat)
    {
        if (root == nullptr)
        {
            root = new NodeLnk(move(dat));
            ++size;
            return true;
        }
        else
        {
            if (FindPointerTo(root, move(dat)) == nullptr)
            {
                FindPointerTo(root, move(dat)) = new NodeLnk(move(dat));
                ++size;
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    template <typename Data>
    bool BST<Data>::Remove(const Data &dat)
    {
        if (!this->Empty() && Exists(dat))
        {
            NodeLnk *&nod = FindPointerTo(root, dat);

            if (nod != nullptr)
            {
                if (nod->left != nullptr)
                {
                    NodeLnk *cur = DetachMax(nod->left);
                    nod->info = cur->info;
                    delete cur;
                }

                else if (nod->right != nullptr)
                {
                    NodeLnk *cur = DetachMin(nod->right);
                    nod->info = cur->info;
                    delete cur;
                }

                else
                {
                    delete *&nod;
                    *&nod = nullptr;
                    size--;
                }
            }

            return true;
        }
        else
            return false;
    }

    /* ************************************************************************** */

    // Specific member functions (inherited from TestableContainer)
    template <typename Data>
    bool BST<Data>::Exists(const Data &dat) const noexcept
    {
        if (FindPointerTo(root, dat) == nullptr)
            return false;
        return true;
    }

    /* ************************************************************************** */

    template <typename Data>
    typename BST<Data>::NodeLnk *BST<Data>::DetachMin(NodeLnk *&nod) noexcept
    {
        return Skip2Right(FindPointerToMin(nod));
    }

    template <typename Data>
    typename BST<Data>::NodeLnk *BST<Data>::DetachMax(NodeLnk *&nod) noexcept
    {
        return Skip2Left(FindPointerToMax(nod));
    }

    template <typename Data>
    typename BST<Data>::NodeLnk *BST<Data>::Skip2Left(NodeLnk *&nod) noexcept
    {
        NodeLnk *leftnod = nullptr;

        if (nod != nullptr)
        {
            std::swap(leftnod, nod->left);
            std::swap(leftnod, nod);
            --size;
        }

        return leftnod;
    }

    template <typename Data>
    typename BST<Data>::NodeLnk *BST<Data>::Skip2Right(NodeLnk *&nod) noexcept
    {
        NodeLnk *rightnod = nullptr;

        if (nod != nullptr)
        {
            std::swap(rightnod, nod->right);
            std::swap(rightnod, nod);
            --size;
        }

        return rightnod;
    }

    template <typename Data>
    typename BST<Data>::NodeLnk *&BST<Data>::FindPointerToMin(NodeLnk *&nod) noexcept
    {
        return const_cast<NodeLnk *&>(static_cast<const BST<Data> *>(this)->FindPointerToMin(nod));
    }

    template <typename Data>
    const typename BST<Data>::NodeLnk *const &BST<Data>::FindPointerToMin(const NodeLnk *const &nod) const noexcept
    {
        const NodeLnk *const *ptr = &nod;
        const NodeLnk *cur = nod;

        if (cur != nullptr)
        {
            while (cur->left != nullptr)
            {
                ptr = &cur->left;
                cur = cur->left;
            }
        }

        return *ptr;
    }

    template <typename Data>
    typename BST<Data>::NodeLnk *&BST<Data>::FindPointerToMax(NodeLnk *&nod) noexcept
    {
        return const_cast<NodeLnk *&>(static_cast<const BST<Data> *>(this)->FindPointerToMax(nod));
    }

    template <typename Data>
    const typename BST<Data>::NodeLnk *const &BST<Data>::FindPointerToMax(const NodeLnk *const &nod) const noexcept
    {
        const NodeLnk *const *ptr = &nod;
        const NodeLnk *cur = nod;

        if (cur != nullptr)
        {
            while (cur->right != nullptr)
            {
                ptr = &cur->right;
                cur = cur->right;
            }
        }

        return *ptr;
    }

    template <typename Data>
    typename BST<Data>::NodeLnk *&BST<Data>::FindPointerTo(NodeLnk *&nod, const Data &dat) noexcept
    {
        return const_cast<NodeLnk *&>(static_cast<const BST<Data> *>(this)->FindPointerTo(nod, dat));
    }

    template <typename Data>
    const typename BST<Data>::NodeLnk *const &BST<Data>::FindPointerTo(const NodeLnk *const &nod, const Data &dat) const noexcept
    {
        const NodeLnk *const *ptr = &nod;
        const NodeLnk *cur = nod;

        while (cur != nullptr)
        {
            if (cur->info < dat)
            {
                ptr = &cur->right;
                cur = cur->right;
            }
            else if (cur->info > dat)
            {
                ptr = &cur->left;
                cur = cur->left;
            }
            else
            {
                break;
            }
        }
        return *ptr;
    }

    template <typename Data>
    typename BST<Data>::NodeLnk **BST<Data>::FindPointerToSuccessor(NodeLnk *&nod, const Data &dat) noexcept
    {
        return const_cast<NodeLnk **>(static_cast<const BST<Data> *>(this)->FindPointerToSuccessor(nod, dat));
    }

    template <typename Data>
    const typename BST<Data>::NodeLnk *const *BST<Data>::FindPointerToSuccessor(const NodeLnk *const &nod, const Data &dat) const noexcept
    {
        const NodeLnk *const *nodptr = &nod;
        const NodeLnk *const *ptr = nullptr;
        while (true)
        {
            const NodeLnk &cur = **nodptr;
            if (cur.info > dat)
            {
                ptr = nodptr;
                if (cur.left == nullptr)
                    return ptr;
                else
                    nodptr = &cur.left;
            }
            else
            {
                if (cur.right == nullptr)
                    return ptr;
                else
                {
                    if (cur.info < dat)
                        nodptr = &cur.right;
                    else
                        return &FindPointerToMin(cur.right);
                }
            }
        }
    }

    template <typename Data>
    typename BST<Data>::NodeLnk **BST<Data>::FindPointerToPredecessor(NodeLnk *&nod, const Data &dat) noexcept
    {
        return const_cast<NodeLnk **>(static_cast<const BST<Data> *>(this)->FindPointerToPredecessor(nod, dat));
    }

    template <typename Data>
    const typename BST<Data>::NodeLnk *const *BST<Data>::FindPointerToPredecessor(const NodeLnk *const &nod, const Data &dat) const noexcept
    {
        const NodeLnk *const *nptr = &nod;
        const NodeLnk *const *ptr = nullptr;
        while (true)
        {
            const NodeLnk &cur = **nptr;
            if (cur.info < dat)
            {
                ptr = nptr;
                if (cur.right == nullptr)
                    return ptr;
                else
                    nptr = &cur.right;
            }
            else
            {
                if (cur.left == nullptr)
                    return ptr;
                else
                {
                    if (cur.info > dat)
                        nptr = &cur.left;
                    else
                    {
                        // if (cur.left == nullptr)
                        //     return nullptr;

                        return &FindPointerToMax(cur.left);
                    }
                }
            }
        }
    }
}
