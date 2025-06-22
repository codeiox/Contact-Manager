#ifndef CONTACT_VALIDATOR_H_
#define CONTACT_VALIDATOR_H_
#include <set>

#include "Contact.h"
#include "Validator.h"

// CONTACT validator class to validate the contact info
// derived from the validator drived class
class ContactValidator : public Validator<Contact> {
   private:
    static const std::set<std::string> allowedTags;  // allowed tags for validation
    // validate name
    bool isValidName(const std::string& name) const;
    // validate phone number
    bool isValidPhoneNumber(const std::string& phone_number) const;
    // valitate email
    bool isValidEmail(const std::string& email) const;

    // validate tag for data grouping consistency, eg.. (Friends, Family, Work, Emergency, Other)
    bool isValidTag(const std::string& tag) const;

   public:
    // takes the person object for validation
    bool validate(const Contact& person) const override;
};
#endif  // CONTACT_VALIDATOR_H_
