QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

HEADERS += ../node.hpp ../tree.hpp ../CustomEllipseItem.hpp ../complex.hpp
SOURCES += tests.cpp ../CustomEllipseItem.cpp ../complex.cpp

# Add the -std=c++2a flag to the C++ compiler
QMAKE_CXXFLAGS += -std=c++2a -g

QMAKE_CLEAN += test

# Define a custom target to run the program with `make run`
run.target = run
run.commands = ./test
run.depends = first # Depend on the first build target, ensuring the program is built before running


QMAKE_EXTRA_TARGETS += run