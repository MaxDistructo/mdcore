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

    template<class T>
    LinkedList<T>::LinkedList()
    {
        //Call the superclass constructor. This will setup the proper values.
        DoubleLinkedList<T>();
    }

    template<class T>
    LinkedList<T>::~LinkedList()
    {
        ~DoubleLinkedList<T>();
    }

    template<class T>
    SortedSingleLinkedList<T>::SortedSingleLinkedList()
    {
        size = 0;
        first_node = nullptr;
        last_node = nullptr;
    }

    template<class T>
    SortedSingleLinkedList<T>::~SortedSingleLinkedList()
    {
        //We don't need to run our own destructor as the destructor
        //of our superclass takes care of it.
        ~SingleLinkedList();
    }

    template<class T>
    void SortedSingleLinkedList<T>::push_back(T value)
    {
        //TODO: Fix the sort logic
    } 

    template<class T>
    void SortedSingleLinkedList<T>::operator+(T value)
    {
        //This doesn't get inherited, redeclare it.
        push_back(value);
    }

    template<class T>
    bool SortedSingleLinkedList<T>::operator=(SortedSingleLinkedList<T> list)
    {


        //Sanity Checks
        // 1. Is this the same list being compared to itself
        if(list.begin() == first_node && list.last() == last_node)
        {
            //This is the same list... just why are you doing this?
            return true;
        }

        // 2. Are the lists the same size?
        if(list.get_size() != size)
        {
            return false;
        }

        // 3. Check the end points.
        if(list.begin()->value != first_node->value || list.last()->value != last_node->value)
        {
            return false;
        }


        //With it being a sane comparison of 2 different lists of the same size
        //Loop over both lists and as soon as we find an element that does not match, return false.
        //This is the most time intensive part of this function.

        SingleNode* node1 = first_node;
        SingleNode* node2 = list.begin();

        while(node1 != nullptr)
        {
            if(node1->value != node2->value)
            {
                return false
            }
            node1 = node1->next;
            node2 = node2->next;
        } 

        return true;
    }

        template<class T>
    SortedDoubleLinkedList<T>::SortedDoubleLinkedList()
    {
        size = 0;
        first_node = nullptr;
        last_node = nullptr;
    }

    template<class T>
    SortedDoubleLinkedList<T>::~SortedDoubleLinkedList()
    {
        //We don't need to run our own destructor as the destructor
        //of our superclass takes care of it.
        ~DoubleLinkedList();
    }

    template<class T>
    void SortedDoubleLinkedList<T>::push_back(T value)
    {
        //TODO: Fix the sort logic
    } 

    template<class T>
    void SortedDoubleLinkedList<T>::operator+(T value)
    {
        //This doesn't get inherited, redeclare it.
        push_back(value);
    }

    template<class T>
    bool SortedDoubleLinkedList<T>::operator=(SortedDoubleLinkedList<T> list)
    {


        //Sanity Checks
        // 1. Is this the same list being compared to itself
        if(list.begin() == first_node && list.last() == last_node)
        {
            //This is the same list... just why are you doing this?
            return true;
        }

        // 2. Are the lists the same size?
        if(list.get_size() != size)
        {
            return false;
        }

        // 3. Check the end points.
        if(list.begin()->value != first_node->value || list.last()->value != last_node->value)
        {
            return false;
        }


        //With it being a sane comparison of 2 different lists of the same size
        //Loop over both lists and as soon as we find an element that does not match, return false.
        //This is the most time intensive part of this function.

        DoubleNode* node1 = first_node;
        DoubleNode* node2 = list.begin();

        while(node1 != nullptr)
        {
            if(node1->value != node2->value)
            {
                return false
            }
            node1 = node1->next;
            node2 = node2->next;
        } 

        return true;
    }

}
