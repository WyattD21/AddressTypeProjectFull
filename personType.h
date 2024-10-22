#pragma once
#include <iostream>
#include <string>
using namespace std;

class personType {
private:
    string firstName;
    string lastName;

public:
    personType(string first = "", string last = "")
        : firstName(first), lastName(last) {}

    virtual void print() const {
        cout << firstName << " " << lastName << endl;
    }

    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }

    //setFirstName and setLastName methods
    void setFirstName(const string& first) { firstName = first; }
    void setLastName(const string& last) { lastName = last; }
};
