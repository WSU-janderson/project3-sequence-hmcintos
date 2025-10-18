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
    size_t sz;


public:
    explicit Sequence(size_t size = 0);
    ~Sequence();

    void clear();

    void erase(size_t position);

    void erase(size_t position, size_t count);

    void insert(size_t position, std::string value);
    void printList();

    std::string &operator[](size_t position);

    Sequence(const Sequence &s);

    Sequence &operator=(const Sequence &s);

    std::string front();

    std::string back();

    bool empty();

    size_t size() const;

    void push_back(std::string item);

    void pop_back();
    friend std::ostream& operator<<(std::ostream& os, const Sequence& s);
};
#endif