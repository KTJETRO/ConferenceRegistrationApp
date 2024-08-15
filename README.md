
#ConferenceRegistrationApp

Description
The ConferenceRegistrationApp is a GUI application developed for the COS3711 Advanced Programming course (Assignment 2, UNISA 2024). This application allows users to register attendees for a conference, manage registration details, and calculate registration fees based on the type of attendee.

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

Open the Project in Qt Creator:

Launch Qt Creator.
Go to File > Open File or Project....
Navigate to your cloned project directory and select the CMakeLists.txt file.
Click Open.
Configure the Project:

Qt Creator will prompt you to configure the project.
Select the appropriate Qt version and build kit if prompted.
Build the Project:

Click the Build button (usually a hammer icon) in the Qt Creator toolbar.
Qt Creator will handle running CMake and compiling the project.
Run the Application:

Click the Run button (usually a green arrow) in the Qt Creator toolbar.
The application should start, and you can interact with it through the GUI.
Usage
Add Registrations: Enter attendee details and select the registration type to add a new registration.

View Registrations: The main interface displays all current registrations and their associated fees.

Filter Registrations: Use the filtering option to view registrations by type.

Save/Load: Save the registration list to an XML file or load an existing XML file into the application.

Save Registration List: Use the option in the GUI to save the registration list in XML format. 

License
This project is licensed under the MIT License.