/**
 * Programmer: Hunter McIntosh
 * Date: 10/16/2025
 * Class: CS 3100 Data Structures and ALgorithms
 * Professor: James Anderson
 * Project 3 Sequence
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include "Sequence.h"


using namespace std;


/**
 * Constructor for our sequence class. Initializes head, tail and size then reserves spots in memory with empty nodes
 *
 * @param size The size you want your linked list to be size_t value
 */
Sequence::Sequence(size_t size):head(nullptr),tail(nullptr), size(size) {
    for (size_t i = 0; i < size; i++) {
        Node* newNodePtr;
        newNodePtr = new Node();
        newNodePtr->index = i;
        newNodePtr->next = nullptr;
        if(head == nullptr){
            head = newNodePtr;
            tail = newNodePtr;
        } else {
            newNodePtr->prev = tail;
            tail->next = newNodePtr;
            tail = newNodePtr;
        }
    }
}


/**
 * Will insert a new node or a string value into an existing node depeinding on position and availability
 * @param position size_t value representing an index within our Linked lists bounds
 * @param value String value we are looking to store within our list
 */
void Sequence::insert(size_t position,string value)
{
    //generate new node
    Node* newNodePtr;
    newNodePtr = new Node();
    newNodePtr->data = value;
    newNodePtr->index = position;
    newNodePtr->next = nullptr;
    if(head == nullptr){ //if head is empty set newNodePtr to be head and tail
        head = newNodePtr;
        tail = newNodePtr;
        size++;
    }
    else{ //else find the position for the insertion
        Node* current = head;
        if (position <= size && position >= 0) { //if position is not out of bounds run this check
            while (current->index != position && current->next != nullptr) {
                //cout << current->index << endl;
                current = current->next;
            }
            if (current->data == "") { //if current is one of the empty nodes we set up in our constructor set data
                current->data = value;
            }
            else { // else insert a new node into the position you wish it to be at then move every other node up
                newNodePtr->prev = current->prev;
                current->prev->next = newNodePtr;
                newNodePtr->next = current;
                current->prev = newNodePtr;
                int i = 1;
                while (current->next != nullptr) {
                    current->index = position + i;
                    i++;
                    current = current->next;
                }
                current->index = position+i; //only thing that the while loop doesnt check. Probably gonna change it to a for loop to avoid this.
                size++;
            }
        }
        else {// throw out of bounds exception
            cout << position << " is not present in the sequence. throw exception here" << endl;
        }
        // newNodePtr->prev = tail;
        // tail->next = newNodePtr;
        // tail = newNodePtr;
    }

}

/**
 * Print list function for sequence will print the sequence to the terminal in order from head to tail then from tail to head
 */
void Sequence::printList(){
    Node* current = head;
    while(current != nullptr){
        cout << current->index << ":" << current->data << " ";
        current = current->next;
    }
    cout << "\nWanna see me do it backwards?" << endl;
    current = tail;
    while(current !=nullptr){
        cout << current->index << ":" << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}


string Sequence::front() {
    Node* current = head;
    if (head==nullptr) {
        return "List is empty throw an exception";
    } else {
        return current->data;
    }
}

string Sequence::back() {
    Node* current = tail;
    if (head==nullptr) {
        return "List is empty throw an exception";
    }
    else {
        return current->data;
    }
}

bool Sequence::empty() {
    return head == nullptr;
}

/**
 * Adds an item to the end of the linked list
 * @param item String value we are looking to add to the end of our linked list.
 */
void Sequence::pushBack(string item) {
    Node* newNodePtr = new Node();
    Node* current = tail;
    newNodePtr->data = item;
    newNodePtr->index = size;
    newNodePtr->prev = current;
    current->next = newNodePtr;
    tail = newNodePtr;
    size++;

}

/**
 * Deletes the last item in the linked list. If list is empty it will throw an exception
 */
void Sequence::popBack() {
    if (head == nullptr) {
        cout  << " is empty. throw exception" << endl;
    } else {
        Node* current = tail;
        if (tail->prev == nullptr) {
            delete current;
            tail = nullptr;
            head = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
            delete current;
        }
        size--;
    }
}

/**
 * Deconstructor for the sequence class. Fully removes it from memory.
 */
Sequence::~Sequence(){
    Node* current = head;
    Node* nextNode;

    while(current != nullptr){
        nextNode = current->next;
        delete current;
        current = nextNode;
    }

    head = nullptr;
    tail = nullptr;
    size = 0;
}