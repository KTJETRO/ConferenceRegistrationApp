#ifndef STANDARDREGISTRATION_H
#define STANDARDREGISTRATION_H

#include "Registration.h"

class StandardRegistration : public Registration {
public:
    StandardRegistration(const Person& attendee);

    double calculateFee() const override;
    QString toString() const override;
};

#endif // STANDARDREGISTRATION_H
