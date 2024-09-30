#pragma once
#include "personType.h"
#include "dateType.h"
#include "addressType.h"
#include <iostream>
#include <string>

using namespace std;

class extPersonType : public personType {
private:
    dateType birthdate;
    addressType address;
    string phoneNumber;
    string relationship;

public:
    // Default constructor
    extPersonType() : personType(), birthdate(), address() {
        phoneNumber = "";
        relationship = "Friend";
    }

    // Parameterized constructor
    extPersonType(const string& first, const string& last, int month, int day, int year,
        const string& streetAddress, const string& city, const string& state, int zip,
        const string& phone, const string& rel)
        : personType(first, last), birthdate(month, day, year), address(streetAddress, city, state, zip) {
        phoneNumber = phone;
        setRelationship(rel);
    }

    // Getter and Setter for phone number
    void setPhoneNumber(const string& phone) { phoneNumber = phone; }
    string getPhoneNumber() const { return phoneNumber; }

    // Getter and Setter for relationship
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

    // Get the birth month
    int getBirthMonth() const {
        return birthdate.getMonth();
    }

    // Print function
    void print() const override {
        personType::print();
        birthdate.print();
        address.print();
        cout << "Phone: " << phoneNumber << endl;
        cout << "Relationship: " << relationship << endl;
    }
};

