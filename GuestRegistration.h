#ifndef GUESTREGISTRATION_H
#define GUESTREGISTRATION_H

#include "Registration.h"

class GuestRegistration : public Registration {
public:
    GuestRegistration(const Person& attendee, const QString& category);

    double calculateFee() const override;
    QString toString() const override;

private:
    QString m_Category;
};

#endif // GUESTREGISTRATION_H

