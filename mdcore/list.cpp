#include "list.h"

namespace mdcore{
    template<class T>
    SingleLinkedList<T>::SingleLinkedList()
    {
        size = 0;
        first_node = nullptr;
        last_node = nullptr;
    }
    template<class T>
    SingleLinkedList<T>::~SingleLinkedList()
    {
        if (first_node == nullptr && last_node == nullptr)
        {
            //Early return if both node values are null
            return;
        }
        //Both nodes are the same
        if(first_node == last_node)
        {
            //Cleanup the one element and delete.
            delete first_node;
            return;
        }
        SingleNode<T>* node = first_node;
        SingleNode<T>* next_node = nullptr;
        while(node != nullptr)
        {
            next_node = node->next;
            //Thread Safety
            if(node == first_node)
            {
                first_node = nullptr;
            }
            delete node;
            if(next_node == nullptr)
            {
                //If the next node is null, we're done since we deleted the current node we are looking at
                return;
            }
        }
        return;
    }
    template<class T>
    void SingleLinkedList<T>::push_back(T val)
    {
        SingleNode<T>* next = new (std::nothrow) SingleNode<T>();
        next->value = val;
        last_node->next = next;
        last_node = next;
        size++;
    }
    template<class T>
    void SingleLinkedList<T>::remove(T val)
    {
        //Iterate over the list, find the node with it and delete.
        SingleNode<T>* node = first_node;
        SingleNode<T>* prev = first_node;
        SingleNode<T>* next = first_node->next;
        while(node != nullptr)
        {
            if(node->value == val)
            {
                //First Element Case
                //Delete the element after updating the first ptr
                if(first_node == node)
                {
                    first_node = next;
                    delete node;
                    size--;
                    return; 
                }
                //Last Element case
                //Update the previous next ptr to be nullptr indicating its the end
                //Delete the node
                //Update last node ptr as well
                if(last_node == node)
                {
                    prev->next = nullptr;
                    delete node;
                    size--;
                    last_node = prev;
                    return;
                }
                //Middle case, remove the node from the chain and delete
                prev->next = node->next;
                delete node;
                size--;
                return;
            }
            //Iteration. Set the current as prev, current is it's next, next is the new current's next
            prev = node;
            node = node->next;
            next = node->next;
        }
        //We didn't find the element, return without doing anything.
        return;
    }
    template<class T>
    T SingleLinkedList<T>::get(int index)
    {
        SingleNode<T>* node = begin();
        for(int i = 0; i < size, i++)
        {
            if(i == index)
            {
                return node->value;
            }
            node = node->next;
        }
        throw std::out_of_range;
    }
    template<class T>
    void SingleLinkedList<T>::operator+(T value)
    {
        //Don't over complicate this or duplicate code
        //Just redirect the value to where it should.
        push_back(value);
    }
    template<class T>
    bool SingleLinkedList<T>::operator=(SingleLinkedList<T> list)
    {
        if(first_node == list.begin() && last_node == list.end())
        {
            //Did you seriously compare a list with itself?
            return true;
        }
        //Sanity check on all other lists and verify the size.
        if(size == list.get_size())
        {
            SingleNode<T>* node1 = begin();
            SingleNode<T>* node2 = list->begin();
            //Both lists are the same size so we don't need to check both for nulls.
            //If one gets to the null, the other is at the null as well.
            while(node1 != nullptr){
                if(node1->value != node2->value)
                {
                    return false;
                }
                node1 = node1->next;
                node2 = node2->next;
            }
            return true;

        }
        return false;
    }
    template<class T>
    SingleNode<T>* SingleLinkedList<T>::begin()
    {
        return first_node;
    }
    template<class T>
    SingleNode<T>* SingleLinkedList<T>::last()
    {
        return last_node;
    }
    template<class T>
    int SingleLinkedList<T>::get_size()
    {
        return size;
    }
    template<class T>
    DoubleLinkedList<T>::DoubleLinkedList()
    {
        size = 0;
        first_node = nullptr;
        last_node = nullptr;
    }
    template<class T>
    DoubleLinkedList<T>::~DoubleLinkedList()
    {
        if (first_node == nullptr && last_node == nullptr)
        {
            //Early return if both node values are null
            return;
        }
        //Both nodes are the same
        if(first_node == last_node)
        {
            //Cleanup the one element and delete.
            delete first_node;
            return;
        }
        DoubleNode<T>* node = first_node;
        DoubleNode<T>* next_node = nullptr;
        while(node != nullptr)
        {
            next_node = node->next;
            //Thread Safety
            if(node == first_node)
            {
                first_node = nullptr;
            }
            delete node;
            if(next_node == nullptr)
            {
                //If the next node is null, we're done since we deleted the current node we are looking at
                return;
            }
        }
        return;
    }
    template<class T>
    void DoubleLinkedList<T>::push_back(T val)
    {
        DoubleNode<T>* next = new (std::nothrow) DoubleNode<T>();
        next->value = val;
        next->prev = last_node;
        last_node->next = next;
        last_node = next;
        next->next = nullptr;
        size++;
    }
    template<class T>
    void DoubleLinkedList<T>::remove(T val)
    {
        //Iterate over the list, find the node with it and delete.
        DoubleNode<T>* node = first_node;
        DoubleNode<T>* prev = first_node;
        DoubleNode<T>* next = first_node->next;
        while(node != nullptr)
        {
            if(node->value == val)
            {
                //First Element Case
                //Delete the element after updating the first ptr
                if(first_node == node)
                {
                    first_node = next;
                    delete node;
                    first_node->prev = nullptr;
                    size--;
                    return; 
                }
                //Last Element case
                //Update the previous next ptr to be nullptr indicating its the end
                //Delete the node
                //Update last node ptr as well
                if(last_node == node)
                {
                    prev->next = nullptr;
                    delete node;
                    size--;
                    last_node = prev;
                    return;
                }
                //Middle case, remove the node from the chain and delete
                prev->next = node->next;
                node->next->prev = prev;
                delete node;
                size--;
                return;
            }
            //Iteration. Set the current as prev, current is it's next, next is the new current's next
            prev = node;
            node = node->next;
            next = node->next;
        }
        //We didn't find the element, return without doing anything.
        return;
    }
    template<class T>
    T DoubleLinkedList<T>::get(int index)
    {
        DoubleNode<T>* node = begin();
        for(int i = 0; i < size, i++)
        {
            if(i == index)
            {
                return node->value;
            }
            node = node->next;
        }
        throw std::out_of_range;
    }
    template<class T>
    void DoubleLinkedList<T>::operator+(T value)
    {
        //Don't over complicate this or duplicate code
        //Just redirect the value to where it should.
        push_back(value);
    }
    template<class T>
    bool DoubleLinkedList<T>::operator=(DoubleLinkedList<T> list)
    {
        if(first_node == list.begin() && last_node == list.end())
        {
            //Did you seriously compare a list with itself?
            return true;
        }
        //Sanity check on all other lists and verify the size.
        if(size == list.get_size())
        {
            DoubleNode<T>* node1 = begin();
            DoubleNode<T>* node2 = list->begin();
            //Both lists are the same size so we don't need to check both for nulls.
            //If one gets to the null, the other is at the null as well.
            while(node1 != nullptr){
                if(node1->value != node2->value)
                {
                    return false;
                }
                node1 = node1->next;
                node2 = node2->next;
            }
            return true;

        }
        return false;
    }
    template<class T>
    DoubleNode<T>* DoubleLinkedList<T>::begin()
    {
        return first_node;
    }
    template<class T>
    DoubleNode<T>* DoubleLinkedList<T>::last()
    {
        return last_node;
    }
    template<class T>
    int DoubleLinkedList<T>::get_size()
    {
        return size;
    }

}
