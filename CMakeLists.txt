cmake_minimum_required(VERSION 3.5)

project(ConferenceRegistrationApp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(ConferenceRegistrationApp
    main.cpp
    MainWindow.cpp
    MainWindow.h
    Person.cpp
    Person.h
    Registration.cpp
    Registration.h
    StudentRegistration.cpp
    StudentRegistration.h
    GuestRegistration.cpp
    GuestRegistration.h
    StandardRegistration.cpp
    StandardRegistration.h
    RegistrationList.cpp
    RegistrationList.h
)

target_link_libraries(ConferenceRegistrationApp Qt6::Widgets)
