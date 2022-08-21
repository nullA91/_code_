TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.c \
    ../Executable/number_f.c

HEADERS += \
    ../Headers/Unions/number_u.h \
    ../Headers/Functions/number_f.h \
    ../Headers/libraries.h \
    ../Headers/Structures/bitrepresentation.h
