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

// Getters and setters
void Person::setName(const std::string& p_name) { name = p_name; }
void Person::setPhoneNumber(const std::string& p_number) { phone_number = p_number; }
void Person::setEmail(const std::string& p_email) { email = p_email; }
void Person::setTag(const std::string& p_tag) { tag = p_tag; }

std::string Person::getName() const { return name; }
std::string Person::getPhoneNumber() const { return phone_number; }
std::string Person::getEmail() const { return email; }
std::string Person::getTag() const { return tag; }

