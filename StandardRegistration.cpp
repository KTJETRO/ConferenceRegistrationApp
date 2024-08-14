#include "StandardRegistration.h"

StandardRegistration::StandardRegistration(const Person& attendee)
    : Registration(attendee) {
}

double StandardRegistration::calculateFee() const {
    return STANDARD_FEE;  // Assuming STANDARD_FEE is defined somewhere (e.g., in Registration.h)
}

QString StandardRegistration::toString() const {
    return QString("Standard: %1").arg(m_Attendee.toString());
}
