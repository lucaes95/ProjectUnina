#include <iostream>

#include "list.hpp"

using namespace std;

namespace lasd
{

    /* ************************************************************************** */

    // Specific constructor
    template <typename Data>
    List<Data>::List(const TraversableContainer<Data> &con)
    {
        con.Traverse(
            [this](const Data &dat)
            {
                InsertAtBack(dat);
            });
    }

    template <typename Data>
    List<Data>::List(MappableContainer<Data> &&con)
    {
        con.Map(
            [this](Data &dat)
            {
                InsertAtBack(move(dat));
            });
    }

    // copy constructor list
    template <typename Data>
    List<Data>::List(const List<Data> &lst)
    {
        if (lst.tail != nullptr)
        {
            tail = new Node(*lst.tail);
            head = lst.head->Clone(tail);
            size = lst.size;
        }
    }

    // move constructor list
    template <typename Data>
    List<Data>::List(List<Data> &&lst) noexcept
    {
        swap(head, lst.head);
        swap(tail, lst.tail);
        swap(size, lst.size);
    }

    // specific constructor node
    template <typename Data>
    List<Data>::Node::Node(Data &&dat) noexcept
    {
        swap(element, dat);
    }

    // move constructor node
    template <typename Data>
    List<Data>::Node::Node(Node &&node) noexcept
    {
        swap(element, node.Elements);
        swap(next, node.next);
    }

    // desctructor node
    template <typename Data>
    List<Data>::Node::~Node()
    {
        delete next;
    }

    // comparison operators
    template <typename Data>
    bool List<Data>::Node::operator==(const Node &nod) const noexcept
    {
        return (element == nod.element) && ((next == nullptr && nod.next == nullptr) || ((next != nullptr)));
    }

    template <typename Data>
    bool List<Data>::Node::operator!=(const Node &nod) const noexcept
    {
        return !(*this == nod);
    }

    // specific functions
    template <typename Data>
    typename List<Data>::Node *List<Data>::Node::Clone(Node *tail)
    {
        if (next == nullptr)
        {
            return tail;
        }
        else
        {
            Node *node = new Node(element);
            node->next = next->Clone(tail);
            return node;
        }
    }

    template <typename Data>
    void List<Data>::InsertAtFront(const Data &dat)
    {
        Node *newnode = new Node(dat);
        newnode->next = head;

        head = newnode;
        if (tail == nullptr)
        {
            tail = head;
        }

        size++;
    }

    template <typename Data>
    void List<Data>::InsertAtFront(Data &&dat)
    {
        Node *newnode = new Node(std::move(dat));
        newnode->next = head;

        head = newnode;
        if (tail == nullptr)
        {
            tail = head;
        }

        size++;
    }

    template <typename Data>
    void List<Data>::RemoveFromFront()
    {
        if (head != nullptr)
        {
            Node *tmp = head;

            if (tail == head)
            {
                head = tail = nullptr;
            }
            else
            {
                head = head->next;
            }

            size--;
            tmp->next = nullptr;
            delete tmp;
        }
        else
        {
            throw length_error("Acces to an empty list");
        }
    }

    template <typename Data>
    Data List<Data>::FrontNRemove()
    {
        if (head != nullptr)
        {
            Data helement = move(head->element);
            Node *tmp = head;

            if (tail == head)
            {
                head = tail = nullptr;
            }
            else
            {
                head = head->next;
            }

            size--;
            tmp->next = nullptr;
            delete tmp;
            return helement;
        }
        else
        {
            throw length_error("Acces to an empty list");
        }
    }

    template <typename Data>
    void List<Data>::InsertAtBack(const Data &dat)
    {
        Node *newnode = new Node;
        newnode->element = dat;
        newnode->next = nullptr;

        if (size == 0)
        {
            head = newnode;
            tail = head;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }

        size++;
    }

    template <typename Data>
    void List<Data>::InsertAtBack(Data &&dat)
    {
        Node *newnode = new Node(move(dat));
        newnode->next = nullptr;

        if (size == 0)
        {
            head = newnode;
            tail = head;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }

        size++;
    }

    template <typename Data>
    List<Data>::~List()
    {
        delete head;
    }

    // Copy and Move assignment
    template <typename Data>
    List<Data> &List<Data>::operator=(const List<Data> &lst)
    {
        if (size <= lst.size)
        {
            if (tail == nullptr)
            {
                List<Data> *tmplst = new List<Data>(lst);
                swap(*tmplst, *this);
                delete tmplst;
            }
            else
            {
                Node *tmplst = lst.head;
                for (Node *tmp = head; tmp != nullptr; tmp = tmp->next, tmplst = tmplst->next)
                    tmp->element = tmplst->element;
                if (tmplst != nullptr)
                {
                    Node *newtail = new Node(*lst.tail);
                    tail->next = tmplst->Clone(newtail);
                    tail = newtail;
                }
            }
        }
        else
        {
            if (lst.tail == nullptr)
            {
                delete head;
                head = tail = nullptr;
            }
            else
            {
                Node *tmp = head;
                for (Node *tmplst = lst.head; tmplst != nullptr; tmplst = tmplst->next, tmp = tmp->next)
                {
                    tmp->element = tmplst->element;
                    tail = tmp;
                }
                delete tmp;
            }
        }

        size = lst.size;
        return *this;
    }

    template <typename Data>
    List<Data> &List<Data>::operator=(List<Data> &&lst) noexcept
    {
        swap(head, lst.head);
        swap(tail, lst.tail);
        swap(size, lst.size);
        return *this;
    }

    // Comparison operator overload
    template <typename Data>
    bool List<Data>::operator==(const List<Data> &lst) const noexcept
    {
        bool chk = true;

        if (size == lst.size && size == 0)
        {
            chk = true;
        }
        else if (size != lst.size)
        {
            chk = false;
        }
        else
        {
            Node *tmpnode = head;
            Node *tmplstnode = lst.head;
            for (unsigned long index = 0; index < size; ++index)
            {
                if (tmplstnode->element != tmpnode->element)
                {
                    chk = false;
                }
                tmpnode = tmpnode->next;
                tmplstnode = tmplstnode->next;
            }
        }

        return chk;
    }

    template <typename Data>
    bool List<Data>::operator!=(const List<Data> &lst) const noexcept
    {
        return !(*this == lst);
    }

    // Clear()
    template <typename Data>
    void List<Data>::Clear()
    {
        delete head;
        head = tail = nullptr;
        size = 0;
    }

    // function from DictionaryContable
    template <typename Data>
    bool List<Data>::Insert(const Data &dat)
    {
        if (head != nullptr)
        {
            for (Node *tmp = head; tmp->next != nullptr; tmp = tmp->next)
            {
                if (tmp->element == dat)
                    return false;
            }
        }

        InsertAtBack(dat);
        return true;
    }

    template <typename Data>
    bool List<Data>::Insert(Data &&dat)
    {
        if (head != nullptr)
        {
            for (Node *tmp = head; tmp->next != nullptr; tmp = tmp->next)
            {
                if (tmp->element == dat)
                    return false;
            }
        }
        InsertAtBack(move(dat));
        return true;
    }

    template <typename Data>
    bool List<Data>::Remove(const Data &dat)
    {
        Node *tmp = nullptr;

        if (head != nullptr)
        {
            if (head->element == dat)
            {
                tmp = head;
                head = head->next;
                tmp->next = nullptr;
                delete tmp;

                size--;
                return true;
            }
            else
            {
                for (Node *cur = head; cur != nullptr; tmp = cur, cur = cur->next)
                {
                    if (cur->element == dat)
                    {
                        tmp->next = cur->next;

                        cur->next = nullptr;

                        delete cur;

                        if (tmp->next == nullptr)
                            tail = tmp;

                        size--;
                        return true;
                    }
                }
            }
        }
        return false;
    }

    template <typename Data>
    const Data &List<Data>::operator[](ulong index) const
    {
        if (index < size)
        {
            if (size == 0)
            {
                return head->element;
            }
            else
            {
                Node *tmp = head;
                for (ulong i = 0; i < index; ++i)
                {
                    tmp = tmp->next;
                }

                return tmp->element;
            }
        }
        else
        {
            throw std::out_of_range("Access at index " + std::to_string(index) + "; List size " + std::to_string(size) + ".");
        }
    };

    template <typename Data>
    Data &List<Data>::operator[](ulong index)
    {
        if (index < size)
        {
            if (size == 0)
            {
                return head->element;
            }
            else
            {
                Node *tmp = head;
                for (ulong i = 0; i < index; ++i)
                {
                    tmp = tmp->next;
                }

                return tmp->element;
            }
        }
        else
        {
            throw std::out_of_range("Access at index " + std::to_string(index) + "; List size " + std::to_string(size) + ".");
        }
    };

    // Front & Back
    template <typename Data>
    inline const Data &List<Data>::Front() const
    {
        if (size > 0)
            return head->element;
        else
            throw std::length_error("Acces to an empty list");
    };

    template <typename Data>
    inline Data &List<Data>::Front()
    {
        if (size > 0)
            return head->element;
        else
            throw std::length_error("Acces to an empty list");
    };

    template <typename Data>
    inline const Data &List<Data>::Back() const
    {
        if (size > 0)
            return tail->element;
        else
            throw std::length_error("Acces to an empty list");
    };

    template <typename Data>
    inline Data &List<Data>::Back()
    {
        if (size > 0)
            return tail->element;
        else
            throw std::length_error("Acces to an empty list");
    };

    template <typename Data>
    inline void List<Data>::Traverse(TraverseFun fun) const
    {
        PreOrderTraverse(fun, head);
    }

    template <typename Data>
    inline void List<Data>::PreOrderTraverse(TraverseFun fun) const
    {
        PreOrderTraverse(fun, head);
    }

    template <typename Data>
    inline void List<Data>::PostOrderTraverse(TraverseFun fun) const
    {
        PostOrderTraverse(fun, head);
    }

    template <typename Data>
    inline void List<Data>::Map(MapFun fun)
    {
        PreOrderMap(fun, head);
    }

    template <typename Data>
    inline void List<Data>::PreOrderMap(MapFun fun)
    {
        PreOrderMap(fun, head);
    }

    template <typename Data>
    inline void List<Data>::PostOrderMap(MapFun fun)
    {
        PostOrderMap(fun, head);
    }

    /* ************************************************************************** */

    // Auxiliar Function

    template <typename Data>
    void List<Data>::PreOrderTraverse(TraverseFun fun, const Node *cur) const
    {
        for (; cur != nullptr; cur = cur->next)
        {
            fun(cur->element);
        }
    }

    template <typename Data>
    void List<Data>::PostOrderTraverse(TraverseFun fun, const Node *cur) const
    {
        if (cur != nullptr)
        {
            PostOrderTraverse(fun, cur->next);
            fun(cur->element);
        }
    }

    template <typename Data>
    void List<Data>::PreOrderMap(MapFun fun, Node *cur)
    {
        for (; cur != nullptr; cur = cur->next)
        {
            fun(cur->element);
        }
    }

    template <typename Data>
    void List<Data>::PostOrderMap(MapFun fun, Node *cur)
    {
        if (cur != nullptr)
        {
            PostOrderMap(fun, cur->next);
            fun(cur->element);
        }
    }
}
