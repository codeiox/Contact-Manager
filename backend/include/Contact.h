#ifndef BASIC_PERSON_H_
#define BASIC_PERSON_H_
#include "Person.h"

class Contact : public Person {
    // TODO: we may need to include private data fields to extend the derived class.
    // TODO: maybe timestamp or address, etc to extend the functionality of Person class.
   public:
    Contact() = default;  // default constructor

    // non default constructor
    Contact(std::string p_name, std::string p_phone_number, std::string p_email, std::string p_tag);

    // Rule of 3 ////////////////////
    // copy constructor
    Contact(const Contact& other);

    // virtual destructor
    virtual ~Contact();
    // Copy Assignment operator for Contact class
    Contact& operator=(const Contact& other);

    // Dynamically down cast the object
    // Copy Assignment operator
    Contact& operator=(const Person& other) override;
    ////////////////////////////////

    // ostream operator overloading
    friend std::ostream& operator<<(std::ostream& output, const Contact& contact);
    // display info
    std::string toString() const override;

    // operator== overloading (down casting is needed)
    bool operator==(const Person& other) const override;

    // operator!= overloading (down casting is needed)
    bool operator!=(const Person& other) const override;

    // group contact by tag
    void groupContact(const std::string& tag) const;

    /**
     * Serializes the current contact list into a single JSON-formatted std::string.
     * This string can then be saved to disk or sent over the network,
     * and later passed to deserialize() to fully restore the in-memory state.
     */

    //! Important: We may have to move serialize() and deserialize() func to seperate class or
    //! struct

    std::string serialize() const;

    std::string deserialize() const;
};

#endif  // BASIC_PERSON_H_
