#include "MainWindow.h"
#include <QVBoxLayout>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
{
setupUi();
}

void MainWindow::setupUi()
{
QVBoxLayout *layout = new QVBoxLayout();

tableWidget = new QTableWidget(this);
tableWidget->setColumnCount(4);
QStringList headers = {"Name", "Affiliation", "Email", "Fee"};
tableWidget->setHorizontalHeaderLabels(headers);

nameLineEdit = new QLineEdit(this);
affiliationLineEdit = new QLineEdit(this);
emailLineEdit = new QLineEdit(this);
registrationTypeComboBox = new QComboBox(this);
registrationTypeComboBox->addItems({"Standard", "Student", "Guest"});
addButton = new QPushButton("Add Registration", this);

totalAttendeesLabel = new QLabel("Total Attendees: 0", this);
totalFeesLabel = new QLabel("Total Fees: $0.00", this);
filterComboBox = new QComboBox(this);
filterComboBox->addItems({"All", "Standard", "Student", "Guest"});

saveButton = new QPushButton("Save Registration List", this);
connect(addButton, &QPushButton::clicked, this, &MainWindow::addRegistration);
connect(saveButton, &QPushButton::clicked, this, &MainWindow::saveRegistrationList);
connect(filterComboBox, QOverload<int>::of(&QComboBox::activated), this, &MainWindow::filterRegistrations);

layout->addWidget(tableWidget);
layout->addWidget(new QLabel("Enter Person Name:", this));
layout->addWidget(nameLineEdit);
layout->addWidget(new QLabel("Enter Affiliation:", this));
layout->addWidget(affiliationLineEdit);
layout->addWidget(new QLabel("Enter Email:", this));
layout->addWidget(emailLineEdit);
layout->addWidget(new QLabel("Select Registration Type:", this));
layout->addWidget(registrationTypeComboBox);
layout->addWidget(addButton);
layout->addWidget(totalAttendeesLabel);
layout->addWidget(totalFeesLabel);
layout->addWidget(new QLabel("Filter Registrations:", this));
layout->addWidget(filterComboBox);
layout->addWidget(saveButton);

QWidget *centralWidget = new QWidget(this);
centralWidget->setLayout(layout);

setCentralWidget(centralWidget);
}

void MainWindow::addRegistration()
{
QString name = nameLineEdit->text().trimmed();
QString affiliation = affiliationLineEdit->text().trimmed();
QString email = emailLineEdit->text().trimmed();
QString type = registrationTypeComboBox->currentText();

if (name.isEmpty() || affiliation.isEmpty() || email.isEmpty()) {
QMessageBox::warning(this, "Error", "Please fill in all fields.");
return;
}

int row = tableWidget->rowCount();
tableWidget->insertRow(row);
tableWidget->setItem(row, 0, new QTableWidgetItem(name));
tableWidget->setItem(row, 1, new QTableWidgetItem(affiliation));
tableWidget->setItem(row, 2, new QTableWidgetItem(email));
double fee = (type == "Standard") ? 200.0 :
(type == "Student") ? 100.0 :
(type == "Guest") ? 150.0 : 0.0;
tableWidget->setItem(row, 3, new QTableWidgetItem(QString("$%1").arg(fee)));

totalAttendeesLabel->setText(QString("Total Attendees: %1").arg(tableWidget->rowCount()));
double totalFees = 0.0;
for (int i = 0; i < tableWidget->rowCount(); ++i) {
totalFees += tableWidget->item(i, 3)->text().remove("$").toDouble();
}
totalFeesLabel->setText(QString("Total Fees: $%1").arg(totalFees));

nameLineEdit->clear();
affiliationLineEdit->clear();
emailLineEdit->clear();
}

void MainWindow::saveRegistrationList()
{
QString filePath = QFileDialog::getSaveFileName(this, "Save Registration List", "", "XML Files (*.xml)");

if (filePath.isEmpty())
return;

QFile file(filePath);
if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
QMessageBox::critical(this, "Error", "Could not open file for writing.");
return;
}

QXmlStreamWriter xmlWriter(&file);
xmlWriter.setAutoFormatting(true);
xmlWriter.writeStartDocument();
xmlWriter.writeStartElement("registrationlist");

for (int row = 0; row < tableWidget->rowCount(); ++row) {
xmlWriter.writeStartElement("registration");
xmlWriter.writeAttribute("type", "Standard");

xmlWriter.writeStartElement("attendee");
xmlWriter.writeTextElement("name", tableWidget->item(row, 0)->text());
xmlWriter.writeTextElement("affiliation", tableWidget->item(row, 1)->text());
xmlWriter.writeTextElement("email", tableWidget->item(row, 2)->text());
xmlWriter.writeEndElement(); // attendee

xmlWriter.writeTextElement("bookingdate", QDate::currentDate().toString());
xmlWriter.writeTextElement("registrationfee", tableWidget->item(row, 3)->text().remove("$"));

xmlWriter.writeEndElement(); // registration
}

xmlWriter.writeEndElement(); // registrationlist
xmlWriter.writeEndDocument();

file.close();
}

void MainWindow::filterRegistrations(int index)
{
QString filter = filterComboBox->itemText(index);
for (int i = 0; i < tableWidget->rowCount(); ++i) {
bool match = (filter == "All") ||
(filter == "Standard" && tableWidget->item(i, 3)->text().contains("Standard")) ||
(filter == "Student" && tableWidget->item(i, 3)->text().contains("Student")) ||
(filter == "Guest" && tableWidget->item(i, 3)->text().contains("Guest"));
tableWidget->setRowHidden(i, !match);
}
}