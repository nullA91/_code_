TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.c \
    ../Headers/Functions/boiler_f.c \
    ../Executable/boiler_f.c

HEADERS += \
    ../Headers/Structures/boiler.h \
    ../Headers/Functions/boiler_f.h
