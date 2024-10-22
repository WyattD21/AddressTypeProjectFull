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
    extPersonType() : personType(), birthdate(), address() {
        phoneNumber = "";
        relationship = "Friend";
    }

    extPersonType(const string& first, const string& last, int month, int day, int year,
        const string& streetAddress, const string& city, const string& state, int zip,
        const string& phone, const string& rel)
        : personType(first, last), birthdate(month, day, year), address(streetAddress, city, state, zip) {
        phoneNumber = phone;
        setRelationship(rel);
    }

    // Removed setName and assigned directly
    extPersonType(const string& fullName) {
        size_t pos = fullName.find(' ');
        if (pos != string::npos) {
            string firstName = fullName.substr(pos + 1);
            string lastName = fullName.substr(0, pos);
            setFirstName(firstName);
            setLastName(lastName);
        }
    }

    void setPhoneNumber(const string& phone) { phoneNumber = phone; }
    string getPhoneNumber() const { return phoneNumber; }

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

    int getBirthMonth() const { return birthdate.getMonth(); }
    int getBirthDay() const { return birthdate.getDay(); }  // fixed getDay
    int getBirthYear() const { return birthdate.getYear(); }  // fixed getYear

    string getStreetAddress() const { return address.getStreetAddress(); }
    string getCity() const { return address.getCity(); }
    string getState() const { return address.getState(); }
    int getZipCode() const { return address.getZipCode(); }

    void print() const override {
        personType::print();
        birthdate.print();
        address.print();
        cout << "Phone: " << phoneNumber << endl;
        cout << "Relationship: " << relationship << endl;
    }

    // Overload operators based on first and last name
    bool operator==(const extPersonType& other) const {
        string thisKey = getLastName() + " " + getFirstName();
        string otherKey = other.getLastName() + " " + other.getFirstName();
        return thisKey == otherKey;
    }

    bool operator!=(const extPersonType& other) const {
        return !(*this == other);
    }

    bool operator>=(const extPersonType& other) const {
        string thisKey = getLastName() + " " + getFirstName();
        string otherKey = other.getLastName() + " " + other.getFirstName();
        return thisKey >= otherKey;
    }
};
