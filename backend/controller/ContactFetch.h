#ifndef CONTACTFETCH_H_
#define CONTACTFETCH_H_
#include <drogon/HttpController.h>

// This class makes api request to frontend via drogon HTTP method
// HttpController<> base class of drogon framework
// ContactFetch inherits from drogon
class ContactFetch : public drogon::HttpController<ContactFetch> {
   public:
    METHOD_LIST_BEGIN  // routing BEGIN to request/response macro

        // ADD_METHOD_TO tells drogon what route should I listen to
        // Backend listens to frontend end-point: /api/contacts/add
        // When the frontend sends a POST request to /api/contacts/add,
        // Drogon will route that request to the handleAddContact() method
        ADD_METHOD_TO(ContactFetch::handleAddContact, "/api/contacts/add", drogon::Post);
    METHOD_LIST_END  // routing END to request/response macro

        void
        handleAddContact(const drogon::HttpRequestPtr& req,
                         std::function<void(const drogon::HttpResponsePtr&)>&& callback);
};

#endif  // CONTACTFETCH_H_