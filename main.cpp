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
    string fullName;
    int month;
    string relationship;

    do {
        cout << "Menu:\n";
        cout << "1. Add New Entry\n";
        cout << "2. Find Person by Name\n";
        cout << "3. Find Birthdays by Month\n";
        cout << "4. Find Persons by Relationship\n";
        cout << "5. Delete Person by Name\n";
        cout << "6. Print All Entries\n";
        cout << "7. Exit and Save\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Clear any leftover newline characters

        switch (choice) {
        case 1:
            addressBook.addEntryInteractively();  // New function for interactive entry
            break;
        case 2:
            cout << "Enter first name: ";
            getline(cin, firstName);
            cout << "Enter last name: ";
            getline(cin, lastName);
            fullName = lastName + " " + firstName;
            addressBook.findPerson(fullName);
            break;
        case 3:
            cout << "Enter birth month (1-12): ";
            cin >> month;
            addressBook.findBirthdays(month);
            break;
        case 4:
            cout << "Enter relationship: ";
            cin.ignore();
            getline(cin, relationship);
            addressBook.findRelations(relationship);
            break;
        case 5:
            cout << "Enter first name: ";
            getline(cin, firstName);
            cout << "Enter last name: ";
            getline(cin, lastName);
            fullName = lastName + " " + firstName;
            addressBook.deletePerson(fullName);  // New function for deleting a person
            break;
        case 6:
            addressBook.print();
            break;
        case 7:
            addressBook.saveToFile();  // Save data before quitting
            cout << "Exiting and saving data..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
