//"copyright 2025"

#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include <cxxtest/TestSuite.h>

// Include your classes header file(s) below and uncomment.
// #include "myClass.h"
#include <drogon/HttpRequest.h>
#include <drogon/HttpResponse.h>
#include <json/json.h>

#include "../controller/ContactDTO.h"
#include "../controller/ContactFetch.h"
#include "../controller/ContactValidator.h"
#include "../include/Contact.h"

using namespace drogon;

class testContactFetch : public CxxTest::TestSuite {
   public:
    static void testHandleContact() {
        // Manually build the JSON
        Json::Value json;
        json["name"] = "John Doe";
        json["phone_number"] = "123-434-7890";
        json["email"] = "JohnDoe@gmail.com";
        json["tag"] = "Family";

        // Create a new HttpRequestPtr pointer initialized with JSON payload 'json' and the correct
        // Content-Type header.
        HttpRequestPtr request = drogon::HttpRequest::newHttpJsonRequest(json);

        // Call ContactFetch.h haldler function to capture the response
        ContactFetch controller;
        HttpResponsePtr response;

        // indicator
        bool called = false;
        controller.handleAddContact(request, [&](const HttpResponsePtr &resp) {
            response = resp;
            called = true;
        });

        TS_ASSERT(called);
        TS_ASSERT(response);

        // Test response Status code 200 OK
        TS_ASSERT_EQUALS(response->getStatusCode(), k200OK);

        std::shared_ptr<Json::Value> out = response->getJsonObject();
        TS_ASSERT(out);
        TS_ASSERT_EQUALS((*out)["status"].asString(), "ok");
        TS_ASSERT_EQUALS((*out)["savedName"].asString(), "John Doe");
    }
};
#endif /* NEWCXXTEST_H */
