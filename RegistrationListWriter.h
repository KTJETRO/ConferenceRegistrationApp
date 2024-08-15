#ifndef REGISTRATIONLISTWRITER_H
#define REGISTRATIONLISTWRITER_H

#include <QFile>
#include <QXmlStreamWriter>
#include "RegistrationList.h"

class RegistrationListWriter
{
public:
RegistrationListWriter(const RegistrationList& list);

bool writeToXml(const QString& filePath);

private:
const RegistrationList& m_List;
};

#endif // REGISTRATIONLISTWRITER_H