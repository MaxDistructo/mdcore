#pragma once
namespace mdcore{
    template<class T>
    struct SingleNode<T>
    {
        SingleNode* next;
        T value;
    }
    template<class T>
    class SingleLinkedList<T>
    {
        protected:
            int size;
            SingleNode<T>* first_node;
            //We need a record of this to speed up adding elements
            SingleNode<T>* last_node;
        public:
            SingleLinkedList();
            ~SingleLinkedList();
            void push_back(T value);
            void remove(T value);
            T get(int index);
            void operator+(T value);
            bool operator=(SingleLinkedList<T> list);
            SingleNode<T>* begin();
            SingleNode<T>* last();
            int get_size();
    }
    template<class T>
    struct DoubleNode<T>
    {
        DoubleNode* next;
        DoubleNode* prev;
        T value;
    }
    template<class T>
    class DoubleLinkedList<T>
    {
        private:
            int size;
            DoubleNode<T>* first_node;
            DoubleNode<T>* last_node;
        public:
            void push_back(T value);
            void remove(T value);
            T get(int i);
            void operator+(T value);
            bool operator=(DoubleLinkedList<T> list);
            DoubleNode<T>* begin();
            DoubleNode<T>* last();
            int get_size();
    }
    //Default linked list class type to be a double linked
    template<class T>
    typedef LinkedList<T> DoubleLinkedList<T>;
    template<class T>
    class SortedSingleLinkedList<T>: public SingleLinkedList<T>
    {
        public:
            SortedSingleLinkedList();
            ~SortedSingleLinkedList();
            //This is the ONLY override compared to the base
            //When adding a new element, we need to insert in the right spot.
            void push_back(T value);
            void operator+(T value);
            bool operator=(SortedSingleLinkedList<T> list);
    }
}
