TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    ../../Executable/student_e.cpp \
    ../../Executable/point_e.cpp

HEADERS += \
    ../../Headers/libraries.h \
    ../../Headers/student.h \
    ../../Headers/point.h
