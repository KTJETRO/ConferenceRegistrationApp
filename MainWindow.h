#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QTableWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QXmlStreamWriter>

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
explicit MainWindow(QWidget *parent = nullptr);

private slots:
void addRegistration();
void saveRegistrationList();
void filterRegistrations(int index);

private:
void setupUi();

QTableWidget *tableWidget;
QLineEdit *nameLineEdit;
QLineEdit *affiliationLineEdit;
QLineEdit *emailLineEdit;
QComboBox *registrationTypeComboBox;
QPushButton *addButton;
QLabel *totalAttendeesLabel;
QLabel *totalFeesLabel;
QComboBox *filterComboBox;
QPushButton *saveButton;
};

#endif // MAINWINDOW_H
