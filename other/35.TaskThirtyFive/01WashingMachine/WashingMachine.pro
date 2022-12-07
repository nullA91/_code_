TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.c \
    ../Executable/washing_machine.c

HEADERS += \
    ../Headers/Structures/washingmachine.h \
    ../Headers/Functions/washing_machine.h \
    ../Headers/libraries.h
