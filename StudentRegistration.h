#ifndef STUDENTREGISTRATION_H
#define STUDENTREGISTRATION_H

#include "Registration.h"

class StudentRegistration : public Registration {
public:
    StudentRegistration(const Person& attendee, const QString& courseName);

    double calculateFee() const override;
    QString toString() const override;

    QString getCourseName() const;  // Getter for course name

private:
    QString m_CourseName;
};

#endif // STUDENTREGISTRATION_H
