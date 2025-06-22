#ifndef VALIDATOR_TEMPLATE_H_
#define VALIDATOR_TEMPLATE_H_
#include "Contact.h"

template <typename theType>
class Validator {
   public:
    // default destructor
    virtual ~Validator() = default;

    // validator (pure virtual function, aka abstract class)
    virtual bool validate(const theType& obj) const = 0;
};
#endif  // VALIDATOR_TEMPLATE_H_