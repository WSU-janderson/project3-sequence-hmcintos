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
    Node* newNodePtr;
    newNodePtr = new Node();
    newNodePtr->data = value;
    newNodePtr->index = position;
    newNodePtr->next = nullptr;
    if(head == nullptr){
        head = newNodePtr;
        tail = newNodePtr;
    }
    else{
        Node* current = head;
        if (position <= size) {
            while (current->index != position && current->next != nullptr) {
                cout << current->index << endl;
                current = current->next;
            }
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


            cout << newNodePtr->index << endl;
            cout << newNodePtr->data << endl;
            cout << "exited the insertion loop" << endl;
        }else {
            cout << position << " is not present in the sequence." << endl;
        }
        // newNodePtr->prev = tail;
        // tail->next = newNodePtr;
        // tail = newNodePtr;
    }
    size++;
}

/**
 * Print list function for sequence will print the sequence to the terminal in order from head to tail then from tail to head
 */
void Sequence::printList(){
    Node* current = head;
    while(current != nullptr){
        cout << current->index << ":" << current->data << endl;
        current = current->next;
    }
    cout << "\nWanna see me do it backwards?" << endl;
    current = tail;
    while(current !=nullptr){
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
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