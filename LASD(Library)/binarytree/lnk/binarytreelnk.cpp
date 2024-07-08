#include "binarytreelnk.hpp"

namespace lasd
{
    // Specific Constructor
    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const NodeLnk &nod)
    {
        info = nod.info;

        if (nod.HasLeftChild())
            left = new NodeLnk(*nod.left);
        else
            left = nullptr;

        if (nod.HasRightChild())
            right = new NodeLnk(*nod.right);
        else
            right = nullptr;
    }

    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk::NodeLnk(NodeLnk &&nod) noexcept
    {
        swap(info, nod.info);
        swap(left, nod.left);
        swap(right, nod.right);
    }

    // Move Constructor
    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk::NodeLnk(Data &&dat) noexcept
    {
        swap(info, dat);
    }

    // Copy Assignment
    template <typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk &BinaryTreeLnk<Data>::NodeLnk::operator=(const NodeLnk &nod)
    {
        info = nod.info;

        if (left == nullptr)
        {
            if (nod.left != nullptr)
                left = new NodeLnk(*nod.left);
        }
        else
        {
            if (nod.left != nullptr)
                *left = *nod.left;
            else
            {
                delete left;
                left = nullptr;
            }
        }

        if (right == nullptr)
        {
            if (nod.right != nullptr)
                right = new NodeLnk(*nod.right);
        }
        else
        {
            if (nod.right != nullptr)
                *right = *nod.right;
            else
            {
                delete right;
                right = nullptr;
            }
        }

        return *this;
    }

    // Move Assignment
    template <typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk &BinaryTreeLnk<Data>::NodeLnk::operator=(NodeLnk &&nod) noexcept
    {
        swap(info, nod.info);
        swap(left, nod.left);
        swap(right, nod.right);

        return *this;
    }

    // Comparison operator
    template <typename Data>
    bool BinaryTreeLnk<Data>::NodeLnk::operator==(const NodeLnk &nod) const noexcept
    {
        return ((info = nod.info) && (((left == nullptr && nod.left == nullptr) || (left != nullptr && nod.left != nullptr)) && ((right == nullptr && nod.right == nullptr) || (right != nullptr && nod.right != nullptr))));
    }

    template <typename Data>
    bool BinaryTreeLnk<Data>::NodeLnk::operator!=(const NodeLnk &nod) const noexcept
    {
        return !(*this == nod);
    }

    // Specific member functions struct NodeLnk
    template <typename Data>
    const Data &BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept
    {
        return info;
    }

    // Specific member functions struct NodeLnk
    template <typename Data>
    Data &BinaryTreeLnk<Data>::NodeLnk::Element() noexcept
    {
        return info;
    }

    template <typename Data>
    bool BinaryTreeLnk<Data>::NodeLnk::IsLeaf() const noexcept
    {
        return (left == nullptr && right == nullptr);
    }

    template <typename Data>
    bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept
    {
        return (left != nullptr);
    }

    template <typename Data>
    bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept
    {
        return (right != nullptr);
    }

    template <typename Data>
    const typename BinaryTreeLnk<Data>::Node &BinaryTreeLnk<Data>::NodeLnk::LeftChild() const
    {
        if (left != nullptr)
            return *left;
        else
            throw std::out_of_range("Access at LeftChild not existing");
    }

    template <typename Data>
    const typename BinaryTreeLnk<Data>::Node &BinaryTreeLnk<Data>::NodeLnk::RightChild() const
    {
        if (right != nullptr)
            return *right;
        else
            throw std::out_of_range("Access at RightChild not existing");
    }

    template <typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk &BinaryTreeLnk<Data>::NodeLnk::LeftChild()
    {
        if (left != nullptr)
            return *left;
        else
            throw std::out_of_range("Access at LeftChild not existing");
    }

    template <typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk &BinaryTreeLnk<Data>::NodeLnk::RightChild()
    {
        if (right != nullptr)
            return *right;
        else
            throw std::out_of_range("Access at RightChild not existing");
    }

    // Destructor Node
    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk::~NodeLnk()
    {
        delete left;
        delete right;
    }

    /* ************************************************************************** */
    // Specific constructors
    template <typename Data>
    BinaryTreeLnk<Data>::BinaryTreeLnk(const TraversableContainer<Data> &con)
    {
        size = con.Size();
        QueueVec<NodeLnk **> Queue;
        Queue.Enqueue(&root);
        con.Traverse([&Queue](const Data &dat)
                     {
            NodeLnk *& cur = *Queue.HeadNDequeue();
            cur = new NodeLnk(dat);
            Queue.Enqueue(&cur->left);
            Queue.Enqueue(&cur->right); });
    }

    template <typename Data>
    BinaryTreeLnk<Data>::BinaryTreeLnk(MappableContainer<Data> &&con)
    {
        size = con.Size();
        QueueVec<NodeLnk **> Queue;
        Queue.Enqueue(&root);
        con.Traverse([&Queue](const Data &dat)
                     {
            NodeLnk *& cur = *Queue.HeadNDequeue();
            cur = new NodeLnk(move(dat));
            Queue.Enqueue(&cur->left);
            Queue.Enqueue(&cur->right); });
    }

    // Copy constructor
    template <typename Data>
    BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk &btl)
    {
        if (btl.root != nullptr)
        {
            root = new NodeLnk(*btl.root);
            size = btl.size;
        }
    }

    // Move constructor
    template <typename Data>
    BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk &&btl) noexcept
    {
        swap(root, btl.root);
        swap(size, btl.size);
    }

    // Copy assignment
    template <typename Data>
    BinaryTreeLnk<Data> &BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk<Data> &btl)
    {
        if (root == nullptr)
        {
            if (btl.root != nullptr)
                root = new NodeLnk(*btl.root);
        }
        else
        {
            if (btl.root == nullptr)
            {
                delete root;
                root = nullptr;
            }
            else
            {
                *root = *btl.root;
            }
        }
        size = btl.size;
        return *this;
    }

    // Move assignment
    template <typename Data>
    BinaryTreeLnk<Data> &BinaryTreeLnk<Data>::operator=(BinaryTreeLnk<Data> &&btl) noexcept
    {
        swap(size, btl.size);
        swap(root, btl.root);

        return *this;
    }

    // Comparison operator
    template <typename Data>
    bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk<Data> &btl) const noexcept
    {
        return (size == btl.size && ((root == nullptr && btl.root == nullptr) || (root != nullptr && btl.root != nullptr)));
    }

    template <typename Data>
    bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk<Data> &btl) const noexcept
    {
        return !(*this == btl);
    }

    // Specific member functions BinaryTreeLnk
    template <typename Data>
    const typename BinaryTreeLnk<Data>::Node &BinaryTreeLnk<Data>::Root() const
    {
        if (root != nullptr)
            return *root;
        else
            throw std::length_error("Access to an empty binarytree");
    }

    // Mutable version
    template <typename Data>
    typename BinaryTreeLnk<Data>::MutableNode &BinaryTreeLnk<Data>::Root()
    {
        if (root != nullptr)
            return *root;
        else
            throw std::length_error("Access to an empty binarytree");
    }

    // Destructor BinaryTreeLnk
    template <typename Data>
    BinaryTreeLnk<Data>::~BinaryTreeLnk()
    {
        delete root;
    }

    template <typename Data>
    void BinaryTreeLnk<Data>::Clear()
    {
        delete root;
        root = nullptr;
        size = 0;
    }

    /* ************************************************************************** */

}
