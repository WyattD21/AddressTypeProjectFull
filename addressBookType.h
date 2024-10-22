#pragma once
#include "extPersonType.h"
#include "orderedLinkedList.h"
#include <iostream>
#include <fstream>
#include <string>

class addressBookType : public orderedLinkedList<extPersonType> {
public:
    addressBookType(int size = 100) {}

    void initEntry() {
        ifstream infile("AddressBookData.txt");
        if (!infile) {
            cerr << "Error opening file!" << endl;
            return;
        }

        string firstName, lastName, streetAddress, city, state, phone, relationship;
        int month, day, year, zip;

        while (infile >> firstName >> lastName >> month >> day >> year) {
            infile.ignore();
            getline(infile, streetAddress);
            getline(infile, city);
            infile >> state >> zip >> phone >> relationship;

            extPersonType person(firstName, lastName, month, day, year, streetAddress, city, state, zip, phone, relationship);
            insert(person);

            cout << "Added: " << firstName << " " << lastName << endl;
        }

        infile.close();
    }

    void findPerson(const string& fullName) const {
        nodeType<extPersonType>* current = first;

        while (current != nullptr) {
            string key = current->info.getLastName() + " " + current->info.getFirstName();
            if (key == fullName) {
                current->info.print();
                return;
            }
            current = current->link;
        }

        cout << "Person not found." << endl;
    }

    void findBirthdays(int month) const {
        nodeType<extPersonType>* current = first;
        bool found = false;

        while (current != nullptr) {
            if (current->info.getBirthMonth() == month) {
                current->info.print();
                found = true;
            }
            current = current->link;
        }

        if (!found) {
            cout << "No persons found with birthday in month " << month << "." << endl;
        }
    }

    void findRelations(const string& relationship) const {
        nodeType<extPersonType>* current = first;
        bool found = false;

        while (current != nullptr) {
            if (current->info.getRelationship() == relationship) {
                current->info.print();
                found = true;
            }
            current = current->link;
        }

        if (!found) {
            cout << "No persons found with relationship " << relationship << "." << endl;
        }
    }

    void print() const {
        nodeType<extPersonType>* current = first;

        while (current != nullptr) {
            current->info.print();
            cout << endl;
            current = current->link;
        }
    }
};
