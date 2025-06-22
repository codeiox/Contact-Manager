#ifndef BASIC_PERSON_H_
#define BASIC_PERSON_H_
#include "Person.h"

class Contact : public Person {
   public:
    Contact();  // default constructor

    // non default constructor
    Contact(std::string p_name, std::string p_phone_number, std::string p_email, std::string p_tag);

    // copy constructor
    Contact(const Person& obj);

    // virtual destructor
    virtual ~Contact();

    // display info
    void displayInfo() const override;

    // group contact by tag
    void groupContact(const std::string& tag) const override;

    // serialize data
    std::string serialize() const override;

    // operator overloading (we need to dynamically downcast the object)
    bool operator==(const Person& other) const override;

    // fromJson overrides from base class
    // converts json data format to object
    void fromJson(const Json::Value& json) override;
};

#endif  // BASIC_PERSON_H_
