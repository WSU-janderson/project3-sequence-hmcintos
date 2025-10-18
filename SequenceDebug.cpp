/**
 * SequenceDebug.cpp
 * Project 3
 * CS 3100
 *
 * In this file, you will write your tests as you implement Sequence. If you are using CLion, you need to select
 * SequenceDebug from the drop-down menu next to the Build (hammer icon) if it is on SequenceTestHarness
 */
#include <iostream>
#include <cstdlib>
#include "Sequence.h"

using namespace std;

int main() {
    Sequence testSequence(10);
    testSequence.insert(2,"go");
    // testSequence.insert(0,"to");
    // testSequence.insert(0,"Where");
    // testSequence.insert(0,"HO");
    // testSequence.insert(0,"HI");
    testSequence.printList();
    testSequence.~Sequence();
    testSequence.printList();

    return 0;
}