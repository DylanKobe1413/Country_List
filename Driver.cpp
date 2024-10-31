// driver.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "CountriesList.h"

int getNumber() {
    srand(static_cast<unsigned int>(time(0)));
    return (rand() % 15) + 6;
}

int main() {
    int records_number = getNumber();
    std::cout << "You need to select " << records_number << " objects from your data file.\n";

    // Open the file
    std::ifstream inputFile("data.txt");
    if (!inputFile) {
        std::cerr << "Error opening file\n";
        return 1;
    }

    Unsorted countryList;
    std::string line;

    // Read the specified number of records
    for (int i = 0; i < records_number && std::getline(inputFile, line); ++i) {
        std::istringstream stream(line);
        std::string name;
        int population;

        // Parse the line
        std::getline(stream, name, ',');
        stream >> population;

        // Create a Countries object and insert into list
        Countries country(name, population);
        countryList.InsertItem(country);
    }

    inputFile.close();

    // Print the list contents
    std::cout << "\nList of selected countries:\n";
    countryList.ResetList();
    Countries item;
    for (int i = 0; i < countryList.LengthIs(); i++) {
        countryList.GetNextItem(item);
        item.Print();
    }

    return 0;
}
