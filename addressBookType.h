#pragma once
#include "extPersonType.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sys/stat.h>

class addressBookType {
private:
    vector<extPersonType> addressList;
    int maxSize;
    int length;

public:
    addressBookType(int size = 100) {
        maxSize = size;
        length = 0;
        addressList.resize(maxSize);
    }

    void initEntry() {
        const char* filename = "AddressBookData.txt";
        ifstream infile(filename);

        if (!infile) {
            cerr << "Error opening file! Ensure the file exists and is in the correct directory." << endl;
            return;
        }

        string firstName, lastName, streetAddress, city, state, phone, relationship;
        int month, day, year, zip;

        while (infile >> firstName >> lastName >> month >> day >> year) {
            infile.ignore(); // Ignore the newline character after year

            getline(infile, streetAddress);
            getline(infile, city);
            infile >> state >> zip >> phone >> relationship;

            extPersonType person(firstName, lastName, month, day, year, streetAddress, city, state, zip, phone, relationship);
            addEntry(person);

            // Debug print statement
            cout << "Added: " << firstName << " " << lastName << ", " << month << "/" << day << "/" << year << ", "
                << streetAddress << ", " << city << ", " << state << ", " << zip << ", " << phone << ", " << relationship << endl;
        }

        infile.close();
    }

    void addEntry(const extPersonType& person) {
        if (length < maxSize) {
            addressList[length] = person;
            length++;
        }
        else {
            cout << "Address book is full. Cannot add more entries." << endl;
        }
    }

    void findPerson(const string& lastName) const {
        for (int i = 0; i < length; i++) {
            if (addressList[i].getLastName() == lastName) {
                addressList[i].print();
                return;
            }
        }
        cout << "Person with last name " << lastName << " not found." << endl;
    }

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
