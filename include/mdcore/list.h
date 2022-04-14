#pragma once
namespace mdcore{
    template<class T>
    struct SingleNode
    {
        SingleNode* next;
        T value;
    };
    template<class T>
    class SingleLinkedList
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
    };
    template<class T>
    struct DoubleNode
    {
        DoubleNode* next;
        DoubleNode* prev;
        T value;
    };
    template<class T>
    class DoubleLinkedList
    {
        private:
            int size;
            DoubleNode<T>* first_node;
            DoubleNode<T>* last_node;
        public:
            DoubleLinkedList();
            ~DoubleLinkedList();
            void push_back(T value);
            void remove(T value);
            T get(int i);
            void operator+(T value);
            bool operator=(DoubleLinkedList<T> list);
            DoubleNode<T>* begin();
            DoubleNode<T>* last();
            int get_size();
    };
    //Alias Class of sorts to make LinkedList = DoubleLinkedList
    template <class T>
    class LinkedList: public DoubleLinkedList<T>
    {
        public:
            LinkedList();
            ~LinkedList();
    };
    //Default linked list class type to be a double linked
    //typedef DoubleLinkedList<std::string> StringLinkedList;
    typedef DoubleLinkedList<char*> CStringLinkedList;
    typedef DoubleLinkedList<int> IntegerLinkedList;
    typedef DoubleLinkedList<char> CharLinkedList;
    typedef DoubleLinkedList<long> LongLinkedList;

    template<class T>
    class SortedSingleLinkedList: public SingleLinkedList<T>
    {
        public:
            SortedSingleLinkedList();
            ~SortedSingleLinkedList();
            //This is the ONLY override compared to the base
            //When adding a new element, we need to insert in the right spot.
            void push_back(T value);
            void operator+(T value);
            bool operator=(SortedSingleLinkedList<T> list);
    };
    template<class T>
    class SortedDoubleLinkedList: public DoubleLinkedList<T>
    {
        public:
            SortedDoubleLinkedList();
            ~SortedDoubleLinkedList();
            //This is the ONLY override compared to the base
            //When adding a new element, we need to insert in the right spot.
            void push_back(T value);
            void operator+(T value);
            bool operator=(SortedDoubleLinkedList<T> list);
    };
}
