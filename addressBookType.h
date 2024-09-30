#pragma once
#include "extPersonType.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class addressBookType {
private:
    vector<extPersonType> addressList;
    int maxSize;    // Maximum size of the address list
    int length;     // Current number of entries in the list

public:
    // Constructor
    addressBookType(int size = 100) {
        maxSize = size;
        length = 0;
        addressList.resize(maxSize);
    }

    // Function to initialize entries from a file
    void initEntry() {
        ifstream infile("AddressBookData.txt");
        if (!infile) {
            cout << "Error opening file!" << endl;
            return;
        }

        string firstName, lastName, streetAddress, city, state, phone, relationship;
        int month, day, year, zip;

        while (infile >> firstName >> lastName >> month >> day >> year
            >> streetAddress >> city >> state >> zip >> phone >> relationship) {
            extPersonType person(firstName, lastName, month, day, year, streetAddress, city, state, zip, phone, relationship);
            addEntry(person);
        }

        infile.close();
    }

    // Function to add an entry
    void addEntry(const extPersonType& person) {
        if (length < maxSize) {
            addressList[length] = person;
            length++;
        }
        else {
            cout << "Address book is full. Cannot add more entries." << endl;
        }
    }

    // Function to find and print a person's information by last name
    void findPerson(const string& lastName) const {
        for (int i = 0; i < length; i++) {
            if (addressList[i].getLastName() == lastName) {
                addressList[i].print();
                return;
            }
        }
        cout << "Person with last name " << lastName << " not found." << endl;
    }

    // Function to find and print entries by birth month
    void findBirthdays(int month) const {
        bool found = false;
        for (int i = 0; i < length; i++) {
            if (addressList[i].getBirthMonth() == month) {
                addressList[i].print();
                found = true;
            }
        }
        if (!found) {
            cout << "No persons found with birthday in month " << month << "." << endl;
        }
    }

    // Function to find and print entries by relationship
    void findRelations(const string& relationship) const {
        bool found = false;
        for (int i = 0; i < length; i++) {
            if (addressList[i].getRelationship() == relationship) {
                addressList[i].print();
                found = true;
            }
        }
        if (!found) {
            cout << "No persons found with relationship " << relationship << "." << endl;
        }
    }

    // Function to print all entries
    void print() const {
        if (length == 0) {
            cout << "Address book is empty." << endl;
        }
        else {
            for (int i = 0; i < length; i++) {
                addressList[i].print();
                cout << endl;
            }
        }
    }
};

