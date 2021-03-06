//
// Created by Nicolae Marius Ghergu on 19.12.2021.
//

#ifndef UTILITYIT_WRONGPASSWORDEXCEPTION_H
#define UTILITYIT_WRONGPASSWORDEXCEPTION_H

#include "BaseException.h"

class BaseException;

class WrongPasswordException : virtual public BaseException {

public:

    WrongPasswordException() = default;

    // constructor de initializare
    explicit WrongPasswordException(const std::string &customMessage);

    // destructor
    ~WrongPasswordException() override = default;

    std::string getCustomMessage() override;

    void setCustomMessage(const std::string &customMessage) override;
};


#endif //UTILITYIT_WRONGPASSWORDEXCEPTION_H
