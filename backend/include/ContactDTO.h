#ifndef CONTACTDTO _H_
#define CONTACTDTO _H_
#include <iostream>
#include <string>

// ContactDTO (Data Transfer Object)
struct ContactDTO {
    std::string name;
    std::string phone_number;
    std::string email;
    std::string tag;
};
#endif  // CONTACTDTO _H_