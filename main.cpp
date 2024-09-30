#pragma once
#include "addressBookType.h"

int main() {
    addressBookType addressBook;
    addressBook.initEntry();

    int choice;
    string lastName;
    int month;
    string relationship;

    do {
        cout << "Menu:\n";
        cout << "1. Find Person by Last Name\n";
        cout << "2. Find Birthdays by Month\n";
        cout << "3. Find Persons by Relationship\n";
        cout << "4. Print All Entries\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter last name: ";
            cin >> lastName;
            addressBook.findPerson(lastName);
            break;
        case 2:
            cout << "Enter birth month (1-12): ";
            cin >> month;
            addressBook.findBirthdays(month);
            break;
        case 3:
            cout << "Enter relationship (Family, Friend, Business): ";
            cin >> relationship;
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
