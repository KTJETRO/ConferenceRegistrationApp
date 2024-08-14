#ifndef REGISTRATIONLIST_H
#define REGISTRATIONLIST_H

#include <QList>
#include <QString>
#include "Registration.h"
#include "StudentRegistration.h"
#include "GuestRegistration.h"
#include "StandardRegistration.h"

class RegistrationList {
public:
    RegistrationList();

    bool addRegistration(const Registration& r);
    bool isRegistered(const QString& name) const;
    double totalFee(const QString& type) const;
    int totalRegistrations(const QString& type) const;
    QList<Registration*> getRegistrations() const;

    // Methods to retrieve registrations of specific types
    QList<Registration*> getRegistrationsOfType(const QString& type) const;

private:
    QList<Registration*> m_RegistrationList;
    QList<StudentRegistration*> m_StudentRegistrationList;
    QList<GuestRegistration*> m_GuestRegistrationList;
};

#endif // REGISTRATIONLIST_H
