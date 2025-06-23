#include "../include/Person.h"

// constructor
Person::Person(std::string p_name, std::string p_phone_number, std::string p_email,
               std::string p_tag) {
    name = p_name;
    phone_number = p_phone_number;
    email = p_email;
    tag = p_tag;
}

// Destructor
Person::~Person() {}

// Pure virtual function doesn't need implementation but derived class must override it.

// Copy constructor to make copy of other object
Person::Person(const Person& other) {
    this->name = other.name;
    this->phone_number = other.phone_number;
    this->email = other.email;
    this->tag = other.tag;
}
