#ifndef CONTACTDTO_H_
#define CONTACTDTO_H_

#include <drogon/HttpRequest.h>
#include <json/json.h>

#include <iostream>
#include <string>

// ContactDTO (Data Transfer Object)
// ContactDTO will hold the receive the data from frontend that
// we can use ContactValidator class to
// validate before further operation

struct ContactDTO {
    std::string name;
    std::string phone_number;
    std::string email;
    std::string tag;

    // Static method to parse JSON into ContactDTO
    static ContactDTO fromJson(const Json::Value& json) {
        ContactDTO dto;
        dto.name = json["name"].asString();
        dto.phone_number = json["phone_number"].asString();
        dto.email = json["email"].asString();
        dto.tag = json["tag"].asString();
        return dto;
    }
};
#endif  // CONTACTDTO_H_
