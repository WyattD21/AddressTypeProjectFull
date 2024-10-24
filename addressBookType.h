#pragma once
#include "extPersonType.h"
#include "orderedLinkedList.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class addressBookType : public orderedLinkedList<extPersonType> {
public:
    addressBookType(int size = 100) {}

    //Added a clock for when the file is changed
    string getFormattedTime() const {
        time_t now = time(0);
        struct tm timeinfo;
        localtime_s(&timeinfo, &now);

        char buffer[80];
        strftime(buffer, sizeof(buffer), "%m/%d/%Y %H:%M:%S", &timeinfo);
        return string(buffer);
    }

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

    void addEntryInteractively() {
        string firstName, lastName, streetAddress, city, state, phone, relationship;
        int month, day, year, zip;

        cout << "Enter first name: ";
        getline(cin, firstName);
        cout << "Enter last name: ";
        getline(cin, lastName);
        cout << "Enter birth month (1-12): ";
        cin >> month;
        cout << "Enter birth day: ";
        cin >> day;
        cout << "Enter birth year: ";
        cin >> year;
        cin.ignore();
        cout << "Enter street address: ";
        getline(cin, streetAddress);
        cout << "Enter city: ";
        getline(cin, city);
        cout << "Enter state: ";
        getline(cin, state);
        cout << "Enter zip code: ";
        cin >> zip;
        cout << "Enter phone number: ";
        cin >> phone;
        cin.ignore();
        cout << "Enter relationship (Family, Friend, Business): ";
        getline(cin, relationship);

        extPersonType newPerson(firstName, lastName, month, day, year, streetAddress, city, state, zip, phone, relationship);
        insert(newPerson);

        srand(static_cast<unsigned int>(time(0)));  // Had to make srand safe, caused memory leaks
        int randomID = rand() % 10000;

        //Outputs the time the entry was added
        cout << "New entry added at: " << getFormattedTime() << endl;
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
    void deletePerson(const string& fullName) {
        deleteNode(extPersonType(fullName));
        cout << fullName << " has been deleted from Address Book data at " << getFormattedTime() << endl;
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

    void saveToFile() const {
        ofstream outfile("AddressBookData.txt");
        if (!outfile) {
            cerr << "Error opening file for saving!" << endl;
            return;
        }

        nodeType<extPersonType>* current = first;
        while (current != nullptr) {
            outfile << current->info.getFirstName() << " "
                << current->info.getLastName() << " "
                << current->info.getBirthMonth() << " "
                << current->info.getBirthDay() << " "
                << current->info.getBirthYear() << endl;
            outfile << current->info.getStreetAddress() << endl;
            outfile << current->info.getCity() << " "
                << current->info.getState() << " "
                << current->info.getZipCode() << endl;
            outfile << current->info.getPhoneNumber() << " "
                << current->info.getRelationship() << endl;

            current = current->link;
        }

        outfile.close();
        cout << "Address book saved successfully at " << getFormattedTime()<< endl;
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
