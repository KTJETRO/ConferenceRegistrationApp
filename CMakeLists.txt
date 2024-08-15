cmake_minimum_required(VERSION 3.19)
project(ConferenceRegistrationApp)

# Find the Qt6 package components
find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

# Set the source files for your project
set(SOURCES
    main.cpp
    MainWindow.cpp
    Registration.cpp
    StandardRegistration.cpp
    StudentRegistration.cpp
    GuestRegistration.cpp
    RegistrationList.cpp
    RegistrationListWriter.cpp
    Person.cpp
)

# Set the header files for your project
set(HEADERS
    MainWindow.h
    Registration.h
    StandardRegistration.h
    StudentRegistration.h
    GuestRegistration.h
    RegistrationList.h
    RegistrationListWriter.h
    Person.h
)

# Generate the executable
add_executable(ConferenceRegistrationApp
    ${SOURCES}
    ${HEADERS}
)

# Link Qt modules
target_link_libraries(ConferenceRegistrationApp PRIVATE Qt6::Core Qt6::Widgets)

# Enable AUTOMOC for Qt-based projects
set_target_properties(ConferenceRegistrationApp PROPERTIES
    AUTOMOC ON
)
