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

#ifndef Sequence_h
#define Sequence_h
class Sequence{
    private:
    Node* head;
    Node* tail;
    int size;

    public:
    Sequence();
    ~Sequence();
    void insert(int value);
    void printList();

    #endif
};
    