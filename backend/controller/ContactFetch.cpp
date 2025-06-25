// controller/ContactFetch.cpp
#include "ContactFetch.h"

#include <iostream>
#include <string>

#include "../include/Contact.h"
#include "ContactDTO.h"
#include "ContactValidator.h"

using namespace drogon;

// req for incomming HTTP request
// callback for response back to frontend/client
void ContactFetch::handleAddContact(
    const drogon::HttpRequestPtr& req,
    std::function<void(const drogon::HttpResponsePtr&)>&& callback) {
    auto json = req->getJsonObject();

    if (!json) {
        auto resp = HttpResponse::newHttpResponse();  // create a new HTTP response
        // If JSON parsing fails, we return a 400 Bad Request response
        resp->setStatusCode(k400BadRequest);      // HTTP status code
        resp->setContentTypeCode(CT_TEXT_PLAIN);  // Content type of the response
        resp->setBody("Invalid JSON");            // Body of the response
        callback(resp);                           // send the response back to the client
        return;
    }

    ContactDTO dto = ContactDTO::fromJson(*json);  // Convert JSON to ContactDTO
    ContactValidator validator;                    // Create a validator instance

    if (!validator.validate(dto)) {  // Validate the DTO

        // If validation fails, we create a JSON response with error messages
        Json::Value errJson;
        errJson["status"] = "error";  // Status of the response
        // Collect all validation errors
        for (const auto& err :
             validator.getError()) {        // Get errors from the ContactValidator vector
            errJson["errors"].append(err);  // Append each error to the JSON response
        }

        auto resp = HttpResponse::newHttpJsonResponse(
            errJson);                         // Create a new HTTP response with JSON content
        resp->setStatusCode(k400BadRequest);  // Set the HTTP status code to 400 Bad Request
        callback(resp);                       // Send the response back to the client
        return;                               // Exit the function after sending the response
    }

    // if data is valid, we construct the Person derived class Contact.h
    // calls the Contact constructor with the validated data
    Contact contact(dto.name, dto.phone_number, dto.email, dto.tag);

    // If validation is successful, we create a success response
    // This response indicates that the contact data is valid
    Json::Value success;
    success["status"] = "success";
    success["message"] = "Contact data is valid.";
    auto resp = HttpResponse::newHttpJsonResponse(success);
    callback(resp);
}
