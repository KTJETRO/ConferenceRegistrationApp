#ConferenceRegistrationApp

Description

The ConferenceRegistrationApp is a GUI application developed for the COS3711 Advanced Programming course. This application allows users to register attendees for a conference, manage registration details, and calculate registration fees based on the type of attendee.

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

