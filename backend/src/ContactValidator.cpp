#include "../include/ContactValidator.h"

// static allows constant used for validation per class
const std::set<std::string> ContactValidator::allowedTags = {"Friends", "Family", "Work",
                                                             "Emergency", "Other"};
