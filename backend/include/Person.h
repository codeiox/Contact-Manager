#ifndef PERSON_H_
#define PERSON_H_
#include <json/json.h>  // Assuming you are using the JsonCpp library

#include <iostream>
#include <string>

class Person {
   private:
    std::string name;
    std::string phone_number;
    std::string email;
    std::string tag;

   public:
    Person() = default;  // default constructor

    // non-default constructor
    Person(std::string p_name, std::string p_phone_number, std::string p_email, std::string p_tag);

    virtual ~Person() = 0;  // pure virtual destructor

    Person(const Person& other);  // copy constructor

    // copy asignment Operator
    // Derived class must override this function
    virtual Person& operator=(const Person& other) = 0;

    // operator == overloading
    // Derived class must override this function
    virtual bool operator==(const Person& other) const = 0;

    virtual bool operator!=(const Person& other) const = 0;

    // display info
    virtual std::string toString() const = 0;

    // Mutators and Accessors
    void setName(const std::string& p_name);
    void setPhoneNumber(const std::string& p_phone_number);
    void setEmail(const std::string& p_email);
    void setTag(const std::string& p_tag);

    std::string getName() const;
    std::string getPhoneNumber() const;
    std::string getEmail() const;
    std::string getTag() const;
};

#endif  // PERSON_H_
