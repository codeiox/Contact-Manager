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
    Person();  // default constructor

    // non-default constructor
    Person(std::string p_name, std::string p_phone_number, std::string p_email, std::string p_tag);

    virtual ~Person();  // pure virtual destructor

    Person(const Person& obj);  // copy constructor

    // pure virtual function (known as abstract)
    virtual void displayInfo() const = 0;

    // pure virtual function (known as abstract)
    virtual void groupContact(const std::string& tag) const = 0;

    // operator == overloading
    virtual bool operator==(const Person& other) const = 0;

    // toString function to return a string representation of the object
    virtual std::string toString() const = 0;

    // ostream operator<< overloading (ONLY for debugging purposes)
    friend std::ostream& operator<<(std::ostream& output, const Person& person);

    // serialize data
    virtual std::string serialize() const = 0;

    // Mutators and Accessors
    void setName(const std::string& p_name);
    void setPhoneNumber(const std::string& p_phone_number);
    void setEmail(const std::string& p_email);
    void setTag(const std::string& p_tag);

    std::string getName() const;
    std::string getPhoneNumber() const;
    std::string getEmail() const;
    std::string getTag() const;

    // fromJson function to populate the object from a JSON representation
    // This function should be implemented in derived classes to handle specific JSON structures
    virtual void fromJson(const Json::Value& json) = 0;
};

#endif  // PERSON_H_
