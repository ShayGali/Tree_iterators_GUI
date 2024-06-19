QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = main
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

HEADERS += node.hpp tree.hpp CustomEllipseItem.hpp complex.hpp
SOURCES += main.cpp CustomEllipseItem.cpp complex.cpp

# Define a custom target to run the program with `make run`
run.target = run
run.commands = ./main
run.depends = first # Depend on the first build target, ensuring the program is built before running

# Define a custom target to run the program with `make tree`
tree.target = tree
tree.commands = ./main
tree.depends = first # Depend on the first build target, ensuring the program is built before running


QMAKE_EXTRA_TARGETS += run tree

# Add the tree executable to the clean files
QMAKE_CLEAN += main .qmake.stash

# Add the -std=c++2a flag to the C++ compiler
QMAKE_CXXFLAGS += -std=c++2a -g