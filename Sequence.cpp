/**
 * Programmer: Hunter McIntosh
 * Date: 10/16/2025
 * Class: CS 3100 Data Structures and ALgorithms
 * Professor: James Anderson
 * Project 3 Sequence
 */

#include <iostream>
#include "Sequence.h"

using namespace std;



Sequence::Sequence():head(nullptr),tail(nullptr),size(0)
{
}

void Sequence::insert(int value)
{
    Node* newNodePtr;
    newNodePtr = new Node();
    newNodePtr->data = value;
    newNodePtr->next = nullptr;
    if(head == nullptr){
        head = newNodePtr;
        tail = newNodePtr;
    }
    else{
        newNodePtr->prev = tail;
        tail->next = newNodePtr;
        tail = newNodePtr;
    }
    size++;
}

void Sequence::printList(){
    Node* current = head;
    while(current != nullptr){
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\nWanna see me do it backwards?" << endl;
    current = tail;
    while(current !=head){
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}   

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