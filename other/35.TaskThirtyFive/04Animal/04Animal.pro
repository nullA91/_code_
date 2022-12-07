TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lWinmm

SOURCES += \
        main.c \
    ../Executable/animal_f.c

HEADERS += \
    ../Headers/Structures/animal.h \
    ../Headers/Functions/animal_f.h
