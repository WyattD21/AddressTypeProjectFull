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
    addressType(string street = "", string cityName = "", string stateCode = "XX", int zip = 10000) {
        setAddress(street);
        setCity(cityName);
        setState(stateCode);
        setZipcode(zip);
    }

    void setAddress(string street) { streetAddress = street; }

    void setCity(string cityName) { city = cityName; }

    void setState(string stateCode) {
        if (stateCode.length() == 2) {
            state = stateCode;
        }
        else {
            state = "XX";
        }
    }

    void setZipcode(int zip) {
        if (zip >= 11111 && zip <= 99999) {
            zipCode = zip;
        }
        else {
            zipCode = 10000;
        }
    }

    string getStreetAddress() const { return streetAddress; }
    string getCity() const { return city; }
    string getState() const { return state; }
    int getZipCode() const { return zipCode; }

    void print() const {
        cout << streetAddress << endl << city << ", " << state << " " << zipCode << endl;
    }
};
