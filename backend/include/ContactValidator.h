#ifndef CONTACT_VALIDATOR_H_
#define CONTACT_VALIDATOR_H_
#include <iostream>
#include <regex>
#include <set>
#include <string>

#include "ContactDTO.h"

class ContactValidator {
   private:
    // we will push the error message into error vector
    mutable std::vector<std::string>
        errors;  // mutable allows modification even inside const methods like below validate()

    // TODO: Add more tags if needed
    const std::set<std::string> allowedTags{"Friends", "Family", "Work", "Emergency", "Other"};

    bool isValidName(const std::string& name) const {
        if (name.empty()) {
            errors.push_back("Name cannot be empty.");
            return false;
        }
        if (name.size() > 100) {
            errors.push_back("Name cannot exceed 100 characters.");
            return false;
        }
        // otherwise true
        return true;
    }

    bool isValidPhoneNumber(const std::string& phone_number) const {
        if (!std::regex_match(phone_number, std::regex(R"(^\d{10}$)"))) {
            errors.push_back("Phone number must be 10 digits");
            return false;
        }
        // otherwise ture
        return true;
    }

    bool isValidEmail(const std::string& email) const {
        if (!std::regex_match(email, std::regex(R"(\w+@\w+\.\w+)"))) {
            errors.push_back("Invalid email format");
            return false;
        }
        return true;
    }

    bool isValidTag(const std::string& tag) const {
        // if find reaches at the end, than its not valid tag
        if (allowedTags.find(tag) == allowedTags.end()) {
            errors.push_back("Tag must be: Friends, Family, Work, Emergency or, Other");
            return false;
        }
        return true;
    }

   public:
    // Validates each field of the ContactDTO from frontend input.
    // - Clears previous errors
    // - Runs all field checks (name, phone, email, tag)
    // - Collects all errors for full feedback (no early return)
    // - Returns true if all fields are valid
    // Collected errors are sent back to the frontend if validation fails.
    bool validate(const ContactDTO& dto) const {
        errors.clear();  // Clear previous error messages
        bool valid = true;

        valid &= isValidName(dto.name);
        valid &= isValidPhoneNumber(dto.phone_number);
        valid &= isValidEmail(dto.email);
        valid &= isValidTag(dto.tag);
        return valid;
    }

    // Retrive the list of validation error messeges after calling validate() function
    // This is getter for private errors vector
    // @Returns a references to the list of error messages collected during validation
    const std::vector<std::string>& getError() const { return errors; }
};
#endif  // CONTACT_VALIDATOR_H_
