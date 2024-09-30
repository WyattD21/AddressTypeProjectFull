#pragma once
#include "personType.h"
#include "dateType.h"
#include "addressType.h"
#include <iostream>
#include <string>

using namespace std;

class extPersonType : public personType {
private:
    dateType birthdate;     // Composition: dateType instance
    addressType address;    // Composition: addressType instance
    string phoneNumber;     // Additional member variables
    string relationship;

public:
    // Default constructor
    extPersonType()
        : personType(), birthdate(), address() {  // Initialize base class and member objects
        phoneNumber = "";
        relationship = "Friend";
    }

    // Parameterized constructor
    extPersonType(const string& first, const string& last, int month, int day, int year,
        const string& streetAddress, const string& city, const string& state, int zip,
        const string& phone, const string& rel)
        : personType(first, last), birthdate(month, day, year),
        address(streetAddress, city, state, zip) {
        phoneNumber = phone;
        setRelationship(rel);
    }

    // Setter and Getter for phone number
    void setPhoneNumber(const string& phone) { phoneNumber = phone; }
    string getPhoneNumber() const { return phoneNumber; }

    // Setter and Getter for relationship
    void setRelationship(const string& rel) {
        if (rel == "Family" || rel == "Friend" || rel == "Business") {
            relationship = rel;
        }
        else {
            cout << "Invalid relationship. Setting to 'Friend' by default." << endl;
            relationship = "Friend";
        }
    }

    string getRelationship() const { return relationship; }

    // Print function
    void print() const override {  // Correctly overrides the base class print
        personType::print();  // Call the print function of the base class
        birthdate.print();     // Call the print function for the date
        address.print();       // Call the print function for the address
        cout << "Phone: " << phoneNumber << endl; // Display the phone number
        cout << "Relationship: " << relationship << endl; // Display the relationship
    }
};
