//"copyright 2025"

#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include <cxxtest/TestSuite.h>

#include "../include/Contact.h"
#include "../include/Person.h"

class testContact : public CxxTest::TestSuite {
   public:
    static void testPersonClass() {
        // call contact.h class to test
        Contact contact = Contact("John Doe", "123-432-9032", "John@gmail.com", "Family");
        TS_ASSERT_EQUALS(contact.getName(), "John Doe");
        TS_ASSERT_EQUALS(contact.getPhoneNumber(), "123-432-9032");
        TS_ASSERT_EQUALS(contact.getEmail(), "John@gmail.com");
        TS_ASSERT_EQUALS(contact.getTag(), "Family");


        // Test setters and getters
        contact.setName("James anderson");
        contact.setPhoneNumber("123-456-7890");
        contact.setEmail("James@gmail.com");
        contact.setTag("Friend");

        TS_ASSERT_EQUALS(contact.getName(), "James anderson");
        TS_ASSERT_EQUALS(contact.getPhoneNumber(), "123-456-7890");
        TS_ASSERT_EQUALS(contact.getEmail(), "James@gmail.com");
        TS_ASSERT_EQUALS(contact.getTag(), "Friend");


        // test Person.h Copy Constructor
        Contact contactCopy(contact); // makes the deep copy of current contact object
        TS_ASSERT_EQUALS(contactCopy.getName(), "James anderson");
        TS_ASSERT_EQUALS(contactCopy.getPhoneNumber(), "123-456-7890");
        TS_ASSERT_EQUALS(contactCopy.getEmail(), "James@gmail.com");
        TS_ASSERT_EQUALS(contactCopy.getTag(), "Friend");
    }

    static void testContactClass() {
        // test copy assignment operator
        Contact contact = Contact("Madison miller", "123-432-9032", "Madison@gmail.com", "Work");
        Contact contactCopy;
        contactCopy = contact; // copy assignment operator
        TS_ASSERT_EQUALS(contactCopy.getName(), "Madison miller");
        TS_ASSERT_EQUALS(contactCopy.getPhoneNumber(), "123-432-9032");
        TS_ASSERT_EQUALS(contactCopy.getEmail(), "Madison@gmail.com");
        TS_ASSERT_EQUALS(contactCopy.getTag(), "Work");

        TS_ASSERT_EQUALS(contactCopy, contact);



        // test copy assignment Person to Contact using pointer
        // Polymorphism and dynamic down casting
        Person* personPtr = new Contact("Alice Smith", "987-654-3210", "Alice@gmail.com", "Colleague");
        Contact contactFromPerson;
        contactFromPerson = *personPtr; // copy assignment operator assign to Contact using pointer dereference
        TS_ASSERT_EQUALS(contactFromPerson.getName(), "Alice Smith");
        TS_ASSERT_EQUALS(contactFromPerson.getPhoneNumber(), "987-654-3210");
        TS_ASSERT_EQUALS(contactFromPerson.getEmail(), "Alice@gmail.com");
        TS_ASSERT_EQUALS(contactFromPerson.getTag(), "Colleague");

        // testing operator<<
        std::ostringstream oss;
        oss << contactFromPerson;
        TS_ASSERT_EQUALS(oss.str(), "Name: Alice Smith\nPhone Number: 987-654-3210\nEmail: Alice@gmail.com\nTag: Colleague\n");
        delete personPtr; // clean up the dynamically allocated memory


        // test operator== and operator!=
        Contact contact1("Bob Brown", "111-222-3333", "Bob@gmail.com", "Friend");
        Contact contact2("Bob Brown", "111-222-3333", "Bob@gmail.com", "Friend");
        Contact contact3("Charlie Green", "444-555-6666", "Charlie@gmail.com", "Family");

        TS_ASSERT_EQUALS(contact1 == contact2, true);  // should be equal
        TS_ASSERT_EQUALS(contact1 != contact3, true);  // should not be equal

    }


};
#endif /* NEWCXXTEST_H */
