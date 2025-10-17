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
    Sequence testSequence;
    testSequence.insert("go");
    testSequence.insert("to");
    testSequence.insert("Where");
    testSequence.insert("HO");
    testSequence.insert("HI");
    testSequence.printList();
    testSequence.~Sequence();
    testSequence.printList();

    return 0;
}