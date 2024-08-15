<<<<<<< HEAD
#ConferenceRegistrationApp

Description
The ConferenceRegistrationApp is a GUI application developed for the COS3711 Advanced Programming course (Assignment 2, Question 1, UNISA 2024). This application allows users to register attendees for a conference, manage registration details, and calculate registration fees based on the type of attendee.

Features
Register Attendees: Add new attendees with their details and select their registration type.

Display Registrations: View a list of current registrations, including attendee names, affiliations, emails, and fees.

Fee Calculation: Automatically calculate and display registration fees based on the registration type (Standard, Student, Guest).

Filter Registrations: Filter the list of registrations by type.

Save and Load Registrations: Save the list of registrations to an XML file and load it back into the application as needed.

Save Registration List: Save the registration list in an XML format using the RegistrationListWriter class. The user can choose the file location using a standard file dialog.

Setup
Clone the Repository:

git clone https://github.com/KTJETRO/ConferenceRegistrationApp.git
cd ConferenceRegistrationApp

Build the Project:

mkdir build
cd build
cmake ..
make

Run the Application:

./ConferenceRegistrationApp

Dependencies:

Qt6: Ensure you have Qt6 installed on your system.
Usage
Add Registrations: Enter attendee details and select the registration type to add a new registration.

View Registrations: The main interface displays all current registrations and their associated fees.

Filter Registrations: Use the filtering option to view registrations by type.

Save/Load: Save the registration list to an XML file or load an existing XML file into the application.

Save Registration List: Use the new option in the GUI to save the registration list in an XML format. The XML will be structured as follows:


<registrationlist>
    <registration type="Registration">
        <attendee>
            <name>..</name>
            <affiliation>..</affiliation>
            <email>..</email>
        </attendee>
        <bookingdate>..</bookingdate>
        <registrationfee>..</registrationfee>
    </registration>
    ...
</registrationlist>


License
This project is licensed under the MIT License.
=======
#ConferenceRegistrationApp

Description

The ConferenceRegistrationApp is a GUI application developed for the COS3711 Advanced Programming course (Assignment 2 , Question 1, UNISA 2024). This application allows users to register attendees for a conference, manage registration details, and calculate registration fees based on the type of attendee.

Features
// Register Attendees: Add new attendees with their details and select their registration type.

// Display Registrations: View a list of current registrations, including attendee names, affiliations, emails, and fees.

// Fee Calculation: Automatically calculate and display registration fees based on the registration type (Standard, Student, Guest).

// Filter Registrations: Filter the list of registrations by type.

// Save and Load Registrations: Save the list of registrations to an XML file and load it back into the application as needed.

Setup
Clone the Repository:

bash
Copy code
git clone https://github.com/KTJETRO/ConferenceRegistrationApp.git
cd ConferenceRegistrationApp
Build the Project:

bash
Copy code
mkdir build
cd build
cmake ..
make
Run the Application:

bash
Copy code
./ConferenceRegistrationApp
Dependencies
# Qt6: Ensure you have Qt6 installed on your system.

Usage
// Add Registrations: Enter attendee details and select the registration type to add a new registration.

// View Registrations: The main interface displays all current registrations and their associated fees.

// Filter Registrations: Use the filtering option to view registrations by type.

// Save/Load: Save the registration list to an XML file or load an existing XML file into the application.

License
This project is licensed under the MIT License.

>>>>>>> f7b04c2de51a8d7011dec4055cad8313a96fdf9d
