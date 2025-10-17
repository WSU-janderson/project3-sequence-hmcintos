#ifndef NODE_H
#define NODE_H

class Node {
public:
    std::string data;
    Node* next;
    Node* prev;

    Node(std::string value = "") : data(value), next(nullptr), prev(nullptr) {}
};
#endif

#ifndef Sequence_h
#define Sequence_h
class Sequence{
    private:
    Node* head;
    Node* tail;
    size_t size;

    public:
    Sequence();
    ~Sequence();
    void insert(std::string value);
    void printList();

    #endif
};
    