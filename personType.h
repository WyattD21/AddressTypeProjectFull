#pragma once
#include <iostream>
#include <string>

using namespace std;

class personType {
private:
    string firstName;
    string lastName;

public:
    // Default constructor
    personType(string first = "", string last = "")
        : firstName(first), lastName(last) {}

    // Virtual print function
    virtual void print() const {
        cout << firstName << " " << lastName << endl;
    }

    // Getters for first and last names
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName;  }

};