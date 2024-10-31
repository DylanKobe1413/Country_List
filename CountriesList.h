// CountriesList.h
#pragma once
#include <string>
#include <iostream>

const int MAX_ITEMS = 20;

class Countries {
public:
    Countries() = default;
    Countries(std::string n, int p) : name(n), population(p) {}

    // Comparison function for Unsorted list retrieval and deletion
    int ComparedTo(const Countries& other) const {
        if (name < other.name) return -1;
        else if (name > other.name) return 1;
        else return 0;
    }

    // Output function for printing
    void Print() const {
        std::cout << "Country: " << name << ", Population: " << population << std::endl;
    }

    // Setter functions to set data from text file
    void setName(std::string n) { name = n; }
    void setPopulation(int p) { population = p; }

private:
    std::string name;
    int population;
};

class Unsorted {
public:
    Unsorted();
    bool IsFull() const;
    int LengthIs() const;
    void RetrieveItem(Countries& item, bool& found);
    void InsertItem(Countries item);
    void DeleteItem(Countries item);
    void ResetList();
    void GetNextItem(Countries& item);
    int GetCurrentPos();

private:
    int length;
    Countries info[MAX_ITEMS];
    int currentPos;
};
