#include "MainWindow.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include "StudentRegistration.h"
#include "GuestRegistration.h"
#include "StandardRegistration.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setupUi();
}

void MainWindow::setupUi() {
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

    connect(addButton, &QPushButton::clicked, this, &MainWindow::addRegistration);
    connect(filterComboBox, QOverload<int>::of(&QComboBox::activated), this, &MainWindow::filterRegistrations);

    QVBoxLayout *layout = new QVBoxLayout;
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

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

void MainWindow::addRegistration() {
    QString name = nameLineEdit->text().trimmed();
    QString affiliation = affiliationLineEdit->text().trimmed();
    QString email = emailLineEdit->text().trimmed();
    QString registrationType = registrationTypeComboBox->currentText();

    if (name.isEmpty() || affiliation.isEmpty() || email.isEmpty()) {
        QMessageBox::warning(this, "Empty Fields", "Please fill in all fields.");
        return;
    }

    Person person(name, affiliation, email);
    Registration* registration = nullptr;

    if (registrationType == "Student") {
        registration = new StudentRegistration(person, "Qualification");
    } else if (registrationType == "Guest") {
        registration = new GuestRegistration(person, "Category");
    } else {
        registration = new StandardRegistration(person);
    }

    if (registrationList.addRegistration(*registration)) {
        int row = tableWidget->rowCount();
        tableWidget->insertRow(row);
        tableWidget->setItem(row, 0, new QTableWidgetItem(person.getName()));
        tableWidget->setItem(row, 1, new QTableWidgetItem(person.getAffiliation()));
        tableWidget->setItem(row, 2, new QTableWidgetItem(person.getEmail()));
        tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(registration->calculateFee())));

        nameLineEdit->clear();
        affiliationLineEdit->clear();
        emailLineEdit->clear();

        QMessageBox::information(this, "Registration Successful", "Registration added successfully.");
    } else {
        QMessageBox::warning(this, "Registration Failed", "Registration failed. Attendee already registered.");
    }

    delete registration;

    // Update total attendees and total fees labels
    updateTotalAttendees();
    updateTotalFees();
}

void MainWindow::updateTotalAttendees() {
    int totalAttendees = registrationList.totalRegistrations("All");
    totalAttendeesLabel->setText("Total Attendees: " + QString::number(totalAttendees));
}

void MainWindow::updateTotalFees() {
    double totalFees = registrationList.totalFee("All");
    totalFeesLabel->setText("Total Fees: $" + QString::number(totalFees, 'f', 2));
}

void MainWindow::filterRegistrations() {
    QString filterType = filterComboBox->currentText();
    QList<Registration*> registrations;

    if (filterType == "All") {
        registrations = registrationList.getRegistrations();
    } else if (filterType == "Standard") {
        registrations = registrationList.getRegistrationsOfType("Standard");
    } else if (filterType == "Student") {
        registrations = registrationList.getRegistrationsOfType("StudentRegistration");
    } else if (filterType == "Guest") {
        registrations = registrationList.getRegistrationsOfType("GuestRegistration");
    }

    // Update table widget with filtered registrations
    tableWidget->clearContents();
    tableWidget->setRowCount(0);

    foreach (Registration* reg, registrations) {
        int row = tableWidget->rowCount();
        tableWidget->insertRow(row);
        tableWidget->setItem(row, 0, new QTableWidgetItem(reg->getAttendee().getName()));
        tableWidget->setItem(row, 1, new QTableWidgetItem(reg->getAttendee().getAffiliation()));
        tableWidget->setItem(row, 2, new QTableWidgetItem(reg->getAttendee().getEmail()));
        tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(reg->calculateFee())));
    }
}

