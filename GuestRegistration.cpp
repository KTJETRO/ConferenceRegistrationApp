#include "GuestRegistration.h"

GuestRegistration::GuestRegistration(const Person& attendee, const QString& category)
    : Registration(attendee), m_Category(category)
{}

double GuestRegistration::calculateFee() const {
    return STANDARD_FEE * 0.1;
}

QString GuestRegistration::toString() const {
    return QString("Guest: %1, Category: %2").arg(m_Attendee.toString(), m_Category);
}
