#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "Person.h"
#include <QDate>

class Registration {
public:
    static const double STANDARD_FEE;

    Registration(const Person& attendee);
    virtual ~Registration() = default;

    Person getAttendee() const;
    QDate getBookingDate() const;
    virtual double calculateFee() const = 0;
    virtual QString toString() const = 0;

protected:
    Person m_Attendee;
    QDate m_BookingDate;
};

#endif // REGISTRATION_H

