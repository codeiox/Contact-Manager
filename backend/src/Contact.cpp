#include "../include/Contact.h"

#include <sstream>
// Constructor
Contact::Contact(std::string p_name, std::string p_phone_number, std::string p_email,
                 std::string p_tag)
    : Person(p_name, p_phone_number, p_email, p_tag) {}

// copy constructor calls Base class copy constructor
Contact::Contact(const Contact& other) : Person(other) {}

// destructor
Contact::~Contact() {}

// copy assignment Operator=
// copy Contact to Contact class
Contact& Contact::operator=(const Contact& other) {
    if (this != &other) {
        setName(other.getName());
        setEmail(other.getEmail());
        setPhoneNumber(other.getPhoneNumber());
        setTag(other.getTag());
    }
    return *this;  // return object itself
}

// copy assignment Operator=
// copy Person to Contact just delegates
Contact& Contact::operator=(const Person& other) {
    if (this == &other) {
        return *this;  // self-assignment via Person*
    }

    const Contact* contact =
        dynamic_cast<const Contact*>(&other);  // downcast from base class to derived class
    if (contact) {
        *this = *contact;  // delegates to overload above
    }
    return *this;  // return object itself
}

// display info for debugging purpose
std::ostream& operator<<(std::ostream& output, const Contact& contact) {
    output << contact.toString() << "\n";
    return output;
}

std::string Contact::toString() const {
    std::ostringstream oss;
    oss << "Name: " << getName() << "\nPhone Number: " << getPhoneNumber()
        << "\nEmail: " << getEmail() << "\nTag: " << getTag();

    return oss.str();
}

// equality operator overloading
bool Contact::operator==(const Person& other) const {
    const Contact* contact = dynamic_cast<const Contact*>(&other);

    return (this->getName() == contact->getName() &&
            this->getPhoneNumber() == contact->getPhoneNumber() &&
            this->getEmail() == contact->getEmail() && this->getTag() == contact->getTag());
}

bool Contact::operator!=(const Person& other) const { return !(*this == other); }

// TODO: groupContact by tag.
// ! Important:  we may have to create another class to deal with grouping part.

// TODO: // TODO: On startup, read contacts.json and deserialize its contents into Contact objects
// so the app can restore all saved contacts and pick up exactly where it left off.

// TODO: fromJson function
