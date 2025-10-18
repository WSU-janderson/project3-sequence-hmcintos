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
    Sequence testSequence2(0);

    testSequence.insert(0,"go");
    testSequence.insert(1,"to");
    testSequence.insert(2,"Where");
    testSequence.insert(3,"HO");
    testSequence.insert(4,"HI");
    testSequence.pushBack("fyuck");
    Sequence testSequence3(testSequence);
    testSequence.clear();
    testSequence3.printList();
    // testSequence.erase(2);
    // cout << testSequence[99] << endl;
    // testSequence.clear();
    // testSequence.printList();
    // testSequence.insert(0,"go");
    // testSequence.insert(1,"to");
    // testSequence.insert(2,"Where");
    // testSequence.insert(3,"HO");
    // testSequence.erase(3);
    // testSequence.printList();

    return 0;
}