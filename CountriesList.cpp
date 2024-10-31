// CountriesList.cpp
#include "CountriesList.h"

// Constructor for Unsorted list
Unsorted::Unsorted() : length(0), currentPos(-1) {}

bool Unsorted::IsFull() const {
    return (length == MAX_ITEMS);
}

int Unsorted::LengthIs() const {
    return length;
}

void Unsorted::InsertItem(Countries item) {
    info[length] = item;
    length++;
}

void Unsorted::RetrieveItem(Countries& item, bool& found) {
    found = false;
    for (int i = 0; i < length; i++) {
        if (info[i].ComparedTo(item) == 0) {
            found = true;
            item = info[i];
            return;
        }
    }
}

void Unsorted::DeleteItem(Countries item) {
    for (int i = 0; i < length; i++) {
        if (info[i].ComparedTo(item) == 0) {
            info[i] = info[length - 1];
            length--;
            return;
        }
    }
}

void Unsorted::ResetList() {
    currentPos = -1;
}

void Unsorted::GetNextItem(Countries& item) {
    currentPos++;
    item = info[currentPos];
}

int Unsorted::GetCurrentPos() {
    return currentPos;
}
