TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.c \
    ../../Executables/file.c \
    ../../Executables/functions.c

HEADERS += \
    ../../Headers/file.h \
    ../../Headers/functions.h
