TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++17

SOURCES += main.cpp \
    rectangle.cpp

HEADERS += \
    rectangle.h
