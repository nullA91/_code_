TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.c \
    ../../Executable/rectangle_f.c \
    ../../Executable/functions.c \
    ../../Executable/point_f.c \
    ../../Executable/fraction_f.c

HEADERS += \
    ../../Headers/rectangle.h \
    ../../Headers/functions.h \
    ../../Headers/point.h \
    ../../Headers/fraction.h
