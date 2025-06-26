#include <drogon/drogon.h>

#include <iostream>

#include "../controller/ContactFetch.h"
#include "../include/Contact.h"

int main(int argc, const char *argv[]) {
    drogon::app().addListener("0.0.0.0", 8080).run();

    // print the data
    Contact contact;
    contact.toString();
    return 0;
}