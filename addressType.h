#pragma once
#include <iostream>
#include <string>

using namespace std;

class addressType {
private:
    string streetAddress;
    string city;
    string state;
    int zipCode;

public:
    // Default constructor
    addressType(string street = "", string cityName = "", string stateCode = "XX", int zip = 10000) {
        setAddress(street);
        setCity(cityName);
        setState(stateCode);
        setZipcode(zip);
    }

    // setter for address
    void setAddress(string street) {
        streetAddress = street;
    }

    // setter for city
    void setCity(string cityName) {
        city = cityName;
    }

    // setter for state with two-character restriction
    void setState(string stateCode) {
        if (stateCode.length() == 2) {
            state = stateCode;
        }
        else {
            state = "XX";
        }
    }

    // setter for zip code with value range restriction
    void setZipcode(int zip) {
        if (zip >= 11111 && zip <= 99999) {
            zipCode = zip;
        }
        else {
            zipCode = 10000;
        }
    }

    // Getter for street address
    string getStreetAddress() const {
        return streetAddress;
    }

    // getter for city
    string getCity() const {
        return city;
    }

    // getter for state
    string getState() const {
        return state;
    }

    // getter for zip code
    int getZipCode() const {
        return zipCode;
    }

    // ensures the display is in the correct format
    void print() const {
        cout << streetAddress << endl
            << city << ", " << state << " " << zipCode << endl;
    }
};

