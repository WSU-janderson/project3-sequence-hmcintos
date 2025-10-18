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
string make_value(int i) {
    return string(1, 'A' + (i % 26));
}
int main() {
    try {
        Sequence data1(3);
        for (int i = 0; i < 3; i++) data1[i] = make_value(i);
        Sequence data2(0);
        data2 = data1;
        data2[0] = make_value(99);
        cout << "data1: " << data1 << endl;
        cout << "data2: " << data2 << endl;

    }
    catch (exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}