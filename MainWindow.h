#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QLabel> // Include QLabel for GUI labels
#include "RegistrationList.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void addRegistration();
    void updateTotalAttendees();
    void updateTotalFees();
    void filterRegistrations();

private:
    void setupUi();

    QTableWidget *tableWidget;
    QLineEdit *nameLineEdit;
    QLineEdit *affiliationLineEdit;
    QLineEdit *emailLineEdit;
    QComboBox *registrationTypeComboBox;
    QPushButton *addButton;
    QLabel *totalAttendeesLabel; // Label for displaying total attendees
    QLabel *totalFeesLabel; // Label for displaying total fees
    QComboBox *filterComboBox; // ComboBox for filtering registrations

    RegistrationList registrationList;
};

#endif // MAINWINDOW_H
