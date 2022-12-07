TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.c \
    ../Executable/smoothing_iron.c

HEADERS += \
    ../Headers/Structures/smoothingiron.h \
    ../Headers/Functions/smoothing_iron.h
