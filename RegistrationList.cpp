#include "RegistrationList.h"

RegistrationList::RegistrationList() {}

bool RegistrationList::addRegistration(const Registration& r) {
    // Check if the attendee is already registered
    for (Registration* reg : m_RegistrationList) {
        if (reg->getAttendee().getName() == r.getAttendee().getName()) {
            return false; // Already registered
        }
    }

    // Add registration to appropriate list based on type
    if (dynamic_cast<const StudentRegistration*>(&r)) {
        m_StudentRegistrationList.append(new StudentRegistration(dynamic_cast<const StudentRegistration&>(r)));
        m_RegistrationList.append(m_StudentRegistrationList.last());
    } else if (dynamic_cast<const GuestRegistration*>(&r)) {
        m_GuestRegistrationList.append(new GuestRegistration(dynamic_cast<const GuestRegistration&>(r)));
        m_RegistrationList.append(m_GuestRegistrationList.last());
    } else if (dynamic_cast<const StandardRegistration*>(&r)) {
        m_RegistrationList.append(new StandardRegistration(dynamic_cast<const StandardRegistration&>(r)));
    } else {
        return false; // Unsupported registration type
    }

    return true; // Successfully added
}

bool RegistrationList::isRegistered(const QString& name) const {
    for (Registration* reg : m_RegistrationList) {
        if (reg->getAttendee().getName() == name) {
            return true;
        }
    }
    return false;
}

double RegistrationList::totalFee(const QString& type) const {
    double total = 0.0;
    for (Registration* reg : m_RegistrationList) {
        if (type == "All" || (type == "StudentRegistration" && dynamic_cast<StudentRegistration*>(reg)) ||
            (type == "GuestRegistration" && dynamic_cast<GuestRegistration*>(reg)) ||
            (type == "Standard" && dynamic_cast<StandardRegistration*>(reg))) {
            total += reg->calculateFee();
        }
    }
    return total;
}

int RegistrationList::totalRegistrations(const QString& type) const {
    int count = 0;
    for (Registration* reg : m_RegistrationList) {
        if (type == "All" || (type == "StudentRegistration" && dynamic_cast<StudentRegistration*>(reg)) ||
            (type == "GuestRegistration" && dynamic_cast<GuestRegistration*>(reg)) ||
            (type == "Standard" && dynamic_cast<StandardRegistration*>(reg))) {
            ++count;
        }
    }
    return count;
}

QList<Registration*> RegistrationList::getRegistrations() const {
    return m_RegistrationList;
}

QList<Registration*> RegistrationList::getRegistrationsOfType(const QString& type) const {
    QList<Registration*> filteredList;
    for (Registration* reg : m_RegistrationList) {
        if (type == "All" || (type == "StudentRegistration" && dynamic_cast<StudentRegistration*>(reg)) ||
            (type == "GuestRegistration" && dynamic_cast<GuestRegistration*>(reg)) ||
            (type == "Standard" && dynamic_cast<StandardRegistration*>(reg))) {
            filteredList.append(reg);
        }
    }
    return filteredList;
}
