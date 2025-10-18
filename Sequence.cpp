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

void Sequence::popBack() {
    if (head == nullptr) {
        cout  << " is empty. throw exception" << endl;
    } else {
        Node* current = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete current;
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