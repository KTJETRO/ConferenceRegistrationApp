#include "Registration.h"

const double Registration::STANDARD_FEE = 100.0;

Registration::Registration(const Person& attendee)
    : m_Attendee(attendee), m_BookingDate(QDate::currentDate())
{}

Person Registration::getAttendee() const {
    return m_Attendee;
}

QDate Registration::getBookingDate() const {
    return m_BookingDate;
}
