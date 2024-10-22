#include "addressBookType.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    addressBookType addressBook;
    addressBook.initEntry();
    int choice;
    string firstName, lastName;
    string fullName;  // Moved to be initialized at the start
    int month;
    string relationship;

    do {
        cout << "Menu:\n";
        cout << "1. Find Person by Name\n";
        cout << "2. Find Birthdays by Month\n";
        cout << "3. Find Persons by Relationship\n";
        cout << "4. Print All Entries\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Clear any leftover newline characters

        switch (choice) {
        case 1:
            cout << "Enter first name: ";
            getline(cin, firstName);
            cout << "Enter last name: ";
            getline(cin, lastName);
            fullName = lastName + " " + firstName;  // Combine names here
            addressBook.findPerson(fullName);
            break;
        case 2:
            cout << "Enter birth month (1-12): ";
            cin >> month;
            addressBook.findBirthdays(month);
            break;
        case 3:
            cout << "Enter relationship: ";
            cin.ignore();
            getline(cin, relationship);
            addressBook.findRelations(relationship);
            break;
        case 4:
            addressBook.print();
            break;
        case 5:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
