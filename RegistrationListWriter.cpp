#include "RegistrationListWriter.h"

RegistrationListWriter::RegistrationListWriter(const RegistrationList& list)
: m_List(list)
{}

bool RegistrationListWriter::writeToXml(const QString& filePath)
{
QFile file(filePath);
if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
return false;
}

QXmlStreamWriter xmlWriter(&file);
xmlWriter.setAutoFormatting(true);
xmlWriter.writeStartDocument();
xmlWriter.writeStartElement("registrationlist");

QList<Registration*> registrations = m_List.getRegistrations();
for (Registration* reg : registrations) {
xmlWriter.writeStartElement("registration");
xmlWriter.writeAttribute("type", reg->toString());

xmlWriter.writeStartElement("attendee");

xmlWriter.writeTextElement("name", reg->getAttendee().getName());
xmlWriter.writeTextElement("affiliation", reg->getAttendee().getAffiliation());
xmlWriter.writeTextElement("email", reg->getAttendee().getEmail());

xmlWriter.writeEndElement(); // attendee

xmlWriter.writeTextElement("bookingdate", reg->getBookingDate().toString());
xmlWriter.writeTextElement("registrationfee", QString::number(reg->calculateFee()));

xmlWriter.writeEndElement(); // registration
}

xmlWriter.writeEndElement(); // registrationlist
xmlWriter.writeEndDocument();

file.close();
return true;
}