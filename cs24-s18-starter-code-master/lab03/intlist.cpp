// intlist.cpp
// Implements class IntList
// George Nebieridze 11/25/2021

#include "intlist.h"

#include <iostream>
using std::cout;

IntList::IntList(const IntList& source) {
    first = 0;

    Node* current = source.first;
    while (current) {
        append(current->info);
        current = current->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {

    if (first == 0) return;

    Node* current = first;
    Node* next = first->next;

    delete current;

    while (next) {
        current = next;
        next = current->next;

        delete current;
    }
}


// return sum of values in list
int IntList::sum() const {
    if (first == NULL)
        return 0;

    int sum = first->info;

    Node* current = first->next;
    while (current != NULL) {
        sum += current->info;
        current = current->next;
    }

    return sum; 
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    if (first == NULL)
        return false;

    Node* current = first;

    do {
        if (current->info == value)
            return true;
        
        current = current->next;

    } while (current != NULL);

    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if (first == NULL)
        return false;

    Node* current = first;
    int max = current->info;

    while (current->next != NULL) {
        current = current->next;
        if (max < current->info)
            max = current->info;
    }

    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (first == NULL)
        return 0.0;

    return ((double)this->sum()) / ((double)this->count());
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    Node* temp = first;
    first = new Node;
    first->info = value;
    first->next = temp;
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    this->~IntList();

    this->first = 0;

    // if (source.first == NULL) return *this;

    Node* current = source.first;
    while (current) {
        this->append(current->info);
        current = current->next;
    }

    return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
