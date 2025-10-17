#ifndef NODE_H
#define NODE_H

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value = 0) : data(value), next(nullptr), prev(nullptr) {}
};

#endif

#ifndef linkedList_h
#define linkedList_h
class LinkedList{
    private:
    Node* head;
    Node* tail;
    int size;

    public:
    LinkedList();
    ~LinkedList();
    void insert(int value);
    void printList();

    #endif
};
    