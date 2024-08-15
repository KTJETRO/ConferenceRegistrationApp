#include "StudentRegistration.h"

StudentRegistration::StudentRegistration(const Person& attendee, const QString& courseName)
: Registration(attendee), m_CourseName(courseName) {}

double StudentRegistration::calculateFee() const {
return STANDARD_FEE * 0.5;
}

QString StudentRegistration::toString() const {
return QString("Student: %1, Course: %2").arg(m_Attendee.toString(), m_CourseName);
}

QString StudentRegistration::getCourseName() const {
return m_CourseName;
}