#ifndef NODE_H
#define NODE_H

class Node {
public:
    std::string data;
    int index;
    Node* next;
    Node* prev;

    Node():next(nullptr),prev(nullptr) {}

    explicit Node(std::string value) : data(value), next(nullptr), prev(nullptr) {}

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
    explicit Sequence(size_t size = 0);
    ~Sequence();
    void insert(size_t position, std::string value);
    void printList();

    std::string front();

    void pushBack(std::string item);

    void popBack();
};
#endif